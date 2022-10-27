/* File: node.h */
/* Definisi ADT Node */

#ifndef NODE_H
#define NODE_H

#include "boolean.h"
#include "makanan.h"
#include "listdin.h"

typedef struct
{
    Makanan m; // Makanan sebagai node
    ListDin children; // Array penampung children
} Node;

#endif