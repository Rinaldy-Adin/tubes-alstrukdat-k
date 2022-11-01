/* File: simulator.h */
/* Definisi ADT Simulator */

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "../point/point.h"
#include "../prioqueue/prioqueue.h"
#include "../strlib/strlib.h"
#include "../waktu/waktu.h"

typedef struct {
    String nama;
    POINT pos;
    PrioQueue inventory;
    TIME time;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define NamaSim(s) (s).nama
#define PositionSim(s) (s).pos
#define InventorySim(s) (s).inventory
#define TimeSim(s) (s).time

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, POINT pos, TIME time,
                     PrioQueue inventory);
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

PrioQueue AdvInventory(PrioQueue inventory);
/* Mengembalikan state inventory dimana semua makanan kadaluarsanya sudah "maju"
 */

#endif