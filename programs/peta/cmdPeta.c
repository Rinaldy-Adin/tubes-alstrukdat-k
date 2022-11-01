#include "cmdPeta.h"

void readPetaFromFile(Matrix *container, char *filename)  { 
    // KAMUS
    int row, col;
    int i, j, k, digits;
    char buffer[100];

    // INISIALISASI
    STARTWORDFILE(filename);
    createMatrix(0, 0, container); 
    
    // BACA JUMLAH BARIS DAN KOLOM PADA AWAL FILE, KONVERSI KE INTEGER (row, col) 
    row = 0, col = 0;
    for (i=0; i<currentWord.Length; i++) {
        row += (currentWord.TabWord[i] - 48) * power(10, currentWord.Length-i-1);
    }
    ADVWORD();
    for (i=0; i<currentWord.Length; i++) {
        col += (currentWord.TabWord[i] - 48) * power(10, currentWord.Length-i-1);
    }
    IgnoreBlanks();
    
    //printf("row: %d, col: %d\n", row, col);
    
    if (row<10 || col<10) {
        printf("Ukuran peta minimal 10x10.\n");
        return;
    }

    ROW_EFF(*container) = row+2;
    COL_EFF(*container) = col+2;

    // MEMASUKKAN PETA KE DALAM MATRIX
    for (i=1; i<row+1; i++) {
        for (j=1; j<=col+1; j++) {
            if (currentChar == '\n' || currentChar == '\r') {
                IgnoreBlanks();
            }
            else {
                if (currentChar == '#') {
                    ELMT(*container, i, j) = ' ';
                }
                else {
                    ELMT(*container, i, j) = currentChar;
                }
                ADV();
            }
        }
    }

    makeFrame(container);
}

void makeFrame(Matrix *rawPeta) {
    // KAMUS 
    int i, j;

    // ALGORITMA
    for (j = 0; j < COL_EFF(*rawPeta); j++) {
        ELMT(*rawPeta, 0, j) = '*';
        ELMT(*rawPeta, ROW_EFF(*rawPeta)-1, j) = '*';
    }

    for (i = 1; i < ROW_EFF(*rawPeta)-1; i++) {
        ELMT(*rawPeta, i, 0) = '*';
        ELMT(*rawPeta, i, COL_EFF(*rawPeta)-1) = '*';
    }
}

POINT currentPosition(Matrix peta) {
    // KAMUS
    POINT pos;
    int i, j;

    // ALGORITMA
    for (i=0; i<ROW_EFF(peta); i++) {
        for (j=0; j<COL_EFF(peta); j++) {
            if (ELMT(peta, i, j) == 'S') {
                CreatePoint(&pos, i, j);
                return pos;
            }
        }
    }
}

boolean isPositionAvailable(POINT pos, Matrix peta) {
    // ALGORITMA
    if (ROW(pos) > 0 && ROW(pos) < COL_EFF(peta)-1 && COL(pos) > 0 && COL(pos) < ROW_EFF(peta)-1) {
        if (ELMT(peta, ROW(pos), COL(pos)) == ' ' || ELMT(peta, ROW(pos), COL(pos)) == 'S') {
            return true;
        }
        return false;
    }
        return false;
}

boolean isAdjacent(POINT pos, Matrix peta, char object) {
    // ALGORITMA
    return (
        ELMT(peta, ROW(pos)+1, COL(pos)) == object ^ 
        ELMT(peta, ROW(pos)-1, COL(pos)) == object ^
        ELMT(peta, ROW(pos), COL(pos)+1) == object ^
        ELMT(peta, ROW(pos), COL(pos)-1) == object
    );
}

void move(POINT *pos, Matrix *peta, char direction) {
    // KAMUS
    POINT temp;

    // ALGORITMA
    CreatePoint(&temp, ROW(*pos), COL(*pos));

    // Hitung posisi baru
    if (direction == 'S') {ROW(temp)++;}
    else if (direction == 'N') {ROW(temp)--;}
    else if (direction == 'W') {COL(temp)--;}
    else if (direction == 'E') {COL(temp)++;}

    if (isPositionAvailable(temp, *peta)) {
        // Karakter 'S' pada posisi sebelumnya dihapus dan karakter 'S' diletakkan di posisi baru
        ELMT(*peta, ROW(*pos), COL(*pos)) = ' ';
        ROW(*pos) = ROW(temp);
        COL(*pos) = COL(temp);
        ELMT(*peta, ROW(temp), COL(temp)) = 'S';
    }
    else {
        printf("Posisi tersebut tidak tersedia.\n");
    }
 }





