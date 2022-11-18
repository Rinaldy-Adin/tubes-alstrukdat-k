#include "kulkas.h"

void createEmptyKulkas (Kulkas *pIn) {
    createMatrix(KULKAS_ROWCAP, KULKAS_COLCAP, &(DISP(*pIn)));
    // Frame kulkas
    for (int j=0; j<KULKAS_COLCAP; j++) {
        ELMT((DISP(*pIn)), 0, j) = '=';
        ELMT((DISP(*pIn)), KULKAS_ROWCAP-1, j) = '=';
    }

    for (int i=1; i<KULKAS_ROWCAP-1; i++) {
        ELMT((DISP(*pIn)), i, 0) = '|';
        ELMT((DISP(*pIn)), i, KULKAS_COLCAP-1) = '|';
    }

    // Isi kulkas (kosong/blank)
    for (int i=1; i<KULKAS_ROWCAP-1; i++) {
        for (int j=1; j<KULKAS_COLCAP-1; j++) {
            ELMT((DISP(*pIn)), i, j) = ' ';
        }
    }
    CreateListStatik(&(CONT(*pIn)));
}

void displayKulkas(Kulkas K) {
    printf("~~~~~~~~~~ TAMPILAN KULKAS ~~~~~~~~~~ \n");
    
    for (int i=0; i<KULKAS_ROWCAP; i++) {
        for (int j =0; j<KULKAS_COLCAP; j++) {
            if (ELMT(DISP(K), i, j) == '*') {
                printf(" ");
            }
            else {
                printf("%c", ELMT(DISP(K), i, j));
            }
        }
        printf("\n");
   }
    printf("\n");


    printf(" ~~~~~~~~~~ APA SAJA YANG ADA DI KULKAS? ~~~~~~~~~~ \n");
    if (isEmptyStat(CONT(K))) {
        printf("Kulkas kosong.\n");
    }
    else {
        printf("No | Nama Makanan | ID | Waktu kadaluarsa (jika dikeluarkan dari kulkas) \n");
        for (int i = 0; i < NEFFSTAT(CONT(K)); i++) {
            printf("%d | ", i+1);
            printString(ELMTSTAT(CONT(K), i).m.nama);
            printf(" | ");
            printString(ELMTSTAT(CONT(K), i).m.id);
            printf(" | ");
            TulisTIME(ELMTSTAT(CONT(K), i).m.kadaluwarsa);
            printf("\n");
        } 
    }
}

void getSpaceRequired(Makanan M, int *rows, int *cols) {
    *rows = Height(M) + 1;
    *cols = (LEN(ID(M)) + 1) * Width(M);
}

boolean isSpaceAvailable(Kulkas K, int upperRow, int leftCol, int rowsReq, int colsReq) {
    for (int i=upperRow; i < upperRow + rowsReq; i++) {
        for (int j=leftCol; j < leftCol + colsReq; j++) {
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

    for (int i=1; i < KULKAS_ROWCAP - rowsReq; i++) {
        for (int j=1; j < KULKAS_COLCAP - colsReq; j++) {
            if (isSpaceAvailable(K, i, j, rowsReq, colsReq)) {
                *upperRow = i;
                *leftCol = j;
                return;
            }
        }
    }
}

void insertToKulkas(Makanan in, Kulkas *pK) {
    // Baris dan kolom yang diperlukan untuk makanan:
    int rowsReq, colsReq;
    // Posisi makanan: 
    int upperRow, leftCol;

    getSpaceRequired(in, &rowsReq, &colsReq);
    findSpaceInKulkas(*pK, &upperRow, &leftCol, rowsReq, colsReq);

    if (upperRow != -1 && leftCol != -1) {
        putInKulkas(pK, in, upperRow, leftCol, rowsReq, colsReq);
        ElTypeStat temp;
        temp.m = in;
        insertLastStat(&CONT(*pK), temp);
    }
    else {
        printf("Kulkas penuh :(");
    }
}

void putInKulkas(Kulkas *pK, Makanan M, int upperRow, int leftCol, int rowsReq, int colsReq) {
    for (int i = upperRow; i < upperRow + rowsReq - 1; i++) {
        for (int j = leftCol; j < leftCol + colsReq; j++) {
            int k = (j - leftCol + 1) % (LEN(ID(M)) + 1);
            if (k != 0) {
                ELMT(DISP(*pK), i, j) = ID(M).Tab[k-1];
            }
            else {
                ELMT(DISP(*pK), i, j) = '*';
            }
        }
    }
    for (int j = leftCol; j < leftCol + colsReq; j++) {
        ELMT(DISP(*pK), upperRow + rowsReq - 1, j) = '*';
    }
}

void removeFromKulkas(Kulkas *pK, String id, Makanan *out) {
    int rowsCleared, colsCleared;
    int idx;
    int pos_row, pos_col;
    ElTypeStat temp;

    idx = indexOfMakanan(CONT(*pK), id);
    if (idx == IDX_UNDEF) {
        printf("Makanan tersebut tidak ada di kulkas.\n");
        return;
    }
    else {
        deleteAtStat(&CONT(*pK), &temp, idx);
        *out = temp.m;
        getSpaceRequired(*out, &rowsCleared, &colsCleared);
        findFoodPosition(*pK, &pos_row, &pos_col, id);
        clearSpace(pK, pos_row, pos_col, rowsCleared, colsCleared);
    }
    
}

void findFoodPosition(Kulkas K, int *pos_row, int *pos_col, String id) {
    for (int i = 1; i < KULKAS_ROWCAP - 1; i++) {
        for (int j = 1; j < KULKAS_COLCAP - LEN(id) ; j++) {
            if (ELMT(DISP(K), i, j) == id.Tab[0] && (ELMT(DISP(K), i, j-1) == '|' || ELMT(DISP(K), i, j-1) == '*' || ELMT(DISP(K), i, j-1) == ' ')) {
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
    return true;
}

void clearSpace(Kulkas *pK, int pos_row, int pos_col, int rowsCleared, int colsCleared) {
    for (int i = pos_row; i < pos_row + rowsCleared; i++) {
        for (int j = pos_col; j < pos_col + colsCleared; j++) {
            ELMT(DISP(*pK), i, j) = ' ';
        }
    }
}

