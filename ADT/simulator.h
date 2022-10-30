/* File: simulator.h */
/* Definisi ADT Simulator */

#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include "point.h"
#include "prioqueue.h"
#include "strlib.h"

typedef struct {
    String nama;
    POINT pos;
    PrioQueue inventory;
} Simulator;

/* *** Notasi Akses: selektor Simulator *** */
#define Nama(s) (s).nama
#define Position(s) (s).pos
#define Inventory(s) (s).inventory

/*** KONSTRUKTOR ***/
void CreateSimulator(Simulator* sim, String nama, int posX, int posY, int day,
                     int hour, int min, PrioQueue inventory);
/* I.S. sim sembarang */
/* F.S. seluruh komponen sim terisi sesuai masukan. */

PrioQueue AdvInventory(PrioQueue inventory);
/* Mengembalikan state inventory dimana semua makanan kadaluarsanya sudah "maju"
 */

#endif