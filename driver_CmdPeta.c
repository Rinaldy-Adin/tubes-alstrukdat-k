#include "cmdPeta.h"

int main() {
    Matrix test;
    POINT position;

    readPetaFromFile(&test, "peta.txt");
    position = currentPosition(test);
    printf("========== KEADAAN AWAL ========== \n");
    displayMatrix(test);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(position)-1, COL(position)-1);

    printf("========== MOVE EAST ========== \n");
    move(&position, &test, 'E');
    displayMatrix(test);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(position)-1, COL(position)-1);

    printf("========== MOVE NORTH ========== \n");
    move(&position, &test, 'N');
    displayMatrix(test);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(position)-1, COL(position)-1);

    printf("========== MOVE SOUTH ========== \n");
    move(&position, &test, 'S');
    displayMatrix(test);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(position)-1, COL(position)-1);

    printf("========== CEK ADJACENT DENGAN TEMPAT MIXING (M) ==========\n");
    if (isAdjacent(position, test, 'M')) {
        printf("Simulator bersebelahan dengan tempat mixing\n\n");
    }
    else {
        printf("Simulator tidak bersebelahan dengan tempat mixing\n\n");
    }
    
    printf("========== MOVE WEST ========== \n");
    move(&position, &test, 'W');
    displayMatrix(test);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(position)-1, COL(position)-1);

    printf("========== CEK ADJACENT DENGAN TEMPAT MIXING (M) ==========\n");
    if (isAdjacent(position, test, 'M')) {
        printf("Simulator bersebelahan dengan tempat mixing\n");
    }
    else {
        printf("Simulator tidak bersebelahan dengan tempat mixing\n");
    }
    /*
    * * * * * * * * * * * *
    * S                   *
    *         T     X     *
    *   M           X     *
    *               X     *
    *         X X X X     *
    *   X                 *
    *   X              C  *
    *   X X X     F       *
    *                     *
    *             B       *
    * * * * * * * * * * * *
    */
}