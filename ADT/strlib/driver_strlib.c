#include "strlib.h"

int main() {
    /* KAMUS */
    String str, copyStr, s1, s2;
    int satu, dua;

    /* ALGORITMA */
    printf("========== MEMBUAT STRING BARU ==========\n");
    str = createString("BNMO");
    printf("String yang dihasilkan: ");
    printString(str);
    printf("\n");
    printf("\n");

    printf("========== MENYALIN STRING BARU ==========\n");
    copyString(str, &copyStr);
    printf("Menyalin string dan mengubah nilai salinan\n");
    printf("String Awal : ");
    printString(str);
    printf("\n");
    printf("String Salinan : ");
    copyStr = createString("OMNB");
    printString(copyStr);
    printf("\n");
    printf("\n");

    printf("========== MEMBACA DAN MENAMPILKAN STRING ==========\n");
    printf("Masukkan string: ");
    START();
    str = readLine();
    printString(str);
    printf("\n");
    printf("\n");

    printf("========== PERBANDINGAN STRING ==========\n");
    s1 = createString("Satu");
    s2 = createString("Satu");
    printf("String 1: ");
    printString(s1);
    printf("\n");
    printf("String 2: ");
    printString(s2);
    printf("\n");
    if (stringsAreEqual(s1, s2))
        printf("String satu dan 2 sama\n");
    printf("\n");

    s1 = createString("Satu");
    s2 = createString("Dua");
    printf("String 1: ");
    printString(s1);
    printf("\n");
    printf("String 2: ");
    printString(s2);
    printf("\n");
    if (!stringsAreEqual(s1, s2))
        printf("String satu dan 2 beda\n");
    printf("\n");
    printf("\n");

    printf("========== OPERASI STRING ==========\n");
    s1 = createString("Satu");
    s2 = createString("Satu");
    printf("String 1: ");
    printString(s1);
    printf("\n");
    printf("String 2: ");
    printString(s2);
    printf("\n");
    printf("Penggabungan dau string : ");
    printString(concatString(s1, s2));
    printf("\n");

    s1 = createString("        Satu   Dua     ");
    printf("String : \"");
    printString(s1);
    printf("\"");
    s1 = removeLongSpaces(s1);
    printf("\n");
    printf("String dipotong: \"");
    printString(s1);
    printf("\"");
    printf("\n");
    printf("\n");

    printf("========== KONVERSI STRING ==========\n");
    str = createString("Satu");
    printf("String : ");
    printString(s1);
    printf("\n");
    if (!stringIsIntParsable(str))
        printf("String tidak bisa diubah jadi int\n");
    printf("\n");

    s1 = createString("1");
    s2 = createString("2");
    printf("String 1 : ");
    printString(s1);
    printf("\n");
    printf("String 2 : ");
    printString(s2);
    printf("\n");
    if (stringIsIntParsable(s1) && stringIsIntParsable(s2))
        printf("String 1 dan 2 bisa diubah jadi int\n");
    printf("Hasil penjumlahan parsing: %d", stringToInt(s1) + stringToInt(s2));
    printf("\n");
    printf("\n");

    str = createString("2 3 1");
    printf("String 1 : ");
    printString(str);
    printf("\n");
    printf("Hasil parsing sebagai TIME: ");
    TulisTIME(stringToTime(str));

    printf("\n");
    printf("\n");
}