#include "order.h"

void delivery(Makanan* makanan, PrioQueue* deliveryList) {
    // deliveryList mungkin kosong, 100 cukup lah ya
    if (!deliveryList) {
        MakeEmpty(deliveryList, 100);
    }
    infotype X;
    Makanan(X) = *makanan;
    Time(X) = DelTime(*makanan);
    Enqueue(deliveryList, X);
}

void buy(Makanan* makanan, PrioQueue* inventory) {
    // inventory mungkin kosong, 100 cukup lah ya
    if (!inventory) {
        MakeEmpty(inventory, 100);
    }
    infotype X;
    Makanan(X) = *makanan;
    Time(X) = Kadal(*makanan);
    Enqueue(inventory, X);
}

void decrementTime(PrioQueue* deliveryList, int minuteSteps) {
    // Decrement waktu di deliveryList sesuai minuteSteps (kalo 1 berarti dikurang 1 menit)
    int i;
    for(i = 0; i < NBElmt(*deliveryList); i++) {
        Time(Elmt(*deliveryList, i)) = MenitToTIME(TIMEToMenit(Time(Elmt(*deliveryList, i))) - minuteSteps);
    }
}

void removeDelivered(PrioQueue* deliveryList, PrioQueue* inventory) {
    // Remove dari deliveryList, di enqueue ke inventory
    int i;
    for(i = 0; i < NBElmt(*deliveryList); i++) {
        if (TIMEToMenit(Time(Elmt(*deliveryList, i))) == 0) {
            Enqueue(inventory, Elmt(*deliveryList, i));
            int j;
            for (j = i; j < Tail(*deliveryList); j++) {
                Elmt(*deliveryList, j) = Elmt(*deliveryList, j + 1);
            }
            Tail(*deliveryList)--;
        }
    }
}
