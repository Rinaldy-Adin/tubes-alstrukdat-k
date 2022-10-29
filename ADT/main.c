#include "listStatik.h"

int main() {
    /* KAMUS */
    ListStatik testMakan;
    ListStatik testResep;
    Tree test;
    Address alamatMakanan;

    /* ALGORITMA */
    // printf("%d\n", indexOfStat(testMakan,ID(MAKANAN(ELMTSTAT(testMakan,4)))));
    loadMakanan(&testMakan);
    // printListStat(testMakan);

    loadResep(&testResep,testMakan);
    printResep(testResep);
    // CreateTree(&test);
    // for (int i=0; i<NEFFSTAT(testMakan); i++) {
    //     AddChild(&test,MAKANAN(ELMTSTAT(testMakan,i)));
    // }
    // deleteTree(&test);
    // printTree(test);
}