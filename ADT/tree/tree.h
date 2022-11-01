/* File: tree.h */
/* Definisi N-Ary tree */

#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#include "../boolean.h"
#include "../makanan/makanan.h"

typedef struct node *Address;

typedef struct node {
    Makanan m;
    Address child;
    Address sibling;
} Node;

typedef Address Tree;

#define ROOT(T) (T)
#define MAKAN(T) (T)->m
#define CHILD(T) (T)->child
#define SIBLING(T) (T)->sibling

boolean isTreeEmpty(Tree T);
/* Mengembalikan true jika T kosong (ROOT(T) == NULL)*/

void CreateTree(Tree *T);
/* I.S. T sembarang */
/* F.S. Terbentuk Tree T yang kosong */

void AddSibling(Tree *T, Makanan sibling);
/* I.S. T terdefinisi */
/* F.S. sibling ditambahkan sebagai sibling dari T */

void AddChild(Tree *T, Makanan child);
/* I.S. T terdefinisi */
/* F.S. child ditambahkan sebagai salah satu children dari T */

void deleteTree(Tree *T);
/* I.S. T terdefinisi */
/* F.S. T menjadi tree kosong */

boolean isMakananInChild(Tree T, Makanan m);
/* Mengembalikan true jika m adalah child dari T */

Tree duplicateTree(Tree T);
/* Mengembalikan salinan Tree T */

Address searchMakananTree(Tree inT, Makanan m);
/* Mengembalikan Address yang value makanananya adalah m di dalam Tree inT, jika
 * ada */

void printTreeResep(Tree T);
/* I.S. T terdefinisi */
/* F.S. Keseluruhan Tree resep T tercetak ke layar */

#endif