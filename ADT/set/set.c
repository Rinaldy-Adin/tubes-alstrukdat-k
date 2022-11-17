/* File : set.c */
/* Implementasi ADT set */

#include "set.h"

void CreateSet(Set *s, ListStatik makanan) {
    /* I.S. s sembarang */
    /* F.S. s terbentuk menjadi Set "kosong" dengan jumlah indeks yang dipakai sesuai indeks pada ListStatik makanan */
    /* KAMUS LOKAL */
    int i;
    ElTypeStat el;

    /* ALGORITMA */
    CreateListStatik(s);
    INTEGER(el) = 0;
    for (i=0; i<NEFFSTAT(makanan); i++) {
        insertLastStat(s, el);
    }
}

boolean isSetEmpty(Set s) {
    /* Mengembalikan true jika s kosong (seluruh makanan berjumlah 0) */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i=0; i<NEFFSTAT(s); i++) {
        if (INTEGER(ELMTSTAT(s,i)) > 0) {
            return false;
        }
    }
    return true;
}

boolean isInSet(Set s, ElTypeStat e, ListStatik makanan) { /* Belum dipake */
    /* Mengembalikan true jika e ada di s (jumlah makanan e tidak 0) */
    /* KAMUS LOKAL */
    int idx;

    /* ALGORITMA */
    idx = indexOfMakanan(makanan, ID(MAKANAN(e)));
    return (INTEGER(ELMTSTAT(s,idx)) > 0);
}

boolean isSetEqual(Set s1, Set s2) { /* Belum dipake */
    /* Mengembalikan true jika s1 sama dengan s2 */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    if (NEFFSTAT(s1) != NEFFSTAT(s2)) {
        return false;
    } else {
        for (i=0; i<NEFFSTAT(s1); i++) {
            if (INTEGER(ELMTSTAT(s1,i)) != INTEGER(ELMTSTAT(s2,i))) {
                return false;
            }
        }
        return true;
    }
}

boolean isSubset(Set s1, Set s2) {
    /* Mengembalikan true jika s2 adalah subset dari s1 */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    if (NEFFSTAT(s2) != NEFFSTAT(s1)) {
        return false;
    } else {
        for (i=0; i<NEFFSTAT(s2); i++) {
            if (((INTEGER(ELMTSTAT(s1,i)) == 0) && (INTEGER(ELMTSTAT(s2,i)) != 0))) {
                return false;
            }
        }
        return true;
    }
}

void AddElmtSet(Set *s, ElTypeStat e, ListStatik makanan) {
    /* I.S. s terdefinisi */
    /* F.S. Jumlah elemen e di s bertambah 1 */
    /* KAMUS LOKAL */
    int idx;

    /* ALGORITMA */
    idx = indexOfMakanan(makanan, ID(MAKANAN(e)));
    INTEGER(ELMTSTAT(*s,idx))++;
}

void RemoveElmtSet(Set *s, ElTypeStat e, ListStatik makanan) {
    /* I.S. s terdefinisi, tidak kosong */
    /* F.S. e dithapus dari s (jika ada) */
    /* KAMUS LOKAL */
    int idx;

    /* ALGORITMA */
    idx = indexOfMakanan(makanan, ID(MAKANAN(e)));
    INTEGER(ELMTSTAT(*s,idx))--;
}

Set Union(Set s1, Set s2, ListStatik katalog) { /* Belum dipake */
    /* Menghasilkan Set hasil union s1 dan s2. Prekondisi : NEFF s1 dan s2 sama */
    /* KAMUS LOKAL */
    Set sUnion;
    int i;

    /* ALGORITMA */
    CreateSet(&sUnion, katalog);
    for (i=0; i<NEFFSTAT(s1); i++) {
        if (INTEGER(ELMTSTAT(s1,i)) >= INTEGER(ELMTSTAT(s2,i))) {
            ELMTSTAT(sUnion,i) = ELMTSTAT(s1,i);
        } else {
            ELMTSTAT(sUnion,i) = ELMTSTAT(s2,i);
        }
    }
    return sUnion;
}

boolean CompareInvWTree(Set *S, Set inv, Tree T, ListStatik katalog) {
    /* Mengembalikan true jika makanan di inventory bisa membuat makanan di resep T */
    /* KAMUS LOKAL */
    ElTypeStat m;

    /* ALGORITMA */
    MAKANAN(m) = MAKAN(T);
    AddElmtSet(S, m, katalog);
    if (SIBLING(T) != NULL) {
        if (CompareInvWTree(S, inv, SIBLING(T), katalog)) {
            return true;
        }
    }
    if (isSubset(inv, *S)) {
        return true;
    }
    if (CHILD(T) != NULL) {
        RemoveElmtSet(S, m, katalog);
        return CompareInvWTree(S, inv, CHILD(T), katalog);
    }
    return false;
}

void RecommendMakanan(PrioQueue inventory, ListStatik resep, ListStatik katalog) {
    /* Memberikan rekomendasi makanan berdasarkan makanan yang ada di inventory */
    /* I.S. inventory, resep, dan katalog terdefinisi */
    /* F.S. Rekomendasi makanan tercetak ke layar */
    /* KAMUS LOKAL */
    Set inv,setResep;
    ElTypeStat m;
    int i, j, idx;
    boolean anyRecomm, recommended;
    Address p,q;

    /* ALGORITMA */
    CreateSet(&inv, katalog);

    // Pengisisan set inventory
    for (i = 0; i < NBElmt(inventory); i++) {
        MAKANAN(m) = Makanan(Elmt(inventory,i));
        AddElmtSet(&inv,m,katalog);
    }

    printf("Rekomendasi makanan : ");
    anyRecomm = false;
    for (i = 0; i < listLengthStat(resep); i++) {
        CreateSet(&setResep, katalog);
        recommended = CompareInvWTree(&setResep, inv, CHILD(TREE(ELMTSTAT(resep,i))), katalog);
        if (recommended) {
            if (i > 0) {
                printf(", ");
            }
            printString(Nama(MAKAN(TREE(ELMTSTAT(resep,i)))));
            anyRecomm = true;
        }
    }
    printf("\n");

    if (!anyRecomm) {
        printf("Tidak ada makanan yang bisa dibuat dengan bahan di inventory\n");
    }
}