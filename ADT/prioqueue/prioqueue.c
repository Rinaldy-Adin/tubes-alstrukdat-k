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

void CopyPrioqueue(PrioQueue Source, PrioQueue *Dest) {
    /* I.S. Source terdefinisi dan Dest sembarang */
    /* F.S. List Dest berisi nilai yang sama dengan Source */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    MakeEmpty(Dest, MaxEl(Source));
    if (!IsEmpty(Source)) {
        i = Head(Source);
        while (i <= Tail(Source)) {
            Enqueue(Dest, Elmt(Source, i));
            i++;
        }
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
            if (TIMEToMenit(Time(X)) < TIMEToMenit(Time(Elmt(*Q, i))) || i == NBElmt(*Q) - 1) {
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

void deleteAtPQ(PrioQueue *Q, infotype *val, IdxType idx) {
    IdxType i;

    /* ALGORITMA */
    if (NBElmt(*Q) == 1) {
        *val = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        *val = Elmt(*Q, idx + Head(*Q));
        for (i = idx + Head(*Q); i < Tail(*Q); i++) {
            Elmt(*Q, i) = Elmt(*Q, i + 1);
        }
        Tail(*Q)--;
    }
}

/* *** Searching indeks makanan *** */
int idxInventory(PrioQueue Q, Makanan m) {
    /* Mengembalikan indeks Makanan m di inventory */
    /* KAMUS LOKAL */
    int i;
    boolean found;

    /* ALGORITMA */
    if (IsEmpty(Q)) {
        return IDX_UNDEF;
    } else {  // Skema searching dengan boolean
        found = false;
        i = Head(Q);
        while (i <= Tail(Q) && !(found)) {
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
    return (TEQ(Time(x), Time(y)) && stringsAreEqual(ID(Makanan(x)), ID(Makanan(y))));
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
        *result = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }

    for (i = Head(*Q); i <= Tail(*Q); i++) {
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
    int idxResep, idxInv, i;
    Tree r;
    infotype temp, cooked;
    PrioQueue required;  // List bahan yang diperlukan

    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        printf("Anda tidak memiliki makanan di inventory\n");
        return false;
    }

    MakeEmpty(&required, 20);
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
        Enqueue(&required, (*Q).T[idxInv]);
        r = SIBLING(r);
    }
    for (i = Head(*Q); i <= Tail(*Q); i++) {
        Ambil(Q, required.T[i], &temp);
    }
    Makanan(cooked) = MAKAN(TREE(ELMTSTAT(resep, idxResep)));
    Time(cooked) = Kadal(Makanan(cooked));
    Enqueue(Q, cooked);
    return true;
}