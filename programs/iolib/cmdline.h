#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include <stdio.h>

#include "../../ADT/makanan/makanan.h"
#include "../../ADT/matrix/matrix.h"
#include "../../ADT/point/point.h"
#include "../../ADT/prioqueue/prioqueue.h"
#include "../../ADT/simulator/simulator.h"
#include "../../ADT/stack/stack.h"
#include "../../ADT/strlib/strlib.h"
#include "../makanan/inventory.h"
#include "../makanan/order.h"
#include "../peta/cmdPeta.h"
#include "boolean.h"
#include "cursed.h"

void displayCurrentState(Matrix peta, Simulator sim, ListStatik listCatalog,
                         Stack undoStack, Stack redoStack, boolean isRedo);

// Wait for user to enter "START" command
void waitForStart(Matrix peta);

int buyCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog);

int cookCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog,
                ListStatik listResep, String cookMethod);

void removeActions(Simulator *sim);

void undoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                 Stack *undoStack, Stack *redoStack);

void redoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                 Stack *undoStack, Stack *redoStack);

void decrementSim(Simulator *sim, Simulator *nextSim, Stack *undoStack,
                  Stack *redoStack, int nMenit);

// Run command based on input
void runCommand(Matrix *peta, Simulator *sim, Simulator *nextSim,
                Stack *undoStack, Stack *redoStack, boolean *isRedo,
                ListStatik listCatalog, ListStatik listResep, String command);

void initializeSimulator(Simulator *sim, Matrix peta);

#endif