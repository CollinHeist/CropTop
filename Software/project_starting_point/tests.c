/**
 *	File
 *		tests.c
 *	Summary
 *		Test source file. Provides a useful Test structure for containing all the data 
 *		pertinent to any given test. This structure has a union for storing data of many
 *		different types without wasting memory. File also contains functions for writing
 *		tests to memory (TBD), storing tests in PIC memory, deleting old tests, etc.
 *	Author(s)
 *		Collin Heist
 *	Note
 *		For a detailed explanation of all fields in the Test structure, see the global
 *		variables and structure section below. Each item is commented.
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include <string.h>

#include "hardware.h"
#include "tests.h"
#include "RTC.h"

/* -------------------------- Global Variables and Structures --------------------------- */

// Structure of a single test - contains all information for each test
typedef struct test {
	unsigned int plot_number;						// Plot number
	unsigned int lca_weight_grams;					// LCA Weight (in grams)
	unsigned int break_height;						// Break height
	unsigned int height;							// Height of the test
	char height_units[MAX_HEIGHT_UNITS_LENGTH];		// Units of the specified height (CM or IN)
	char operator[MAX_OPERATOR_LENGTH];				// Operator of the test
	char folder[MAX_FOLDER_LENGTH];					// Folder to store results in
	char pre_test_notes[MAX_TEST_NOTE_LENGTH];		// Pre-test notes
	char post_test_notes[MAX_TEST_NOTE_LENGTH];		// Post-test notes
	rtccTime time;									// Time the test finished being taken
	rtccDate date;									// Date the test finished being taken
	union {											// Use of union permits accessing many ways without wasting memory
		char data_char[MAX_DATA_BYTES];				// Store the data as: char, short, unsigned short, int, unsigned int, or float
		short data_short[MAX_NUMBER_SHORT];			// Data was generalized to permit many different sensors
		unsigned short data_ushort[MAX_NUMBER_SHORT];
		int data_int[MAX_NUMBER_INT];
		unsigned int data_uint[MAX_NUMBER_INT];
		float data_float[MAX_NUMBER_FLOAT];
	};
} Test;

Test all_tests[MAX_NUMBER_TESTS];	// Array of all tests stored in the PIC memory

static unsigned int test_index;		// Current test number (0 to MAX_NUMBER_TESTS) being run
static unsigned int data_index;		// Current index of the data array being populated

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Function to initialize any test-related objects. Currently this just clears the global
 *		all_tests array, but should later initialize any USB-writing interfaces.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if initialization was successful.
 *	Note
 *		The clearing of the all_tests array should not be necessary (global variables) are
 *		default initialized to 0, but it's best-practice - especially with structures.
 */
unsigned int initialize_test_operations(void) {
	if (MAX_NUMBER_TESTS < 0)
		return ERROR;		// Error if an invalid number of tests has been entered (compiler should error anyway...)

	delete_all_tests();		// Clear contents of all_tests array

	return NO_ERROR;
}

/*
 *	Summary
 *		Private function to parse the contents of a test string (after removing SAVE_TEST) into
 *		a Test structure (defined in tests.h) for easier data-passage.
 *	Parameters
 *		buffer[in]: Pointer to the first character of the null-terminated string being parsed into
 *			separate variables. Should be of the form: "save_test plotNumber heightNumberUnit
 *			breakHeight operator folder lcaWeight preTestNotes postTestNotes" (no newline).
 *	Returns
 *		Test structure containing the contents filled from the buffer. Not all fields are populated.
 */
Test parse_test_information(const char* buffer) {
	// All intermediate parsing variables
	Test current_test = {0};	// All fields initialized to 0
	unsigned int plot_number = 0, height = 0, break_height = 0, lca_weight = 0;
	char height_units[MAX_HEIGHT_UNITS_LENGTH] = {'\0'}, operator[MAX_OPERATOR_LENGTH] = {'\0'}, folder[MAX_FOLDER_LENGTH] = {'\0'};
	char pre_test_notes[MAX_TEST_NOTE_LENGTH] = {'\0'}, post_test_notes[MAX_TEST_NOTE_LENGTH] = {'\0'};
	// Scan string into intermediate variables
	sscanf(buffer, "%u %u%s %u %s %s %u %s %s", &plot_number, &height, height_units, &break_height, operator, folder, &lca_weight, pre_test_notes, post_test_notes);
	// Populate the struct
	current_test.plot_number = plot_number;
	current_test.lca_weight_grams = lca_weight;
	current_test.break_height = break_height;
	current_test.height = height;
	strncpy(current_test.height_units, height_units, MAX_HEIGHT_UNITS_LENGTH);
	strncpy(current_test.operator, operator, MAX_OPERATOR_LENGTH);
	strncpy(current_test.folder, folder, MAX_FOLDER_LENGTH);
	strncpy(current_test.pre_test_notes, pre_test_notes, MAX_TEST_NOTE_LENGTH);
	strncpy(current_test.post_test_notes, post_test_notes, MAX_TEST_NOTE_LENGTH);

	return current_test;
}

