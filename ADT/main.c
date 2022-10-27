#include "listStatik.h"

int main() {
    /* KAMUS */
    ListStatik testMakan;

    /* ALGORITMA */
    printf("%d\n", indexOfStat(testMakan,ID(MAKANAN(ELMTSTAT(testMakan,4)))));
    loadMakanan(&testMakan);
    printListStat(testMakan);
}