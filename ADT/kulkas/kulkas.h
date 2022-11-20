#ifndef KULKAS_H
#define KULKAS_H

#include <stdio.h>

#include "../../boolean.h"
#include "../liststatik/listStatik.h"
#include "../makanan/makanan.h"
#include "../matrix/matrix.h"
#include "../prioqueue/prioqueue.h"
#include "../strlib/strlib.h"

/* DEFINISI DAN SPESIFIKASI ADT KULKAS */
typedef struct {
    Matrix disp;
    PrioQueue contents;
} Kulkas;

#define KULKAS_ROWCAP 20
#define KULKAS_COLCAP 30
#define MAXKULKAS 50

/* SELEKTOR */
#define DISP(k) (k).disp
#define CONT(k) (k).contents

void createEmptyKulkas(Kulkas *pIn);

void copyKulkas(Kulkas Src, Kulkas *Dest);

void displayKulkas(Kulkas K);

void getSpaceRequired(Makanan M, int *rows, int *cols);

boolean isSpaceAvailable(Kulkas K, int upperRow, int leftCol, int rowsReq, int colsReq);

void findSpaceInKulkas(Kulkas K, int *upperRow, int *leftCol, int rowsReq, int colsReq);

void putInKulkas(Kulkas *pK, Makanan M, int upperRow, int leftCol, int rowsReq, int colsReq);

void insertToKulkas(infotype in, Kulkas *pK);

void findFoodPosition(Kulkas K, int *pos_row, int *pos_col, String id);

boolean cmpID(Kulkas K, String id, int i, int j);

void clearSpace(Kulkas *pK, int pos_row, int pos_col, int rowsCleared, int colsCleared);

void removeFromKulkas(Kulkas *pK, int idx, infotype *out);

#endif