#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include <stdio.h>

#include "../../ADT/matrix/matrix.h"
#include "../../ADT/point/point.h"
#include "../../ADT/simulator/simulator.h"
#include "../../ADT/strlib/strlib.h"
#include "../peta/cmdPeta.h"
#include "boolean.h"
#include "cursed.h"

void displayCurrentState(Matrix peta, Simulator sim);

// Wait for user to enter "START" command
void waitForStart(Matrix peta);

void initializeSimulator(Simulator *sim, Matrix peta);

// Run command based on input
void runCommand(Matrix *peta, Simulator *sim, String command);

// Run command line until user enters "EXIT" command
void commandLineCycle(Matrix peta);

#endif