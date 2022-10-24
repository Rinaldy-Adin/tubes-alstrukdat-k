/* File: makanan.h */
/* Tanggal: 22 Oktober 2022 */
/* Implementasi ADT makanan */

#include <stdio.h>
#include "wordmachine.c"
#include "makanan.h"

/* KONSTRUKTOR */
void makeMakanan(Makanan *m, Word id, Word nama, Word kadaluwarsa, Word deliver, Word command) {
    /* I.S. m sembarang */
    /* F.S. seluruh komponen m terisi sesuai masukan. */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    ID(*m) = id;
    Nama(*m) = nama;
    Kadal(*m) = wordToTime(kadaluwarsa);
    DelTime(*m) = wordToTime(deliver);
    Command(*m) = command.TabWord[0];
}

/*** PRIMITIF ***/
void advKadal(Makanan *m, int n) {
    /* I.S. m sudah terdefinisi */
    /* F.S. kadaluwarsa m bertambah sebanyak n menit */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    Kadal(*m) = NextNMenit(Kadal(*m), n);
}