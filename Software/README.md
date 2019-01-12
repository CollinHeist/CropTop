## Code Guidelines

Lets try to keep our code consistent throughotu the project

### File Headers

All files will follow the following form:

'''
/* **************************************************************************
 * File name:   SomeLib.c
 * Association: University of Idaho
 * Author:      
 * Dates:       Created x/x/xxxx
 * 
 * Summary:     Description of the file's purpose and functionality
 * 
 * Notes:       Optional, largely used during development to keep track of 
				work in progress.
 * **************************************************************************/
'''

### Function Headers

TBD

 
### Comments

Strive to limit comments, if you can make a better funciton name or variable, do it.

    //lower case touching forward slash
    
	/*
	for two lines or more open a multi line comment
	opt for inline comments, avoid comments to the side of code
	*/

### Function Naming Conventions

A library, such as MotorLib.c will have all functions labeled with "MotorLib_" before
a descriptive function name.