#include "listStatik.h"
#include "prioqueue.h"

int main() {
    /* KAMUS */
    ListStatik testMakan;
    ListStatik testResep;
    ListStatik testMasak;
    Tree test;
    Address alamatMakanan;
    PrioQueue q;
    infotype bahan;
    boolean found;

    /* ALGORITMA */
    // printf("%d\n", indexOfMakanan(testMakan,ID(MAKANAN(ELMTSTAT(testMakan,4)))));
    loadMakanan(&testMakan);
    printListMakanan(testMakan);

    loadResep(&testResep,testMakan);
    printResep(testResep);

    testMasak = listMakananCommand(createString("Fry"),testMakan);
    testMasak = listMakananCommand(createString("Mix"),testMakan);
    testMasak = listMakananCommand(createString("Chop"),testMakan);
    testMasak = listMakananCommand(createString("Boil"),testMakan);

    MakeEmpty(&q,20);
    for (int i=0; i<NEFFSTAT(testMakan); i++) {
        Makanan(bahan) = MAKANAN(ELMTSTAT(testMakan,i));
        Time(bahan) = Kadal(Makanan(bahan));
        Enqueue(&q, bahan);
    }
    printf("Isi inventory\n");
    for (int i=0; i<NBElmt(q); i++) {
        printString(Nama(Makanan(q.T[i])));
        printf(", ");
    }

    printf("\n\n");
    printf("Masak makanan : ");
    printString(Nama(MAKANAN(ELMTSTAT(testMasak,1))));
    printf("\n");
    found = Cook(ID(MAKANAN(ELMTSTAT(testMasak,1))), &q, testResep);
    printf("%d\n", found);
    
    printf("Isi inventory\n");
    for (int i=0; i<NBElmt(q); i++) {
        printString(Nama(Makanan(q.T[i])));
        printf(", ");
    }

    printf("\n\n");
    printf("Masak makanan : ");
    printString(Nama(MAKANAN(ELMTSTAT(testMasak,1))));
    printf("\n");
    found = Cook(ID(MAKANAN(ELMTSTAT(testMasak,1))), &q, testResep);
    printf("%d\n", found);

    // CreateTree(&test);
    // for (int i=0; i<NEFFSTAT(testMakan); i++) {
    //     AddChild(&test,MAKANAN(ELMTSTAT(testMakan,i)));
    // }
    // deleteTree(&test);
    // printTree(test);
}