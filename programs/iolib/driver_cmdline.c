#include "cmdline.h"
#include "../../ADT/matrix.h"

int main() {
    Matrix peta;
    readPetaFromFile(&peta, "peta.txt");
    commandLineCycle(peta);

    return 0;
}