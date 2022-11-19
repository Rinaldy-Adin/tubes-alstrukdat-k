#include "kulkas.h"

// cd tubes-alstrukdat-j-priv
// gcc driver_kulkas.c kulkas.c ../matrix/matrix.c ../strlib/strlib.c ../makanan/makanan.c
// ../liststatik/listStatik.c ../waktu/waktu.c ../charmachine/charmachine.c
// ../wordmachine/wordmachine.c ../tree/tree.c ../prioqueue/prioqueue.c -o driver_kulkas
// ./driver_kulkas

int main() {
    Kulkas test;
    infotype Ayam;
    Makanan ayam;
    String nama = createString("ayam");
    String id = createString("14");
    ayam.nama = nama;
    ayam.id = id;
    ayam.height = 2;
    ayam.width = 3;
    Ayam.makanan = ayam;
    Ayam.time.DD = 3;
    Ayam.time.HH = 2;
    Ayam.time.MM = 48;

    infotype Bawang;
    Makanan bawang;
    String nama2 = createString("bawang");
    String id2 = createString("123");
    bawang.nama = nama2;
    bawang.id = id2;
    bawang.height = 1;
    bawang.width = 1;
    Bawang.makanan = bawang;
    Bawang.time.DD = 1;
    Bawang.time.HH = 4;
    Bawang.time.MM = 0;

    infotype Sambal;
    Makanan sambal;
    String nama3 = createString("sambal");
    String id3 = createString("56");
    sambal.nama = nama3;
    sambal.id = id3;
    sambal.height = 4;
    sambal.width = 4;
    Sambal.makanan = sambal;
    Sambal.time.DD = 0;
    Sambal.time.HH = 2;
    Sambal.time.MM = 1;

    printf(
        "Penjelasan makanan (hanya berlaku driver ini saja sebagai contoh): \n"
        "1. ayam,  ID = 14, height: 2, width: 3, kadaluwarsa: (3,2,48)\n"
        "2. bawang, ID = 123, height: 1, width: 1, kadaluwarsa: (1,4,0\n"
        "3. sambal, ID: 56, height: 4; width: 4, kadaluwarsa: (0,2,1)\n\n");

    printf("A. CREATE EMPTY KULKAS\n\n");
    createEmptyKulkas(&test);
    displayKulkas(test);
    printf("\n");

    printf("B. INSERT TO KULKAS \n\n");

    printf("1. MASUKKAN AYAM KE KULKAS\n");
    insertToKulkas(Ayam, &test);
    displayKulkas(test);
    printf("\n");

    printf("2. MASUKKAN BAWANG KE KULKAS\n");
    insertToKulkas(Bawang, &test);
    displayKulkas(test);
    printf("\n");

    printf("3. MASUKKAN SAMBAL KE KULKAS\n");
    insertToKulkas(Sambal, &test);
    displayKulkas(test);
    printf("\n");

    printf("4. MASUKKAN AYAM KE KULKAS\n");
    insertToKulkas(Ayam, &test);
    displayKulkas(test);
    printf("\n");

    printf("5. MASUKKAN BAWANG KE KULKAS\n");
    insertToKulkas(Bawang, &test);
    displayKulkas(test);
    printf("\n");

    printf("6. MASUKKAN SAMBAL KE KULKAS\n");
    insertToKulkas(Sambal, &test);
    displayKulkas(test);
    printf("\n\n");

    printf("C. REMOVE FROM KULKAS\n\n");
    infotype temp;
    printf("1. REMOVE MAKANAN KEDUA DI LIST DARI KULKAS\n");
    removeFromKulkas(&test, 2 - 1, &temp);
    displayKulkas(test);
    printf("\n");
    printf("Makanan yg diremove: ");
    printString(temp.makanan.nama);
    printf("\nWaktu kadaluarsa: ");
    TulisTIME(temp.time);
    printf("\n\n");

    printf("2. REMOVE MAKANAN KELIMA DI LIST DARI KULKAS\n");
    removeFromKulkas(&test, 5 - 1, &temp);
    displayKulkas(test);
    printf("\n");
    printf("Makanan yg diremove: ");
    printString(temp.makanan.nama);
    printf("\nWaktu kadaluarsa: ");
    TulisTIME(temp.time);
    printf("\n\n");

    printf("2. REMOVE MAKANAN KE-99 DARI KULKAS\n");
    removeFromKulkas(&test, 99 - 1, &temp);
    displayKulkas(test);
    printf("\n");
}
