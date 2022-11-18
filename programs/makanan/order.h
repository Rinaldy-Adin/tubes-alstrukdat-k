#ifndef ORDER_H
#define ORDER_H

#include "../../ADT/prioqueue/prioqueue.h"

void delivery(Makanan* makanan, PrioQueue* deliveryList);

void buy(Makanan makanan, int minutesOffset, PrioQueue* inventory);

void decrementTime(PrioQueue* deliveryList, PrioQueue* inventoryList,
                   ListStatik* eventList, int minuteSteps);

void displayDelivery(PrioQueue delivery);

#endif
