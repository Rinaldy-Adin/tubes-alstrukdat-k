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
