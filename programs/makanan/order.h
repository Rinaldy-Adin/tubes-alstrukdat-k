#ifndef ORDER_H
#define ORDER_H

#include "prioqueue/prioqueue.h"

void delivery(Makanan* makanan, PrioQueue* deliveryList);

void buy(Makanan* makanan, PrioQueue* inventory);

void decrementTime(PrioQueue* deliveryList, int minuteSteps);

void removeDelivered(PrioQueue* deliveryList, PrioQueue* inventory);

#endif
