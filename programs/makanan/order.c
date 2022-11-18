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

void buy(Makanan makanan, int minutesOffset, PrioQueue* inventory) {
    // inventory mungkin kosong, 100 cukup lah ya
    if (!inventory) {
        MakeEmpty(inventory, 100);
    }
    infotype X;
    Makanan(X) = makanan;
    Time(X) = MenitToTIME(TIMEToMenit(Kadal(makanan)) - minutesOffset);
    Enqueue(inventory, X);
}

void decrementTime(PrioQueue* deliveryList, PrioQueue* inventoryList,
                   ListStatik* eventList, int minuteSteps) {
    // Decrement waktu di deliveryList sesuai minuteSteps (kalo 1 berarti
    // dikurang 1 menit)
    int i, minutes;
    infotype iType;
    ElTypeStat eType;
    String eventStr;

    i = Head(*inventoryList);
    while (!IsEmpty(*inventoryList) && i < NBElmt(*inventoryList)) {
        minutes = TIMEToMenit(Time(Elmt(*inventoryList, i))) - minuteSteps;
        printf("%ld\n", TIMEToMenit(Time(Elmt(*inventoryList, i))));
        printf("%d\n", minutes);
        if (minutes < 0)
            minutes = 0;
        Time(Elmt(*inventoryList, i)) = MenitToTIME(minutes);

        if (TIMEToMenit(Time(Elmt(*inventoryList, i))) == 0) {
            eventStr = createString("Exp");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*inventoryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(eventList, eType);

            Dequeue(inventoryList, &iType);
        } else {
            i++;
        }
    }

    i = Head(*deliveryList);
    while (!IsEmpty(*deliveryList) && i < NBElmt(*deliveryList)) {
        minutes = TIMEToMenit(Time(Elmt(*deliveryList, i))) - minuteSteps;

        if (minutes > 0) {
            Time(Elmt(*deliveryList, i)) = MenitToTIME(minutes);
            i++;
        } else {
            minutes *= -1;

            eventStr = createString("Deliv");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*deliveryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(eventList, eType);

            if (minutes < TIMEToMenit(Kadal(Makanan(Elmt(*deliveryList, i))))) {
                buy(Makanan(Elmt(*deliveryList, i)), minutes, inventoryList);
                Dequeue(deliveryList, &iType);
            } else {
                eventStr = createString("Exp");
                eventStr =
                    concatString(eventStr, ID(Makanan(Elmt(*deliveryList, i))));

                STRING(eType) = eventStr;
                insertLastStat(eventList, eType);
                Dequeue(deliveryList, &iType);
            }
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