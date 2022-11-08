/* File: simulator.h */
/* Definisi ADT Simulator */

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "../liststatik/listStatik.h"
#include "../point/point.h"
#include "../prioqueue/prioqueue.h"
#include "../strlib/strlib.h"
#include "../waktu/waktu.h"

typedef struct {
    String nama;
    POINT pos;
    PrioQueue inventory;
    PrioQueue delivery;
    ListStatik events;
    TIME time;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define NamaSim(s) (s).nama
#define PositionSim(s) (s).pos
#define InventorySim(s) (s).inventory
#define TimeSim(s) (s).time
#define DeliverySim(s) (s).delivery
#define EventsSim(s) (s).events

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, POINT pos, TIME time,
                     PrioQueue inventory, PrioQueue delivery,
                     ListStatik events);
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

void CopySimulator(Simulator sim, Simulator* newSim);

PrioQueue AdvInventory(PrioQueue inventory);
/* Mengembalikan state inventory dimana semua makanan kadaluarsanya sudah "maju"
 */

#endif