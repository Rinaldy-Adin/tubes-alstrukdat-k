#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int X, int Y) {
    ROW(*P)=X;
    COL(*P)=Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
    int x,y;
    scanf("%d %d", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT (POINT P) {
    printf("(%d,%d)", ROW(P), COL(P));
}              

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
    return ((ROW(P1)==ROW(P2))&&(COL(P1)==COL(P2)));
}

void Geser (POINT *P, int deltaX, int deltaY) {
    ROW(*P) += deltaX;
    COL(*P) += deltaY;
}






