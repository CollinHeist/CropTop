# CropTop
## Development
CropTop is a small-form data acquisition platform initially developed by Kennedy Caisley and Ryan Donahue, two undergraduate electrical engineering students at the University of Idaho. It is designed to support the cereal grain crop strength research being conducted by [Dr. Daniel Roberston](https://www.uidaho.edu/engr/departments/me/our-people/faculty/daniel-robertson) in the UI Department of Mechanical Engineering.

The current iteration of the project is being developed by [Collin Heist](https://github.com/CollinHeist), an undergraduate Electrical Engineering student at University of Idaho.

## What can CropTop do? 
Croptop is based around a 32 bit PIC32MX795F512L microcontroller and includes the following peripherals onboard:
* 12 bit temperature/humidity sensor
* 3-axis accelerometer
* ΔΣ 24 bit 1kSPS ADC
* GNSS receiver
* USB 2.0 OTG interface
* 5A DC motor controller
* Resistive touch controller
* Rotary encoder interface
* Linear encoder interface
* 1GB NAND flash
* User programmable push buttons
* User programmable LEDs
* 14 additional GPIO

## Code Development Standards

### <a name='checklist'></a>Development Checklists

#### <a name='checklist-header-files'></a>Header File

- [x] Has a valid file heading ([template](#templates-file-heading)).
- [x] Has multiple-inclusion protection ([template](#templates-inclusion-protection)).
- [x] Has verbose `#define` statements.
- [x] Has function prototypes.
- [x] Has limited (to no) macro functions - replace these with `inline` functions, instead.

#### <a name='checklist-source-files'></a>Source File

- [x] Has an associated header file.
- [x] Has a valid file heading ([template](#templates-file-heading)).
- [x] Has required source file sections ([template](#templates-source-file-sections)).
- [x] All functions have an associated comment block ([template](#templates-source-file-sections)).
- [x] All _small_ functions are `inline`.
- [x] All function names and variables are verbose (i.e. `initialize_screen()` as opposed to `init_scr()`).
- [x] All function parameters that do not change during operation are `const`.
- [x] All functions that are not user-facing (from a library perspective) are private (`static`).

#### <a name='checklist-GUI'></a>Nextion GUI

- [x] The number of unique pages are kept to a minimum because pages have quite a lot of overhead (in memory).
- [x] Objects with strings - either for text display or variables - have the minimum length required.
- [x] The number of PIC-screen communications are kept to a minimum this is because the UART communication is _somewhat_ unreliable.

-----

### <a name='templates'></a>Templates
#### <a name='templates-file-heading'></a>File Heading (source and header)

```C
/**
 *  File
 *      filename.h
 *  Summary
 *      A brief summary of the header file's purpose.
 *  Author(s)
 *      Author 1, Author 2.
 *  Note
 *      Optional additional information regarding the file.
 */
```

#### <a name='templates-inclusion-protection'></a>Multiple Inclusion Protection

```C
#ifndef __FILENAME_H__
    #define __FILENAME_H__
    // Code
#endif
```

#### <a name='templates-source-file-sections'></a>Source File Sections

```C
/* ----------------------------------- File Inclusion ----------------------------------- */
/* -------------------------- Global Variables and Structures --------------------------- */
/* ---------------------------------- Public Functions ---------------------------------- */
/* --------------------------------- Private Functions ---------------------------------- */
/* ----------------------------- Interrupt Service Routines ----------------------------- */
```

#### <a name='templates-source-file-sections'></a>Function Comment Blocks

```C
/*
 *  Summary
 *      Short description of the function.
 *  Parameters
 *      param1[in]: Description of the first parameter (in if not changed).
 *      param2[out]: Description of the second parameter (out if changed).
 *  Returns
 *      Describe the meaning of the return value (if there is one).
 *  Note
 *      Optional addition of the function.
 */
```


