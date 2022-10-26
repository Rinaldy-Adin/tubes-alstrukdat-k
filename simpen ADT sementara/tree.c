//
// Created by ammar on 24/10/2022.
//

#include "tree.h"

void CreateTree(Tree *T, Makanan m, int count)
{
    /* Membuat tree. Jika count = 0 maka sama seperti membuat node tanpa ada children. */
    int i = 0;
    Makanan(*T) = m;
    if (count > 0) {
        CreateListDin(&Child(*T), count);
    }
}

void AddChild(Tree *T, Tree child) {
    /* Menambahkan child yang terdefinisi ke tree yang terdefinisi. */
    ElType elmt;
    elmt.t = child;
    if (CAPACITY(Child(*T)) == 0) {
        CreateListDin(&Child(*T), 1);
    }
    insertLast(&Child(*T), elmt);
}