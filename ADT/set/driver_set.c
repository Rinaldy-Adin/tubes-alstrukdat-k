/* File : driver_set.c */
/* Driver untuk menguji ADT Set */

#include "set.h"

int main() {
    /* KAMUS */
    ListStatik katalog, resep;
    PrioQueue inv;
    infotype isiInv;
    Set test, test2, uni;
    int i;

    /* ALGORITMA */
    // Inisialisasi katalog dan list resep yang ada
    loadMakanan(&katalog, "./pita.txt");
    loadResep(&resep, katalog, "./pitaResep.txt");

    printf("========== MEMBUAT SET KOSONG ==========\n");
    CreateSet(&test, katalog);
    printf("Set test sudah diinisialisasi.\n");

    printf("========== MENAMBAH MAKANAN KE SET ==========\n");
    for (i=0; i<NEFFSTAT(katalog); i++) {
        AddElmtSet(&test, ELMTSTAT(katalog,i), katalog);
    }
    printf("Set test sudah diisi dengan seluruh makanan katalog.\n");

    printf("========== UJI SUBSET DAN KESAMAAN DUA SET ==========\n");
    CreateSet(&test2, katalog);
    for (i=0; i<NEFFSTAT(katalog)-1; i++) {
        AddElmtSet(&test2, ELMTSTAT(katalog,i), katalog);
    }
    printf("Apakah Set test2 merupakan subset dari test ? ");
    if (isSubset(test,test2)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    printf("========== MENGHAPUS ELEMEN SET ==========\n");
    for (i=0; i<NEFFSTAT(katalog); i++) {
        RemoveElmtSet(&test, ELMTSTAT(katalog,i), katalog);
    }
    printf("Seluruh isi Set test sudah dihapus.\n");
    printf("Apakah Set test2 merupakan subset dari test ? ");
    if (isSubset(test,test2)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    printf("========== REKOMENDASI MAKANAN (SEKALIGUS CompareInvWTree YANG DIGUNAKAN DI REKOMENDASI MAKANAN) ==========\n");
    printf("Dengan inventory kosong\n");
    MakeEmpty(&inv, NEFFSTAT(katalog));
    RecommendMakanan(inv, resep, katalog);

    printf("Dengan inventory berisi n-4 jenis makanan di katalog\n");
    for (i=0; i<NEFFSTAT(katalog)-4; i++) {
        if (i != 1) {
            Makanan(isiInv) = MAKANAN(ELMTSTAT(katalog,i));
            Enqueue(&inv, isiInv);
        }
    }
    printf("\n");
    RecommendMakanan(inv, resep, katalog);

    printf("Dengan inventory berisi seluruh makanan di katalog\n");
    for (i=0; i<NEFFSTAT(katalog); i++) {
        if (i != 1) {
            Makanan(isiInv) = MAKANAN(ELMTSTAT(katalog,i));
            Enqueue(&inv, isiInv);
        }
    }
    printf("\n");
    RecommendMakanan(inv, resep, katalog);
    return 0;
}