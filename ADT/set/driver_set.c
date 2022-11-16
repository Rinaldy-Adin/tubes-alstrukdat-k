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
    printf("Set test sudah diinisialisasi. Apakah kosong ? ");
    if (isSetEmpty(test)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    printf("========== MENAMBAH MAKANAN KE SET ==========\n");
    for (i=0; i<NEFFSTAT(katalog); i++) {
        AddElmtSet(&test, ELMTSTAT(katalog,i), katalog);
    }
    printf("Set test sudah diisi dengan seluruh makanan katalog. Apakah set kosong ? ");
    if (isSetEmpty(test)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    for (i=0; i<NEFFSTAT(katalog); i++) {
        printf("Apa ");
        printString(Nama(MAKANAN(ELMTSTAT(katalog,i))));
        printf(" ada di Set test ? ");
        if (isInSet(test,ELMTSTAT(katalog,i), katalog)) {
            printf("Iya\n");
        } else {
            printf("Tidak\n");
        }
    }
    printf("\n");

    printf("========== UJI SUBSET DAN KESAMAAN DUA SET ==========\n");
    CreateSet(&test2, katalog);
    for (i=0; i<NEFFSTAT(katalog)-1; i++) {
        AddElmtSet(&test2, ELMTSTAT(katalog,i), katalog);
    }
    printf("Apakah Set test dan test2 sama ? ");
    if (isSetEqual(test,test2)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("Apakah Set test2 merupakan subset dari test ? ");
    if (isSubset(test,test2)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }
    printf("\n");

    printf("========== UJI UNION ==========\n");
    printf("Isi Set test : ");
    for (i=0; i<NEFFSTAT(test); i++) {
        printf("%d ", INTEGER(ELMTSTAT(test,i)));
    }       
    printf("\n");
    printf("Isi Set test2 : ");
    for (i=0; i<NEFFSTAT(test2); i++) {
        printf("%d ", INTEGER(ELMTSTAT(test2,i)));
    }       
    printf("\n");
    uni = Union(test, test2, katalog);
    printf("Isi Set hasil union test dan test2 : ");
    for (i=0; i<NEFFSTAT(uni); i++) {
        printf("%d ", INTEGER(ELMTSTAT(uni,i)));
    }       
    printf("\n\n");

    printf("========== MENGHAPUS ELEMEN SET ==========\n");
    for (i=0; i<NEFFSTAT(katalog); i++) {
        RemoveElmtSet(&test, ELMTSTAT(katalog,i), katalog);
    }
    printf("Seluruh isi Set test sudah dihapus. Apakah kosong ? ");
    if (isSetEmpty(test)) {
        printf("Iya\n");
    } else {
        printf("Tidak\n");
    }

    printf("========== REKOMENDASI MAKANAN (SEKALIGUS CompareInvWTree YANG DIGUNAKAN DI REKOMENDASI MAKANAN) ==========\n");
    printf("Dengan inventory kosong\n");
    MakeEmpty(&inv, NEFFSTAT(katalog));
    RecommendMakanan(inv, resep, katalog);

    printf("Dengan inventory berisi beberapa makanan di katalog\n");
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