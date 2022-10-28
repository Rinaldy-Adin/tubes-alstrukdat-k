//
// Created by ammar on 24/10/2022.
//

#include "prioqueue.h"
#include "stdlib.h"

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
    (*Q).T = (infotype *) malloc((Max + 1) * sizeof(infotype));
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
        Head(*Q) = 1;
        Tail(*Q) = 1;
        Elmt(*Q, 1) = X;
    } else {
        Tail(*Q)++;
        Elmt(*Q, Tail(*Q)) = X;
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

// Fungsi internal
boolean checkEq(infotype x, infotype y) {
    return (Time(x) == Time(y)) && stringsAreEqual(ID(Makanan(x)), ID(Makanan(y)));
}

void Ambil(PrioQueue *Q, infotype X, infotype *result) {
    if (NBElmt(*Q) == 1 && checkEq(InfoHead(*Q), X)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        *result = InfoHead(*Q);
    }
    int i;
    for (i = 0; i < NBElmt(*Q); i++) {
        if (checkEq(Elmt(*Q, i), X)) {
            infotype temp = Elmt(*Q, i);
            int j;
            for (j = i; j < Tail(*Q); j++) {
                Elmt(*Q, j) = Elmt(*Q, j + 1);
            }
            Tail(*Q)--;
            *result = temp;
        }
    }
}