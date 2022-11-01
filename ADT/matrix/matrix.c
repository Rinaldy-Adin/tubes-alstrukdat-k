#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di
 * "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i <= ROW_CAP - 1 && j >= 0 && j <= COL_CAP - 1);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMat(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i <= ROW_EFF(m) - 1 && j >= 0 && j <= COL_EFF(m) - 1);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (int i = 0; i < ROW_EFF(mIn); i++) {
        for (int j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    ROW_EFF(*m) = nRow;
    COL_EFF(*m) = nCol;
    for (int i = 0; i < ROW_EFF(*m); i++) {
        for (int j = 0; j < COL_EFF(*m); j++) {
            scanf("%c", &ELMT(*m, i, j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayMatrix(Matrix m) {
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (j != COL_EFF(m) - 1) {
                printf("%c ", ELMT(m, i, j));
            } else {
                printf("%c\n", ELMT(m, i, j));
            }
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen
   per baris dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan
   newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan
 * per kolom */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2))) {
        for (int i = 0; i < ROW_EFF(m1); i++) {
            for (int j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))) {
        return true;
    } else {
        for (int i = 0; i < ROW_EFF(m1); i++) {
            for (int j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2
 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    return (ROW_EFF(m) * COL_EFF(m));
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    return (ROW_EFF(m) == COL_EFF(m));
}
