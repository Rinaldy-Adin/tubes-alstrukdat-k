#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include <stdio.h>

#include "../../ADT/wordmachine/wordmachine.h"
#include "boolean.h"

// Print "Enter command" then return command from user
Word readCommand();

// Wait for user to enter "START" command
void waitForStart();

// Run command line until user enters "EXIT" command
void commandLineCycle();

#endif