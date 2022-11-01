/* File: simulator.c */
/* Implementasi ADT simulator */

#include "simulator.h"

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, POINT pos, TIME time,
                     PrioQueue inventory) {
    /* ALGORITMA */
    NamaSim(*sim) = nama;
    PositionSim(*sim) = pos;
    InventorySim(*sim) = inventory;
    Time(*sim) = time;
}
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

PrioQueue AdvInventory(PrioQueue inventory) {
    /* KAMUS */
    int i, n;

    /* ALGORITMA */
    i = Head(inventory);

    while (i <= Tail(inventory)) {
        advKadal(&Makanan(Elmt(inventory, i)), 1);
        Time(Elmt(inventory, i)) = NextNMenit(Time(Elmt(inventory, i)), 1);
        i++;
    }

    return inventory;
}
/* Mengembalikan state inventory dimana semua makanan kadaluarsanya sudah "maju"
 */