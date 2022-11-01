#include "../../ADT/matrix/matrix.h"
#include "cmdline.h"

int main() {
    Matrix peta;
    readPetaFromFile(&peta, "peta.txt");
    commandLineCycle(peta);

    return 0;
}