#include "listMakanan.c"

int main() {
    /* KAMUS */
    ListMakanan testMakan;

    /* ALGORITMA */
    loadMakanan(&testMakan);
    printList(testMakan);
}