/* File: makanan.h */
/* Tanggal: 22 Oktober 2022 */
/* Definisi ADT makanan */

#ifndef MAKANAN_H
#define MAKANAN_H

#include <stdio.h>
#include "boolean.h"
#include "waktu.h"
#include "strlib.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
    String id;
	String nama;
    TIME kadaluwarsa;
    TIME actTime; // Waktu yang diperlukan untuk delivery
    String command; // B = Buy, F = Fry, M = Mix, C = Chop, O = Boil
} Makanan;

/* *** Notasi Akses: selektor Makanan *** */
#define ID(M) (M).id
#define Nama(M) (M).nama
#define Kadal(M) (M).kadaluwarsa
#define Command(M) (M).command
#define ActTime(M) (M).actTime
#define Buy 'B'
#define Fry 'F'
#define Mix 'M'
#define Chop 'C'
#define Boil 'O'

/*** KONSTRUKTOR ***/
void makeMakanan(Makanan *m, String id, String nama, TIME kadaluwarsa, TIME actTime, String command);
/* I.S. m sembarang */
/* F.S. seluruh komponen m terisi sesuai masukan. */

/*** PRIMITIF ***/
void advKadal(Makanan *m, int n);
/* I.S. m sudah terdefinisi */
/* F.S. kadaluwarsa m bertambah sebanyak n menit */

#endif