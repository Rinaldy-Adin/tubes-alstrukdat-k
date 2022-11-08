#include "inventory.h"

void displayInventory(PrioQueue inventory) {
    /* KAMUS */
    Makanan curr;
    int i;

    /* ALGORITMA */
    printf("List makanan di Inventory:\n");
    if (NBElmt(inventory) == 0) {
        printf(
            "Inventory kosong. Pesan makanan di Telepon menggunakan command "
            "BUY.\n");
    } else {
        printf("nama - waktu sisa kedaluwarsa\n");
        for (i = 0; i < NBElmt(inventory); i++) {
            printf("   %d. ", i + 1);

            printString(Nama(Makanan(Elmt(inventory, i))));
            printf(" - ");
            TulisTIMEShort(Time(Elmt(inventory, i)));

            printf("\n");
        }
    }
}

void removeExpired(PrioQueue *inventoryList, ListStatik *EventsList) {
    int i;
    infotype iType;
    ElTypeStat eType;
    String eventStr;

    for (i = 0; i < NBElmt(*inventoryList); i++) {
        while (TIMEToMenit(Time(Elmt(*inventoryList, i))) == 0 &&
               NBElmt(*inventoryList) > 1) {
            eventStr = createString("Exp");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*inventoryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(EventsList, eType);

            int j;
            for (j = 0; j < Tail(*inventoryList); j++) {
                Elmt(*inventoryList, j) = Elmt(*inventoryList, j + 1);
            }
            Tail(*inventoryList)--;
        }
        if (TIMEToMenit(Time(Elmt(*inventoryList, i))) == 0 &&
            NBElmt(*inventoryList) == 1) {
            eventStr = createString("Exp");
            eventStr =
                concatString(eventStr, ID(Makanan(Elmt(*inventoryList, i))));

            STRING(eType) = eventStr;
            insertLastStat(EventsList, eType);

            Dequeue(inventoryList, &iType);
        }
    }
}
