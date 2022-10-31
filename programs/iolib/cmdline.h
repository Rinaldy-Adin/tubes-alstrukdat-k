#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include <stdio.h>

#include "../../ADT/strlib.h"
#include "../../ADT/matrix.h"
#include "../../ADT/point.h"
#include "../peta/cmdPeta.h"
#include "boolean.h"
#include "cursed.h"

// Wait for user to enter "START" command
void waitForStart(Matrix peta);

// Run command line until user enters "EXIT" command
void commandLineCycle(Matrix peta);

#endif