/**
 *	Summary
 *		Function to save the current test with the provided auxiliary test information to the
 *		global all_tests array (for later writing to memory, etc.).
 *	Parameters
 *		current_test[in]: Test structure containing the populated information of a given test.
 *			The only information not needed to be populated in this struct is time, date, and
 *			the data_* field.
 *	Returns
 *		None.
 *	Note
 *		If there is insufficient memory available in all_tests, the test information is ignored
 *		and the function immediately returns. If this provided information fills up the last
 *		available spot in the all_tests array, the alert_user_memory_full() is called.
 */
void save_test(const Test current_test) {
	if (test_index > MAX_NUMBER_TESTS - 1)
		return;	// Do not break memory bounds, user should be warned results are ignored
	
	// Get the current date and time
	rtccTime time; rtccDate date;
	get_datetime_rtcc(&time, &date);
	
	// Update the fields of the current test structure in the array
	all_tests[test_index].plot_number = current_test.plot_number;
	all_tests[test_index].lca_weight_grams = current_test.lca_weight;
	all_tests[test_index].break_height = current_test.break_height;
	all_tests[test_index].height = current_test.height;
	strncpy(all_tests[test_index].height_units, current_test.height_units, MAX_HEIGHT_UNITS_LENGTH);
	strncpy(all_tests[test_index].operator, current_test.operator, MAX_OPERATOR_LENGTH);
	strncpy(all_tests[test_index].folder, current_test.folder, MAX_FOLDER_LENGTH);
	strncpy(all_tests[test_index].pre_test_notes, current_test.pre_test_notes, MAX_TEST_NOTE_LENGTH);
	strncpy(all_tests[test_index].post_test_notes, current_test.post_test_notes, MAX_TEST_NOTE_LENGTH);
	all_tests[test_index].time = time;
	all_tests[test_index].date = date;
	
	// Increment the current test number, and make sure we haven't gone beyond MAX_NUMBER_TESTS
	test_index++;
	if (check_if_memory_full() == IS_FULL)
		alert_user_memory_full();	// Send a message to the user saying to export the current tests to the USB
}

/**
 *	Summary
 *		Function to delete the current test - clears (sets to 0) the contents of the data union.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
inline void delete_current_test_data(void) {
	clear_buffer(all_tests[test_index].data_char, MAX_DATA_BYTES);
}

/**
 *	Summary
 *		Function to check if the all_tests array is full. This is primarily a helper funtion
 *		to avoid having to manually check the status of test_index versus MAX_NUMBER_TESTS.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned integer that is either IS_FULL or IS_NOT_FULL to denote the filled status
 *		of the all_tests buffer.
 */
inline unsigned int check_if_memory_full(void) {
	return (test_index > (MAX_NUMBER_TESTS - 1) ? IS_FULL : IS_NOT_FULL);
}

/* --------------------------------- Private Functions ---------------------------------- */

/**
 *	Summary
 *		Private function to completely clear the contents of the all_tests array - effectively
 *		deleting all stored test data from the PIC.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
static inline void delete_all_tests(void) {
	unsigned int i = 0;		// Test index variable
	for (; i < MAX_NUMBER_TESTS; i++) {
		delete_test(&all_tests[i]);
	}
	
	test_index = 0;
}

/**
 *	Summary
 *		Private function to clear the contents of a passed Test structure.
 *	Parameters
 *		current_test[out]: Pointer to the Test structure to be cleared.
 *	Returns
 *		None.
 */
static inline void delete_test(Test* current_test) {
	current_test -> plot_number = 0;
	current_test -> lca_weight_grams = 0;
	current_test -> break_height = 0;
	current_test -> height = 0;
	clear_buffer(current_test -> height_units, MAX_HEIGHT_UNITS_LENGTH);
	clear_buffer(current_test -> operator, MAX_OPERATOR_LENGTH);
	clear_buffer(current_test -> folder, MAX_FOLDER_LENGTH);
	clear_buffer(current_test -> pre_test_notes, MAX_TEST_NOTE_LENGTH);
	clear_buffer(current_test -> post_test_notes, MAX_TEST_NOTE_LENGTH);
	current_test -> time.l = 0;
	current_test -> date.l = 0;
	clear_buffer(current_test -> data_char, MAX_DATA_BYTES);
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */