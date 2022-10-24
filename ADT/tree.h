/* File: tree.h */
/* Definisi N-Ary tree */

#ifndef TREE_H
#define TREE_H

#include "boolean.h"
#include "listdin.h"
#include "makanan.h"

typedef struct
{
    Makanan m; // Makanan sebagai node
    ListDin children; // Array penampung children
} Tree;


#endif