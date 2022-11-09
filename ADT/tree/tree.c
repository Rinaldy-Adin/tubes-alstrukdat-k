//
// Created by ammar on 24/10/2022.
//

#include "tree.h"

Address newNode(Makanan m) {
    /* Membuat node baru dengan isi Makanan m */
    /* KAMUS LOKAL */
    Address t;

    /* ALGORITMA */
    t = (Address) malloc(sizeof(Node));
    if (t != NULL) {
        MAKAN(t) = m;
        CHILD(t) = NULL;
        SIBLING(t) = NULL;
    }
    return t;
}

boolean isTreeEmpty(Tree T) {
    /* Mengembalikan true jika T kosong (ROOT(T) == NULL)*/
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (ROOT(T) == NULL);
}

void CreateTree(Tree *T)
{
    /* I.S. T sembarang */
    /* F.S. Terbentuk Tree T yang kosong */
    /* KAMUS LOKAL */
    Address t;

    /* ALGORITMA */
    ROOT(*T) = NULL;
}

void AddSibling(Tree *T, Makanan sibling) {
    /* I.S. T terdefinisi */
    /* F.S. sibling ditambahkan sebagai sibling dari T */
    /* KAMUS LOKAL */
    Address s;

    /* ALGORITMA */
    if (SIBLING(*T) != NULL) {
        AddSibling(&SIBLING(*T), sibling);
    } else {
        s = newNode(sibling);
        if (s != NULL) {
            SIBLING(*T) = s;
        }
    }
}

void AddChild(Tree *T, Makanan child) {
    /* I.S. T terdefinisi */
    /* F.S. child ditambahkan sebagai salah satu children dari T */
    /* KAMUS LOKAL */
    Address c;

    /* ALGORITMA */
    if (isTreeEmpty(*T)) {
        c = newNode(child);
        if (c != NULL) {
            ROOT(*T) = c;
        }
    }
    else if (CHILD(*T) != NULL) {
        AddSibling(&CHILD(*T), child);
    } else {
        c = newNode(child);
        if (c != NULL) {
            CHILD(*T) = c;
        }
    }
}

void deleteTree(Tree *T) {
    /* I.S. T terdefinisi */
    /* F.S. T menjadi tree kosong */
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    if (ROOT(*T) == NULL) {
        return;
    }
    p = ROOT(*T);
    deleteTree(&CHILD(*T));
    deleteTree(&SIBLING(*T));
    ROOT(*T) = NULL;
    free(p);
}

Tree duplicateTree(Tree T) {
    /* Mengembalikan salinan Tree T */
    /* KAMUS LOKAL */
    Tree dup;

    /* ALGORITMA */
    if(isTreeEmpty(T)) {
        return NULL;
    }
    else {
        CreateTree(&dup);
        AddChild(&dup, MAKAN(ROOT(T)));
        SIBLING(dup) = duplicateTree(SIBLING(T));
        CHILD(dup) = duplicateTree(CHILD(T));
        return dup;
    }
}

Address searchMakananTree(Tree inT, Makanan m) {
    /* Mengembalikan Address yang value makanananya adalah m di dalam Tree inT, jika ada. Jika tidak ada, mengembalikan NULL */
    /* Sumber : https://stackoverflow.com/questions/37209346/search-for-an-item-in-an-n-ary-tree */
    /* KAMUS LOKAL */
    Address temp;

    /* ALGORITMA */
    if (isTreeEmpty(inT)) // Basis 0
        return NULL;
    if (isMakananEqual(MAKAN(inT), m)) // Basis 1 (ditemukan)
        return inT;
    // Cari dari sibling dulu
    temp = searchMakananTree(SIBLING(inT), m);
    if (temp != NULL)
        return temp;
    // Cari dari child
    return searchMakananTree(CHILD(inT),m);
}


void printTree(Tree T) {
    /* I.S. T terdefinisi */
    /* F.S. Keseluruhan Tree resep T tercetak ke layar */
    /* KAMUS LOKAL */
    Address t;

    /* ALGORITMA */
    if (isTreeEmpty(T)) {
        printf("Tree kosong\n");
    }
    else {
        t = T;
        printString(Nama(MAKAN(t)));
        if (SIBLING(T) != NULL) {
            printf(", ");
            printTree(SIBLING(T));
        }
        if (CHILD(T) != NULL) {
            printf("\n");
            printString(Nama(MAKAN(t)));
            printf(" punya child : ");
            printTree(CHILD(T));
        }
        printf("\n");
    }
}