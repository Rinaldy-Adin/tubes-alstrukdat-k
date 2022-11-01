/* File : prioqueue.h */
/* Implementasi ADT Priority Queue Time dengan representasi array secara
 * eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */
/* Created by ammar on 24/10/2022. */

#include "prioqueue.h"

boolean IsEmpty(PrioQueue Q) {
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull(PrioQueue Q) {
    return (Tail(Q) == MaxEl(Q));
}

int NBElmt(PrioQueue Q) {
    if (IsEmpty(Q)) {
        return 0;
    }
    return (Tail(Q) - Head(Q) + 1);
}

void MakeEmpty(PrioQueue *Q, int Max) {
    (*Q).T = malloc(Max * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueue *Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue(PrioQueue *Q, infotype X) {
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q, 0) = X;
    } else {
        Tail(*Q)++;
        int i;
        for (i = 0; i < NBElmt(*Q); i++) {
            if (TIMEToMenit(Time(X)) < TIMEToMenit(Time(Elmt(*Q, i)))) {
                int j;
                for (j = Tail(*Q); j > i; j--) {
                    Elmt(*Q, j) = Elmt(*Q, j - 1);
                }
                Elmt(*Q, i) = X;
                break;
            }
        }
    }
}

void Dequeue(PrioQueue *Q, infotype *X) {
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        *X = InfoHead(*Q);
        Head(*Q)++;
    }
}

/* *** Searching indeks makanan *** */
int idxInventory(PrioQueue Q, Makanan m) {
    /* Mengembalikan indeks Makanan m di inventory */
    /* KAMUS LOKAL */
    int i;
    int length;
    boolean found;

    /* ALGORITMA */
    if (IsEmpty(Q)) {
        return IDX_UNDEF;
    } else {  // Skema searching dengan boolean
        found = false;
        length = NBElmt(Q);
        i = 0;
        while (i < length && !(found)) {
            if (isMakananEqual(m, Q.T[i].makanan)) {
                found = true;
            } else {
                i++;
            }
        }
        if (found) {
            return i;
        } else {
            return IDX_UNDEF;
        }
    }
}

// Fungsi internal
boolean checkEq(infotype x, infotype y) {
    /* Mengecek apakah x dan y sama */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TEQ(Time(x), Time(y)) &&
            stringsAreEqual(ID(Makanan(x)), ID(Makanan(y))));
}

void Ambil(PrioQueue *Q, infotype X, infotype *result) {
    /* Proses: Mengambil X pada Q dan dihapus setelah operasi */
    /* I.S. Q tidak mungkin kosong, mungkin ada X */
    /* F.S. Q mungkin kosong. Jika X tidak ditemukan maka result tidak berubah
     */
    /* KAMUS LOKAL */
    int i, j;
    infotype temp;

    /* ALGORITMA */
    if (NBElmt(*Q) == 1 && checkEq(InfoHead(*Q), X)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        *result = InfoHead(*Q);
    }

    for (i = 0; i < NBElmt(*Q); i++) {
        if (checkEq(Elmt(*Q, i), X)) {
            temp = Elmt(*Q, i);
            for (j = i; j < Tail(*Q); j++) {
                Elmt(*Q, j) = Elmt(*Q, j + 1);
            }
            Tail(*Q)--;
            *result = temp;
        }
    }
}

boolean Cook(String IDMakanan, PrioQueue *Q, ListStatik resep) {
    /* Proses: Memasak makanan dengan ID IDMakanan jika ada di resep dan
     * bahannya ada di inventory */
    /* I.S. IDMakanan, *Q, resep terdefinisi */
    /* F.S. Jika bahan dan resep ada, makanan dengan ID IDMakanan terbentuk.
     * Makanan di Q berkurang. Q mungkin kosong. */
    /* KAMUS LOKAL */
    int idxResep, idxInv;
    Tree r;
    infotype required, temp, cooked;

    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        printf("Anda tidak memiliki makanan di inventory\n");
        return false;
    }

    // Cari makanan di resep
    idxResep = indexOfResep(resep, IDMakanan);
    if (idxResep == IDX_UNDEF) {
        printf("Makanan tersebut tidak ada di resep\n");
        return false;
    }

    r = TREE(ELMTSTAT(resep, idxResep));
    r = CHILD(r);
    while (r != NULL) {
        idxInv = idxInventory(*Q, MAKAN(r));
        if (idxInv == IDX_UNDEF) {
            printf("Gagal memasak karena Anda tidak memiliki bahan : ");
            printString(Nama(MAKAN(r)));
            printf("\n");
            return false;
        }
        required = (*Q).T[idxInv];
        Ambil(Q, required, &temp);
        r = SIBLING(r);
    }
    Makanan(cooked) = MAKAN(TREE(ELMTSTAT(resep, idxResep)));
    Time(cooked) = Kadal(Makanan(cooked));
    Enqueue(Q, cooked);
    return true;
}