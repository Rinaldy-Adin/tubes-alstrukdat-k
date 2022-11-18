#include "kulkas.h"

// cd tubes-alstrukdat-j-priv
// gcc driver_kulkas.c kulkas.c ../matrix/matrix.c ../strlib/strlib.c
// ../makanan/makanan.c ../liststatik/listStatik.c ../waktu/waktu.c
// ../charmachine/charmachine.c ../wordmachine/wordmachine.c ../tree/tree.c -o
// driver_kulkas
// ./driver_kulkas

int main() {
    Kulkas test;
    Makanan ayam;
    String nama = createString("ayam");
    String id = createString("14");
    ayam.nama = nama;
    ayam.id = id;
    ayam.height = 2;
    ayam.width = 3;
    ayam.kadaluwarsa.DD = 3;
    ayam.kadaluwarsa.HH = 2;
    ayam.kadaluwarsa.MM = 48;

    Makanan bawang;
    String nama2 = createString("bawang");
    String id2 = createString("123");
    bawang.nama = nama2;
    bawang.id = id2;
    bawang.height = 1;
    bawang.width = 1;
    bawang.kadaluwarsa.DD = 1;
    bawang.kadaluwarsa.HH = 4;
    bawang.kadaluwarsa.MM = 0;

    Makanan sambal;
    String nama3 = createString("sambal");
    String id3 = createString("56");
    sambal.nama = nama3;
    sambal.id = id3;
    sambal.height = 4;
    sambal.width = 4;
    sambal.kadaluwarsa.DD = 0;
    sambal.kadaluwarsa.HH = 2;
    sambal.kadaluwarsa.MM = 1;

    printf(
        "Penjelasan makanan (berlaku driver ini saja sebagai contoh): \n"
        "1. ayam,  ID = 14, height: 2, width: 3, kadaluwarsa: (3,2,48)\n"
        "2. bawang, ID = 123, height: 1, width: 1, kadaluwarsa: (1,4,0\n"
        "3. sambal, ID: 56, height: 4; width: 4, kadaluwarsa: (0,2,1)\n\n");

    printf("A. CREATE EMPTY KULKAS\n\n");
    createEmptyKulkas(&test);
    displayKulkas(test);
    printf("\n");

    printf("B. INSERT TO KULKAS \n\n");
    printf("1. MASUKKAN AYAM KE KULKAS\n");
    insertToKulkas(ayam, &test);
    displayKulkas(test);
    printf("\n");
    printf("2. MASUKKAN BAWANG KE KULKAS\n");
    insertToKulkas(bawang, &test);
    displayKulkas(test);
    printf("\n");
    printf("3. MASUKKAN SAMBAL KE KULKAS\n");
    insertToKulkas(sambal, &test);
    displayKulkas(test);
    printf("\n");
    printf("4. MASUKKAN AYAM KE KULKAS\n");
    insertToKulkas(ayam, &test);
    displayKulkas(test);
    printf("\n");
    printf("5. MASUKKAN BAWANG KE KULKAS\n");
    insertToKulkas(bawang, &test);
    displayKulkas(test);
    printf("\n");
    printf("6. MASUKKAN SAMBAL KE KULKAS\n");
    insertToKulkas(sambal, &test);
    displayKulkas(test);
    printf("\n");

    printf("C. REMOVE FROM KULKAS\n\n");
    Makanan temp;
    printf("1. REMOVE MAKANAN DENGAN ID 56 DARI KULKAS\n");
    removeFromKulkas(&test, id3, &temp);
    displayKulkas(test);
    printf("\n");
    printf("2. REMOVE MAKANAN DENGAN ID 14 DARI KULKAS\n");
    removeFromKulkas(&test, id, &temp);
    displayKulkas(test);
    printf("\n");
    printf("2. REMOVE MAKANAN DENGAN ID 99 DARI KULKAS\n");
    removeFromKulkas(&test, createString("99"), &temp);
    displayKulkas(test);
    printf("\n");
}
