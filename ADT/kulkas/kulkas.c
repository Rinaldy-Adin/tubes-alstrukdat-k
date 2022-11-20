#include "kulkas.h"

void createEmptyKulkas(Kulkas *pIn) {
    createMatrix(KULKAS_ROWCAP, KULKAS_COLCAP, &(DISP(*pIn)));
    // Frame kulkas
    for (int j = 0; j < KULKAS_COLCAP; j++) {
        ELMT((DISP(*pIn)), 0, j) = '=';
        ELMT((DISP(*pIn)), KULKAS_ROWCAP - 1, j) = '=';
    }

    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        ELMT((DISP(*pIn)), i, 0) = '|';
        ELMT((DISP(*pIn)), i, KULKAS_COLCAP - 1) = '|';
    }

    // Isi kulkas (kosong/blank)
    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        for (int j = 1; j < KULKAS_COLCAP - 1; j++) {
            ELMT((DISP(*pIn)), i, j) = ' ';
        }
    }
    MakeEmpty(&(CONT(*pIn)), MAXKULKAS);
}

void copyKulkas(Kulkas Src, Kulkas *Dest) {
    createMatrix(KULKAS_ROWCAP, KULKAS_COLCAP, &(DISP(*Dest)));
    // Frame kulkas
    for (int j = 0; j < KULKAS_COLCAP; j++) {
        ELMT((DISP(*Dest)), 0, j) = ELMT((DISP(Src)), 0, j);
        ELMT((DISP(*Dest)), KULKAS_ROWCAP - 1, j) = ELMT((DISP(Src)), KULKAS_ROWCAP - 1, j);
    }

    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        ELMT((DISP(*Dest)), i, 0) = ELMT((DISP(Src)), i, 0);
        ELMT((DISP(*Dest)), i, KULKAS_COLCAP - 1) = ELMT((DISP(Src)), i, KULKAS_COLCAP - 1);
    }

    // Isi kulkas (kosong/blank)
    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        for (int j = 1; j < KULKAS_COLCAP - 1; j++) {
            ELMT((DISP(*Dest)), i, j) = ELMT((DISP(Src)), i, j);
        }
    }
    CopyPrioqueue(CONT(Src), &(CONT(*Dest)));
}

void displayKulkas(Kulkas K) {
    printf("~~~~~~~~~~ TAMPILAN KULKAS ~~~~~~~~~~ \n");

    for (int i = 0; i < KULKAS_ROWCAP; i++) {
        for (int j = 0; j < KULKAS_COLCAP; j++) {
            if (ELMT(DISP(K), i, j) == '*') {
                printf(" ");
            } else {
                printf("%c", ELMT(DISP(K), i, j));
            }
        }
        printf("\n");
    }
    printf("\n");

    printf(" ~~~~~~~~~~ APA SAJA YANG ADA DI KULKAS? ~~~~~~~~~~ \n");
    if (IsEmpty(CONT(K))) {
        printf("Kulkas kosong.\n");
    } else {
        printf("No | Nama Makanan | ID | Waktu kadaluarsa (jika dikeluarkan dari kulkas) \n");
        for (int i = 0; i < NBElmt(CONT(K)); i++) {
            printf("%d | ", i + 1);
            printString(Elmt(CONT(K), i).makanan.nama);
            printf(" | ");
            printString(Elmt(CONT(K), i).makanan.id);
            printf(" | ");
            TulisTIME(Elmt(CONT(K), i).time);
            printf("\n");
        }
    }
}

void getSpaceRequired(Makanan M, int *rows, int *cols) {
    *rows = Height(M) + 1;
    *cols = (LEN(ID(M)) + 1) * Width(M);
}

boolean isSpaceAvailable(Kulkas K, int upperRow, int leftCol, int rowsReq, int colsReq) {
    for (int i = upperRow; i < upperRow + rowsReq; i++) {
        for (int j = leftCol; j < leftCol + colsReq; j++) {
            if (ELMT(DISP(K), i, j) != ' ') {
                return false;
            }
        }
    }
    return true;
}

