#include <stdio.h>

#include "matrix.h"

int main() {
    Matrix test1, test2, test3;
    int brs1, brs2, klm1, klm2;
    int row1, col1;
    char temp;
    printf("========== BACA MATRIX ==========\n");
    printf("Note : Fungsi ini tidak digunakan di program utama karena\n");
    printf(
        "      pembacaan input menggunakan mesin karakter dan mesin kata.\n");
    printf("Contoh cara input baris dan kolom: \n");
    printf("3 3\n");
    printf("Contoh cara input matrix: \n");
    printf("abc\ndef\nghi\n\n");
    printf(
        "Masukkan banyak baris dan kolom matrix pertama (dengan format brs "
        "klm): ");
    scanf("%d %d", &brs1, &klm1);
    scanf("%c", &temp);
    printf("Masukkan elemen matrix pertama:\n");
    readMatrix(&test1, brs1, klm1);
    printf("\n");
    printf(
        "Masukkan banyak baris dan kolom matrix kedua (dengan format brs "
        "klm): ");
    scanf("%d %d", &brs2, &klm2);
    scanf("%c", &temp);
    printf("Masukkan elemen matrix kedua:\n");
    readMatrix(&test2, brs2, klm2);
    printf("\n\n");

    printf("========== TULIS MATRIX ==========\n");
    printf("Matrix pertama: \n");
    displayMatrix(test1);
    printf("\nMatrix kedua: \n");
    displayMatrix(test2);
    printf("\n");

    printf("========== IS IDX EFEKTIF, IS IDX VALID ==========\n");
    printf("Masukkan banyak baris dan kolom matrix (dengan format brs klm): ");
    scanf("%d %d", &row1, &col1);
    if (isMatrixIdxValid(row1, col1)) {
        if (isIdxEff(test1, row1, col1)) {
            printf("Index tersebut valid dan efektif pada matrix pertama \n");
        } else {
            printf("Index tersebut tidak efektif pada matrix pertama\n");
        }
    } else {
        printf("Index tersebut tidak valid\n");
    }
    printf("\n");

    printf("========== IS MATRIX EQUAL ==========\n");
    if (isMatrixEqual(test1, test2)) {
        printf("Matrix pertama sama dengan matrix kedua\n");
    } else {
        printf("Matrix pertama tidak sama dengan matrix kedua\n");
    }
    printf("\n");

    printf("========== IS MATRIX SIZE EQUAL ==========\n");
    if (isMatrixSizeEqual(test1, test2)) {
        printf("Ukuran kedua matrix sama\n");
    } else {
        printf("Ukuran kedua matrix berbeda\n");
    }
    printf("\n");

    printf("========== COPY MATRIX ==========\n");
    copyMatrix(test1, &test3);
    printf("Matrix ketiga: \n");
    displayMatrix(test3);
    printf("\n");

    printf("========== IS SQUARE ==========\n");
    if (isSquare(test1)) {
        printf("Matrix pertama persegi\n");
    } else {
        printf("Matrix pertama bukan persegi\n");
    }
    printf("\n");

    printf("========== COUNT ELEMENT ==========\n");
    printf("Banyak elemen matrix pertama: %d\n", countElmt(test1));
}