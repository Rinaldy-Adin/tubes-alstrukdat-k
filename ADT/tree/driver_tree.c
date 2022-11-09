#include <stdio.h>
#include "tree.h"

int main() {
    Tree TestT, TestT2;
    Address p;
    Makanan testM;
    TIME t;

    printf("========== MEMBUAT TREE KOSONG ==========\n");
    printf("Tidak menghasilkan output, hanya membuat Tree kosong\n\n");
    CreateTree(&TestT);

    printf("========== MENGECEK APAKAH TREE KOSONG ==========\n");
    if (isTreeEmpty(TestT)) {
        printf("Tree kosong\n\n");
    } else {
        printf("Tree tidak kosong\n\n");
    }

    printf("========== MENAMBAH CHILD BARU DAN SIBLING BARU (Sekaligus fungsi newNode dan printTree (tidak digunakan)) ==========\n");
    makeMakanan(&testM, createString("99"), createString("Makanan test 2"), t, t, t, createString("Buy"), 10, 10);
    printf("Menambah root dan child pertama\n");
    AddChild(&TestT, testM);
    AddChild(&TestT, testM);
    printTree(TestT);
    printf("Menambah sibling ke root\n");
    AddSibling(&TestT, testM);
    printTree(TestT);
    printf("Menambah child kedua root\n");
    AddChild(&TestT, testM);
    printTree(TestT);
    printf("\n");

    printf("========== MEMBUAT DUPLIKAT TREE ==========\n");
    TestT2 = duplicateTree(TestT);
    printf("Tree duplikat :\n");
    printTree(TestT2);

    printf("========== MENGHAPUS SELURUH TREE ==========\n");
    deleteTree(&TestT);
    printf("Tree yang dihapus :\n");
    printTree(TestT);
    printf("\n");

    printf("========== SEARCHING ADDRESS MAKANAN PADA TREE ==========\n");
    p = searchMakananTree(TestT2, testM);
    printf("ID makanan yang ditemukan : ");
    printString(ID(MAKAN(p)));
    printf("\n\n");
}