void findSpaceInKulkas(Kulkas K, int *upperRow, int *leftCol, int rowsReq, int colsReq) {
    // INISIALISASI
    *upperRow = -1;
    *leftCol = -1;

    for (int i = 1; i < KULKAS_ROWCAP - rowsReq; i++) {
        for (int j = 1; j < KULKAS_COLCAP - colsReq; j++) {
            if (isSpaceAvailable(K, i, j, rowsReq, colsReq)) {
                *upperRow = i;
                *leftCol = j;
                return;
            }
        }
    }
}

void insertToKulkas(infotype in, Kulkas *pK) {
    // Baris dan kolom yang diperlukan untuk makanan:
    int rowsReq, colsReq;
    // Posisi makanan:
    int upperRow, leftCol;

    getSpaceRequired(in.makanan, &rowsReq, &colsReq);
    findSpaceInKulkas(*pK, &upperRow, &leftCol, rowsReq, colsReq);

    if (upperRow != -1 && leftCol != -1) {
        putInKulkas(pK, in.makanan, upperRow, leftCol, rowsReq, colsReq);
        Enqueue(&CONT(*pK), in);
        // ElTypeStat temp;
        // temp.m = in;
        // insertLastStat(&CONT(*pK), temp);
    } else {
        printf("Kulkas penuh :(");
    }
}

void putInKulkas(Kulkas *pK, Makanan M, int upperRow, int leftCol, int rowsReq, int colsReq) {
    for (int i = upperRow; i < upperRow + rowsReq - 1; i++) {
        for (int j = leftCol; j < leftCol + colsReq; j++) {
            int k = (j - leftCol + 1) % (LEN(ID(M)) + 1);
            if (k != 0) {
                ELMT(DISP(*pK), i, j) = ID(M).Tab[k - 1];
            } else {
                ELMT(DISP(*pK), i, j) = '*';
            }
        }
    }
    for (int j = leftCol; j < leftCol + colsReq; j++) {
        ELMT(DISP(*pK), upperRow + rowsReq - 1, j) = '*';
    }
}

void removeFromKulkas(Kulkas *pK, int idx, infotype *out) {
    int rowsCleared, colsCleared;
    int pos_row, pos_col;
    String id;
    infotype temp;

    if (idx >= NBElmt(CONT(*pK)) || idx < 0) {
        printf("Index makanan tidak valid.\n");
        return;
    } else {
        temp = Elmt(CONT(*pK), idx);
        id = temp.makanan.id;
        Ambil(&CONT(*pK), temp, out);
        Time(*out) = MenitToTIME(TIMEToMenit(Time(*out)) + 1);
        // deleteAtStat(&CONT(*pK), &temp, idx);
        // *out = temp.m;
        getSpaceRequired(out->makanan, &rowsCleared, &colsCleared);
        findFoodPosition(*pK, &pos_row, &pos_col, id);
        clearSpace(pK, pos_row, pos_col, rowsCleared, colsCleared);
    }
}

void findFoodPosition(Kulkas K, int *pos_row, int *pos_col, String id) {
    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        for (int j = 1; j < KULKAS_COLCAP - LEN(id); j++) {
            if (ELMT(DISP(K), i, j) == id.Tab[0] &&
                (ELMT(DISP(K), i, j - 1) == '|' || ELMT(DISP(K), i, j - 1) == '*' ||
                 ELMT(DISP(K), i, j - 1) == ' ')) {
                if (cmpID(K, id, i, j)) {
                    // printf("posisi: %d %d\n", i, j);
                    *pos_row = i;
                    *pos_col = j;
                    return;
                }
            }
        }
    }
}

boolean cmpID(Kulkas K, String id, int i, int j) {
    for (int k = 0; k < LEN(id); k++) {
        if (ELMT(DISP(K), i, j + k) != id.Tab[k]) {
            return false;
        }
    }
    return (ELMT(DISP(K), i, j + LEN(id)) == '|' || ELMT(DISP(K), i, j + LEN(id)) == '*' ||
            ELMT(DISP(K), i, j + LEN(id)) == ' ');
}

void clearSpace(Kulkas *pK, int pos_row, int pos_col, int rowsCleared, int colsCleared) {
    for (int i = pos_row; i < pos_row + rowsCleared; i++) {
        for (int j = pos_col; j < pos_col + colsCleared; j++) {
            ELMT(DISP(*pK), i, j) = ' ';
        }
    }
}
