/* File: driver_liststatik.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 23 Oktober 2022 */
/* Deskripsi: implementasi ADT list statik untuk Makanan */

#include <stdio.h>
#include "listStatik.h"

int main() {
    ListStatik testMakanan, testResep, testMByCommand, testString, testStringCopy;
    Makanan testM;
    Tree testR;
    TIME t;
    ElTypeStat elM, elR, elS;
    String str;
    int i;

    printf("========== MEMBUAT LIST STATIK KOSONG ==========\n");
    printf("Tidak menghasilkan output, hanya langsung terbentuk ListStatik kosong\n");
    CreateListStatik(&testMakanan);
    CreateListStatik(&testResep);
    printf("\n");

    printf("========== MENYALIN ISI LIST STATIK STRING ==========\n");
    CreateListStatik(&testString);
    STRING(elS) = createString("satu");
    insertLastStat(&testString, elS);
    STRING(elS) = createString("dua");
    insertLastStat(&testString, elS);
    CopyListStatikString(testString, &testStringCopy);
    printf("String awal:");
    printListString(testString);
    printf("String salinan:");
    printListString(testStringCopy);

    printf("========== MELAKUKAN LOAD MAKANAN DAN RESEP DARI FILE KONFIGURASI ==========\n");
    loadMakanan(&testMakanan, "./pita.txt");
    loadResep(&testResep, testMakanan, "./pitaResep.txt");
    printf("\n");
    
    printf("========== PANJANG LIST ==========\n");
    printf("Panjang list testMakanan: ");
    printf("%d\n", listLengthStat(testMakanan));
    printf("Panjang list testResep: ");
    printf("%d\n", listLengthStat(testResep));
    printf("\n");

    printf("========== INDEKS TERAKHIR LIST ==========\n");
    printf("Indeks terakhir list testMakanan: ");
    printf("%d\n", getLastIdxStat(testMakanan));
    printf("Indeks terakhir list testResep: ");
    printf("%d\n", getLastIdxStat(testResep));
    printf("\n");

    printf("========== IS IDX EFEKTIF, IS IDX VALID ==========\n");
    printf("Masukkan indeks yang ingin dicek : ");
    scanf("%d", &i);
    if (isIdxValidStat(i)) {
        if (isIdxEffStat(testMakanan, i)) {
            printf("Index tersebut valid dan efektif pada List testMakanan\n");
        }
        else {
            printf("Index tersebut valid tapi tidak efektif pada List testMakanan\n");
        }
    }
    else {
        printf("Index tersebut tidak valid\n");
    }
    printf("\n");

    printf("========== IS LIST EMPTY ==========\n");
    if (isEmptyStat(testMakanan)) {
        printf("List testMakanan kosong\n");
    }
    else {
        printf("List testMakanan tidak kosong\n");
    }
    printf("\n");

    printf("========== IS LIST FULL ==========\n");
    if (isFullStat(testMakanan)) {
        printf("List testMakanan penuh\n");
    }
    else {
        printf("List testMakanan tidak penuh\n");
    }
    printf("\n");

    printf("========== MENCETAK KATALOG DAN COOKBOOK ==========\n");
    printf("Katalog makanan\n");
    printListMakanan(testMakanan);
    printf("Cookbook\n");
    printResep(testResep);
    printf("\n");

    printf("========== IS LIST EQUAL ==========\n");
    if (isListEqualStat(testMakanan, testResep)) {
        printf("List testMakanan dan testResep sama\n");
    }
    else {
        printf("List testMakanan dan testResep berbeda\n");
    }
    printf("\n");

    printf("========== SEARCHING MAKANAN/RESEP PADA LIST MAKANAN DAN RESEP ==========\n");
    printf("Keterangan : memakai ID makanan yang bersangkutan\n");
    printf("Indeks katalog makanan dengan ID 31 : %d\n", indexOfMakanan(testMakanan, createString("31")));
    printf("Indeks resep makanan dengan ID 100 : %d\n", indexOfResep(testResep, createString("100")));
    printf("\n");

    
    printf("========== OPERASI INSERT/DELETE ==========\n");
    CreateTime(&t, 10, 10, 10);
    makeMakanan(&testM, createString("100"), createString("Makanan test"), t, t, t, createString("Buy"), 10, 10);
    MAKANAN(elM) = testM;

    insertFirstStat(&testMakanan, elM);
    insertAtStat(&testMakanan, elM, 2);
    insertLastStat(&testMakanan, elM);
    printf("Hasil setelah insert first, at, dan last :\n");
    printListMakanan(testMakanan);

    deleteFirstStat(&testMakanan, &elM);
    deleteAtStat(&testMakanan, &elM, 1);
    deleteLastStat(&testMakanan, &elM);
    printf("Hasil setelah delete first, at, dan last :\n");
    printListMakanan(testMakanan);
    printf("\n");

    printf("========== MEMBUAT LIST MAKANAN TERKELOMPOK BERDASARKAN COMMAND ==========\n");
    testMByCommand = listMakananCommand(createString("Fry"), testMakanan);
    printf("\n");

    printf("========== MEMBAGI STRING ==========\n");
    str = createString("satu dua tiga");
    printf("String awal: ");
    printString(str);
    printf("\n");
    testString = splitString(str);
    printListString(testString);
}