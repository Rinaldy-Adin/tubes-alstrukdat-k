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
    // Decrement waktu di deliveryList sesuai minuteSteps (kalo 1 berarti
    // dikurang 1 menit)
    int i, minutes;
    for (i = 0; i < NBElmt(*deliveryList); i++) {
        minutes = TIMEToMenit(Time(Elmt(*deliveryList, i))) - minuteSteps;
        if (minutes < 0)
            minutes = 0;
        Time(Elmt(*deliveryList, i)) = MenitToTIME(minutes);
    }
}

void removeDelivered(PrioQueue* deliveryList, PrioQueue* inventory,
                     ListStatik* EventsList) {
    // Remove dari deliveryList, di enqueue ke inventory
    int i;
    infotype iType;
    ElTypeStat eType;
    String eventStr;

    for (i = 0; i < NBElmt(*deliveryList); i++) {
        while (TIMEToMenit(Time(Elmt(*deliveryList, i))) == 0 &&
               NBElmt(*deliveryList) > 1) {
            eventStr = createString("Deliv");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*deliveryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(EventsList, eType);

            buy(&Makanan(Elmt(*deliveryList, i)), inventory);

            int j;
            for (j = 0; j < Tail(*deliveryList); j++) {
                Elmt(*deliveryList, j) = Elmt(*deliveryList, j + 1);
            }
            Tail(*deliveryList)--;
        }
        if (TIMEToMenit(Time(Elmt(*deliveryList, i))) == 0 &&
            NBElmt(*deliveryList) == 1) {
            eventStr = createString("Deliv");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*deliveryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(EventsList, eType);

            Dequeue(deliveryList, &iType);
            buy(&Makanan(Elmt(*deliveryList, i)), inventory);
        }
    }
}

void displayDelivery(PrioQueue delivery) {
    /* KAMUS */
    Makanan curr;
    int i;

    /* ALGORITMA */
    printf("List makanan di Delivery:\n");
    if (NBElmt(delivery) == 0) {
        printf(
            "Delivery list kosong. Pesan makanan di Telepon menggunakan "
            "command "
            "BUY.\n");
    } else {
        printf("nama - waktu sisa delivery\n");
        for (i = 0; i < NBElmt(delivery); i++) {
            printf("   %d. ", i + 1);

            printString(Nama(Makanan(Elmt(delivery, i))));
            printf(" - ");
            TulisTIMEShort(Time(Elmt(delivery, i)));

            printf("\n");
        }
    }
}