#include "./ADT/liststatik/listStatik.h"
#include "./ADT/matrix/matrix.h"
#include "./ADT/prioqueue/prioqueue.h"
#include "./programs/iolib/cmdline.h"

int main() {
    Matrix peta;
    ListStatik listCatalog;
    ListStatik listResep;
    loadMakanan(&listCatalog);
    loadResep(&listResep, listCatalog);
    readPetaFromFile(&peta, "peta.txt");
    commandLineCycle(peta, listCatalog, listResep);

    return 0;
}