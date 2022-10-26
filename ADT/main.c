#include "listMakanan.h"

int main() {
    /* KAMUS */
    ListMakanan testMakan;

    /* ALGORITMA */
    loadMakanan(&testMakan);
    printListStat(testMakan);
}