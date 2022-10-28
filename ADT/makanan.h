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
    TIME delTime; // Waktu yang diperlukan untuk delivery
    TIME actTime; // Waktu yang diperlukan untuk aksi (selain delivery)
    String command;
} Makanan;

/* *** Notasi Akses: selektor Makanan *** */
#define ID(M) (M).id
#define Nama(M) (M).nama
#define Kadal(M) (M).kadaluwarsa
#define Command(M) (M).command
#define DelTime(M) (M).delTime
#define ActTime(M) (M).actTime

/*** KONSTRUKTOR ***/
void makeMakanan(Makanan *m, String id, String nama, TIME kadaluwarsa, TIME del, TIME act, String command);
/* I.S. m sembarang */
/* F.S. seluruh komponen m terisi sesuai masukan. */

/*** PRIMITIF ***/
void advKadal(Makanan *m, int n);
/* I.S. m sudah terdefinisi */
/* F.S. kadaluwarsa m bertambah sebanyak n menit */

boolean isMakananEqual(Makanan m1, Makanan m2);
/* Mengembalikan true jika m1 = m2 (dicek dari ID) */
#endif