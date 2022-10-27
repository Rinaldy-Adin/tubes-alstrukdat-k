/* File: tree.h */
/* Definisi N-Ary tree */

#ifndef TREE_H
#define TREE_H

#include "boolean.h"
#include "makanan.h"
#include "node.h"

typedef Node Tree;

#define Makanan(P) (P).m
#define Child(P) (P).children

void CreateTree(Tree *T, Makanan m, int count);
/* I.S. T sembarang */
/* F.S. T terdefinisi dengan makanan m sebagai root dan count sebagai jumlah children */

void AddChild(Tree *T, Tree child);
/* I.S. T dan child terdefinisi */
/* F.S. T ditambahkan dengan node child */

#endif