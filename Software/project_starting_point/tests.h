/**
 *	File
 *		tests.h
 *	Summary
 *		Test header file. Provides macros for full vs. not full, definition for how many tests
 *		to store in memory during operation, and how big to make each test's data field.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __TESTS_H__
	#define __TESTS_H__

	// Convenient Macros
	#define IS_FULL					(1)		// Macro denoting that the all_tests array is full
	#define IS_NOT_FULL				(0)		// Macro denoting that the all_tests arra is not full

	// Operational Configurations
	#define MAX_NUMBER_TESTS		(8)		// How many tests to store on the PIC at any given time
	#define MAX_DATA_BYTES			(256)	// How many bytes to allocate for data for any given test
		#define MAX_NUMBER_SHORT	(MAX_DATA_BYTES / NUM_BYTES_SHORT)
		#define MAX_NUMBER_INT		(MAX_DATA_BYTES / NUM_BYTES_INT)
		#define MAX_NUMBER_FLOAT	(MAX_DATA_BYTES / NUM_BYTES_FLOAT)
	#define MAX_OPERATOR_LENGTH		(17)	// Maximum length of an operator name (+1 for '\0')
	#define MAX_FOLDER_LENGTH		(21)	// Maximum length of a folder name (+1 for '\0')
	#define MAX_TEST_NOTE_LENGTH	(33)	// Maximum length of an test note (+1 for '\0')
	#define MAX_HEIGHT_UNITS_LENGTH	(3)		// Maximum length of the height units (+1 for '\0')

	// Function Prototypes
	unsigned int initialize_test_operations(void);
	Test parse_test_information(const char* buffer);
	void save_test(const Test current_test);
	inline unsigned int check_if_memory_full(void);
	inline void delete_current_test_data(void);
	static void delete_all_tests(void);
	static inline void delete_test(Test* current_test);
#endif