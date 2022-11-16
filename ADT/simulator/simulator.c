/* File: simulator.c */
/* Implementasi ADT simulator */

#include "simulator.h"

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, POINT pos, TIME time,
                     PrioQueue inventory, PrioQueue delivery,
                     ListStatik events) {
    /* ALGORITMA */
    NamaSim(*sim) = nama;
    PositionSim(*sim) = pos;
    InventorySim(*sim) = inventory;
    Time(*sim) = time;
    DeliverySim(*sim) = delivery;
    EventsSim(*sim) = events;
}
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

void CopySimulator(Simulator sim, Simulator* newSim) {
    copyString(NamaSim(sim), &NamaSim(*newSim));
    PositionSim(*newSim) = PositionSim(sim);
    CopyPrioqueue(InventorySim(sim), &InventorySim(*newSim));
    Time(*newSim) = Time(sim);
    CopyPrioqueue(DeliverySim(sim), &DeliverySim(*newSim));
    CopyListStatikString(EventsSim(sim), &EventsSim(*newSim));
}
/* I.S. sim terdefinisi, newSim sembarang */
/* F.S. seluruh komponen newSim terisi dengan nilai yang sama
        dengan sim; */
/* Proses: deep copy dengan memanggil fungsi
           copy untuk tipe data yang mengandung pointer */

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