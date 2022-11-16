#include "../../ADT/liststatik/listStatik.h"
#include "../../ADT/matrix/matrix.h"
#include "../../ADT/prioqueue/prioqueue.h"
#include "cmdline.h"

int main() {
    Matrix peta;
    ListStatik listCatalog;
    ListStatik listResep;
    loadMakanan(&listCatalog, "pita.txt");
    loadResep(&listResep, listCatalog, "pitaResep.txt");
    readPetaFromFile(&peta, "peta.txt");
    commandLineCycle(peta, listCatalog, listResep);

    return 0;
}