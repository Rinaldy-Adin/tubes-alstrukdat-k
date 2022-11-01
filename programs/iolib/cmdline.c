#include "cmdline.h"

void displayCurrentState(Matrix peta, Simulator sim) {
    POINT position = PositionSim(sim);

    printf("\n");
    printf("========================================");
    printf("\n");
    printf("BNMO di posisi: (%d,%d)", ROW(position) - 1, COL(position) - 1);
    printf("\n");
    printf("Waktu: %02d.%02d", Jam(TimeSim(sim)), Menit(TimeSim(sim)));
    printf("\n");
    printf("Notifikasi: ");
    printf("\n");
    printf("\n");
    displayMatrix(peta);
    printf("\n");
}

// Run command based on input
void runCommand(Matrix *peta, Simulator *sim, String command) {
    String mv_north = createString("MOVE NORTH");
    String mv_east = createString("MOVE EAST");
    String mv_south = createString("MOVE SOUTH");
    String mv_west = createString("MOVE WEST");

    if (stringsAreEqual(command, mv_north)) {
        move(&PositionSim(*sim), peta, 'N');
        TimeSim(*sim) = NextMenit(TimeSim(*sim));
    } else if (stringsAreEqual(command, mv_east)) {
        move(&PositionSim(*sim), peta, 'E');
        TimeSim(*sim) = NextMenit(TimeSim(*sim));
    } else if (stringsAreEqual(command, mv_south)) {
        move(&PositionSim(*sim), peta, 'S');
        TimeSim(*sim) = NextMenit(TimeSim(*sim));
    } else if (stringsAreEqual(command, mv_west)) {
        move(&PositionSim(*sim), peta, 'W');
        TimeSim(*sim) = NextMenit(TimeSim(*sim));
    } else {
        printf("command salah");
    }
}

void initializeSimulator(Simulator *sim, Matrix peta) {
    /* KAMUS */
    String nama;
    POINT pos;
    PrioQueue inventory;
    TIME time;

    /* ALGORITMA */
    pos = currentPosition(peta);
    printf("Posisi saat ini: (%d,%d)\n\n", ROW(pos) - 1, COL(pos) - 1);
    MakeEmpty(&inventory, 100);
    CreateTime(&time, 0, 0, 0);

    printf("\n");
    printf("========================================");
    printf("\n\n");
    printf("Masukkan nama anda : ");
    nama = readLine();
    nama = removeLongSpaces(nama);

    CreateSimulator(sim, nama, pos, time, inventory);
}

/* Run command line until user enters "EXIT" command */
void commandLineCycle(Matrix peta) {
    /* KAMUS */
    String command, exit, start;
    Simulator simulator;
    boolean started;

    /* ALGORITMA */
    command = createString("");
    exit = createString("EXIT");
    start = createString("START");

    // splashScreen();

    printf("Enter command: ");
    START();
    started = false;
    while (!endWord) {
        if (!started) {
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, start)) {
                initializeSimulator(&simulator, peta);
                started = true;
            } else if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                printf("Enter command: ");
            }
        } else {
            displayCurrentState(peta, simulator);

            printf("Enter command: ");
            command = readLine();
            command = removeLongSpaces(command);
            if (stringsAreEqual(command, exit)) {
                endWord = true;
            } else {
                runCommand(&peta, &simulator, command);
            }
        }
    }
}