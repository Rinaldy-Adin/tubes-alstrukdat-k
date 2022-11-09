#include "makanan.h"

int main() {
    /* KAMUS */
    Makanan testM, testM2;
    TIME t;

    /* ALGORITMA */
    printf("========== MEMBUAT MAKANAN BARU ==========\n");
    CreateTime(&t, 10, 10, 10);
    makeMakanan(&testM, createString("100"), createString("Makanan test"), t, t, t, createString("Buy"), 10, 10);
    printf("ID makanan baru : ");
    printString(ID(testM));
    printf("\n");
    printf("Nama makanan baru : ");
    printString(Nama(testM));
    printf("\n");
    printf("Waktu kedaluwarsa makanan baru : ");
    TulisTIME(Kadal(testM));
    printf("\n");
    printf("Waktu antar makanan baru : ");
    TulisTIME(DelTime(testM));
    printf("\n");
    printf("Waktu aksi makanan baru : ");
    TulisTIME(ActTime(testM));
    printf("\n");
    printf("Aksi untuk mendapat makanan baru : ");
    printString(Command(testM));
    printf("\n");
    printf("Ukuran makanan baru : ");
    printf("%d x %d", Width(testM), Height(testM));
    printf("\n\n");

    printf("========== MEMAJUKAN KEDALUWARSA MAKANAN ==========\n");
    advKadal(&testM, 5);
    printf("Sisa waktu kedaluwarsa makanan setelah 5 menit : ");
    TulisTIME(Kadal(testM));
    printf("\n\n");

    printf("========== APAKAH 2 MAKANAN SAMA ==========\n");
    printf("Keterangan : dilakukan dengan memeriksa ID makanan karena ID bersifat unique\n");
    makeMakanan(&testM2, createString("99"), createString("Makanan test 2"), t, t, t, createString("Buy"), 10, 10);
    if (isMakananEqual(testM, testM2)) {
        printf("Kedua makanan sama\n");
    } else {
        printf("Kedua makanan berbeda\n");
    }
}