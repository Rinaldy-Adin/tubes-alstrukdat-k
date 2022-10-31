#include "mathops.h"

int power(int x, int y) {
    /* KAMUS */
    int res;

    /* ALGORITMA */
    res = 1;
    while (y > 0) {
        res *= x;
        y--;
    }
    return res;
}
/* Mengembalikan hasil dari x^y */