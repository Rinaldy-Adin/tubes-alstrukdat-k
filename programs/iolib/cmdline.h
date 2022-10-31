#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include <stdio.h>

#include "../../ADT/strlib.h"
#include "../../ADT/matrix.h"
#include "../../ADT/point.h"
#include "../peta/cmdPeta.h"
#include "../../ADT/simulator.h"
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