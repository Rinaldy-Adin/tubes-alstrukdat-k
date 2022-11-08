#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <stdio.h>

#include "../../ADT/liststatik/listStatik.h"
#include "../../ADT/prioqueue/prioqueue.h"

void displayInventory(PrioQueue inventory);

void removeExpired(PrioQueue *inventoryList, ListStatik *EventsList);

#endif