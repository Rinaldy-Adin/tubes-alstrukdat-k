/* File: stack.c */
/* Deskripsi: Realisasi fungsi dan prosedur ADT stack */

#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack* S) {
    /* KAMUS */
    /* ALGORITMA */
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean StackIsEmpty(Stack S) {
    return Top(S) == NilStack;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean StackIsFull(Stack S) {
    return Top(S) == MaxElStack - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

int stackSize(Stack S) {
    return Top(S) + 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack* S, infotypeStack X) {
    int i;

    if (StackIsFull(*S)) {
        for (i = 0; i < MaxElStack - 1; i++) {
            StackElmt(*S, i) = StackElmt(*S, i + 1);
            Top(*S) = i;
        }
    }

    Top(*S)++;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack* S, infotypeStack* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
