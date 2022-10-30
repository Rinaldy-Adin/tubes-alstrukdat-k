/* File: makanan.h */
/* Tanggal: 22 Oktober 2022 */
/* Implementasi ADT makanan */

#include <stdio.h>
#include "makanan.h"

/* KONSTRUKTOR */
void makeMakanan(Makanan *m, String id, String nama, TIME kadaluwarsa, TIME del, TIME act, String command) {
    /* I.S. m sembarang */
    /* F.S. seluruh komponen m terisi sesuai masukan. */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    ID(*m) = id;
    Nama(*m) = nama;
    Kadal(*m) = kadaluwarsa;
    DelTime(*m) = del;
    ActTime(*m) = act;
    Command(*m) = command;
}

/*** PRIMITIF ***/
void advKadal(Makanan *m, int n) {
    /* I.S. m sudah terdefinisi */
    /* F.S. kadaluwarsa m bertambah sebanyak n menit */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    Kadal(*m) = NextNMenit(Kadal(*m), n);
}

boolean isMakananEqual(Makanan m1, Makanan m2) {
    /* Mengembalikan true jika m1 = m2 (dicek dari ID) */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (stringsAreEqual(ID(m1),ID(m2)));
}