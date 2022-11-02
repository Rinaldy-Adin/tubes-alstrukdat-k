#include "point.h"

int main() {
    POINT test1, test2;
    int x, y;

    printf("========== BACA POINT ==========\n");
    printf("Note : Fungsi ini tidak digunakan di program utama karena\n");
    printf("      pembacaan input menggunakan mesin karakter dan mesin kata\n");
    printf("Masukkan titik pertama: ");
    BacaPOINT(&test1);
    printf("Masukkan titik kedua: ");
    BacaPOINT(&test2);
    printf("\n");

    printf("========== TULIS POINT ==========\n");
    printf("titik pertama: \n");
    TulisPOINT(test1);
    printf("\n");
    printf("titik kedua: \n");
    TulisPOINT(test2);
    printf("\n\n");

    printf("========== IS EQUAL ==========\n");
    if (EQ(test1, test2)) {
        printf("Titik pertama sama dengan titik kedua\n\n");
    }
    else {
        printf("Titik pertama tidak sama dengan titik kedua\n\n");
    }

    printf("========== GESER ==========\n");
    printf("(Menggeser titik pertama)\n");
    printf("Masukkan perubahan baris: ");
    scanf("%d", &x);
    printf("Masukkan perubahan kolom: ");
    scanf("%d", &y);
    Geser(&test1, x, y);
    TulisPOINT(test1);
    printf("\n");

}