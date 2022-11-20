/* File: simulator.h */
/* Definisi ADT Simulator */

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "../kulkas/kulkas.h"
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
    Kulkas kulkas;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define NamaSim(s) (s).nama
#define PositionSim(s) (s).pos
#define InventorySim(s) (s).inventory
#define TimeSim(s) (s).time
#define DeliverySim(s) (s).delivery
#define EventsSim(s) (s).events
#define KulkasSim(s) (s).kulkas

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, POINT pos, TIME time, PrioQueue inventory,
                     PrioQueue delivery, ListStatik events, Kulkas kulkas);
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

void CopySimulator(Simulator sim, Simulator* newSim);
/* I.S. sim terdefinisi, newSim sembarang */
/* F.S. seluruh komponen newSim terisi dengan nilai yang sama
        dengan sim; */
/* Proses: deep copy dengan memanggil fungsi
           copy untuk tipe data yang mengandung pointer */

#endif