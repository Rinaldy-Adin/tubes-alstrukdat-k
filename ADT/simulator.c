/* File: simulator.c */
/* Implementasi ADT simulator */

#include "simulator.h"

#include "point.h"
#include "prioqueue.h"
#include "strlib.h"

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, int posX, int posY, int day,
                     int hour, int min, PrioQueue inventory) {
    /* ALGORITMA */
    POINT pos;
    CreatePoint(&pos, posX, posY);

    Nama(*sim) = nama;
    Position(*sim) = pos;
    Inventory(*sim) = inventory;
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