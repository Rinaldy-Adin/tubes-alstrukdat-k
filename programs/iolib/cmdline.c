#include "cmdline.h"

void displayCurrentState(Matrix peta, Simulator sim, ListStatik listCatalog, Stack undoStack,
                         Stack redoStack, boolean isRedo) {
    int i, n_events, j;
    Simulator lastSim = InfoTop(redoStack);
    ListStatik eventStrings;
    String event, id;
    Makanan eventMakanan;
    POINT position = PositionSim(sim);

    printf("\n");
    printf("=========================================");
    printf("\n");
    printString(NamaSim(sim));
    printf(" di posisi: (%d,%d)", ROW(position) - 1, COL(position) - 1);
    printf("\n");
    printf("Waktu: %02d.%02d", Jam(TimeSim(sim)), Menit(TimeSim(sim)));
    printf("\n");
    printf("Notifikasi: ");

    if (((StackIsEmpty(redoStack) || isRedo) && isEmptyStat(EventsSim(sim)) ||
         ((!StackIsEmpty(redoStack) && !isRedo) && isEmptyStat(EventsSim(lastSim))))) {
        printf("-");
    } else {
        if (StackIsEmpty(redoStack) || isRedo) {
            n_events = NEFFSTAT(EventsSim(sim));
        } else {
            n_events = NEFFSTAT(EventsSim(lastSim));
        }

        j = 0;
        for (i = 0; i < n_events; i++) {
            if (StackIsEmpty(redoStack)) {
                eventStrings = splitString(STRING(ELMTSTAT(EventsSim(sim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Deliv"))) {
                    printf("\n");
                    printf("   %d. ", j + 1);
                    j++;

                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah diterima oleh ");
                    printString(NamaSim(sim));
                    printf("!");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    printf("\n");
                    printf("   %d. ", j + 1);
                    j++;

                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah kedaluarsa");
                }

            } else if (isRedo) {
                printf("\n");
                printf("   %d. ", j + 1);
                j++;

                eventStrings = splitString(STRING(ELMTSTAT(EventsSim(sim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Deliv"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah diterima oleh ");
                    printString(NamaSim(sim));
                    printf("!");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" sudah kedaluarsa");
                } else if (stringsAreEqual(event, createString("Buy"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pembelian ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Fry"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan penggorengan ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Mix"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pencampuran ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Boil"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan perebusan ");
                    printString(Nama(eventMakanan));

                } else if (stringsAreEqual(event, createString("Chop"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Dilakukan pemotongan ");
                    printString(Nama(eventMakanan));
                } else if (stringsAreEqual(event, createString("Ins"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dimasukkan ke dalam kulkas");
                } else if (stringsAreEqual(event, createString("Take"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" diambil dari kulkas");
                }
            } else {
                printf("\n");
                printf("   %d. ", j + 1);
                j++;

                eventStrings = splitString(STRING(ELMTSTAT(EventsSim(lastSim), i)));
                event = STRING(ELMTSTAT(eventStrings, 0));
                id = STRING(ELMTSTAT(eventStrings, 1));

                if (stringsAreEqual(event, createString("Buy"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pembelian ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Fry"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Penggorengan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Mix"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pencampuran ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Boil"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Perebusan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Chop"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printf("Pemotongan ");
                    printString(Nama(eventMakanan));
                    printf(" dibatalkan");
                } else if (stringsAreEqual(event, createString("Exp"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dikembalikan ke inventory");
                } else if (stringsAreEqual(event, createString("Deliv"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dihapus dari inventory");
                } else if (stringsAreEqual(event, createString("Ins"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dikembalikan ke inventory dari kulkas");
                } else if (stringsAreEqual(event, createString("Take"))) {
                    eventMakanan = MAKANAN(ELMTSTAT(listCatalog, indexOfMakanan(listCatalog, id)));
                    printString(Nama(eventMakanan));
                    printf(" dikembalikan ke ke kulkas");
                }
            }

            if (j == 0) {
                printf("-");
            }
        }
    }

    printf("\n");
    printf("\n");
    displayMatrix(peta);
    printf("\n");
}

int buyCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog) {
    /* KAMUS */
    ListStatik list;
    Makanan chosenMakanan;
    infotype inventoryItem;
    String eventStr, commandStr;
    ElTypeStat eType;
    int command;

    /* ALGORITMA */
    printf("=========================================\n");
    printf("=                   BUY                 =\n");
    printf("=========================================\n");
    list = listMakananCommand(createString("Buy"), listCatalog);

    printf("Kirim 0 untuk exit.\n\n");
    printf("Enter command: ");
    commandStr = removeLongSpaces(readLine());

    while (true) {
        if (stringIsIntParsable(commandStr)) {
            command = stringToInt(commandStr);
            if (command >= 0 && command <= NEFFSTAT(list))
                break;
        }
        printf("Masukkan command yang valid (angka 0 - %d)\n\n", NEFFSTAT(list));
        printf("Enter command: ");
        commandStr = removeLongSpaces(readLine());
        printf("\n");
    }

    if (command > 0) {
        chosenMakanan = MAKANAN(ELMTSTAT(list, command - 1));

        printf("Berhasil memesan ");
        printString(Nama(chosenMakanan));
        printf(". ");
        printString(Nama(chosenMakanan));
        printf(" akan diantar dalam ");
        TulisTIMEShort(DelTime(chosenMakanan));
        printf(".\n");

        delivery(&chosenMakanan, &DeliverySim(*nextSim));

        eventStr = createString("Buy");
        eventStr = concatString(eventStr, ID(chosenMakanan));

        STRING(eType) = eventStr;
        insertLastStat(&EventsSim(*nextSim), eType);

        return 1;
    }
    return -1;
}

int cookCommand(Simulator *sim, Simulator *nextSim, ListStatik listCatalog, ListStatik listResep,
                String cookMethod) {
    /* KAMUS */
    ListStatik list;
    Makanan chosenMakanan;
    infotype inventoryItem;
    ElTypeStat eType;
    String eventStr, commandStr;
    int command;
    boolean cookable;

    /* ALGORITMA */
    printf("=========================================\n");
    printf("=                   ");
    printString(cookMethod);
    printf("                 =\n");
    printf("=========================================\n");
    list = listMakananCommand(cookMethod, listCatalog);

    printf("Kirim 0 untuk exit.\n\n");
    printf("Enter command: ");
    commandStr = removeLongSpaces(readLine());
    printf("\n");

    while (true) {
        if (stringIsIntParsable(commandStr)) {
            command = stringToInt(commandStr);
            if (command >= 0 && command <= NEFFSTAT(list)) {
                if (command == 0) {
                    break;
                } else {
                    cookable = Cook(ID(MAKANAN(ELMTSTAT(list, command - 1))),
                                    &InventorySim(*nextSim), listResep);

                    if (cookable) {
                        break;
                    } else {
                        printf("\nEnter command: ");
                        commandStr = removeLongSpaces(readLine());
                        continue;
                    }
                }
            }
        }

        printf("Masukkan command yang valid (angka 0 - %d)\n\n", NEFFSTAT(list));
        printf("Enter command: ");
        commandStr = removeLongSpaces(readLine());
        printf("\n");
    }

    if (command > 0) {
        chosenMakanan = MAKANAN(ELMTSTAT(list, command - 1));

        printString(Nama(chosenMakanan));
        printf(" selesai dibuat dan sudah masuk ke inventory!\n");
        eventStr = concatString(cookMethod, ID(chosenMakanan));

        STRING(eType) = eventStr;
        insertLastStat(&EventsSim(*nextSim), eType);

        return TIMEToMenit(ActTime(chosenMakanan));
    }
    return -1;
}

int kulkasCommand(Simulator *sim, Simulator *nextSim) {
    /* KAMUS */
    ListStatik list;
    Makanan chosenMakanan;
    infotype inventoryItem;
    String eventStr, commandStr;
    ElTypeStat eType;
    int command;
    boolean correctCommand;

    /* ALGORITMA */
    displayKulkas(KulkasSim(*sim));
    printf("\n");
    printf("Enter command (INSERT/TAKE/EXIT): ");
    commandStr = removeLongSpaces(readLine());

    correctCommand = false;
    while (!stringsAreEqual(commandStr, createString("EXIT"))) {
        if (stringsAreEqual(commandStr, createString("INSERT"))) {
            displayInventory(InventorySim(*sim));
            correctCommand = true;

            if (NBElmt(InventorySim(*sim)) > 0) {
                printf("\nMasukkan nomor makanan yang ingin dimasukan ke kulkas: ");
                commandStr = removeLongSpaces(readLine());

                while (true) {
                    if (stringIsIntParsable(commandStr)) {
                        command = stringToInt(commandStr);
                        if (command >= 0 && command <= NBElmt(InventorySim(*sim)))
                            break;
                    }
                    displayInventory(InventorySim(*sim));
                    printf("\nMasukkan command yang valid (angka 0 - %d)\n\n",
                           NBElmt(InventorySim(*sim)));
                    printf("Masukkan nomor makanan yang ingin dimasukan ke kulkas: ");
                    commandStr = removeLongSpaces(readLine());
                }

                if (command > 0) {
                    deleteAtPQ(&InventorySim(*nextSim), &inventoryItem, command - 1);
                    insertToKulkas(inventoryItem, &KulkasSim(*nextSim));

                    printf("\nBerhasil memasukan ");
                    printString(Nama(Makanan(inventoryItem)));
                    printf(" ke dalam kulkas.\n");

                    eventStr = concatString(createString("Ins"), ID(Makanan(inventoryItem)));

                    STRING(eType) = eventStr;
                    insertLastStat(&EventsSim(*nextSim), eType);
                    return 1;
                }
            }
        } else if (stringsAreEqual(commandStr, createString("TAKE"))) {
            correctCommand = true;
            displayKulkas(KulkasSim(*sim));
            if (NBElmt(CONT(KulkasSim(*sim))) > 0) {
                printf("\n");
                printf("Masukkan nomor makanan yang ingin diambil dari kulkas: ");
                commandStr = removeLongSpaces(readLine());

                while (true) {
                    if (stringIsIntParsable(commandStr)) {
                        command = stringToInt(commandStr);
                        if (command >= 0 && command <= NBElmt(CONT(KulkasSim(*sim))))
                            break;
                    }
                    displayKulkas(KulkasSim(*sim));
                    printf("\n");
                    printf("Masukkan command yang valid (angka 0 - %d)\n\n",
                           NBElmt(CONT(KulkasSim(*sim))));
                    printf("\n");
                    printf("Masukkan nomor makanan yang ingin dimasukan k kulkas: ");
                    commandStr = removeLongSpaces(readLine());
                }

                if (command > 0) {
                    removeFromKulkas(&KulkasSim(*nextSim), command - 1, &inventoryItem);

                    Enqueue(&InventorySim(*nextSim), inventoryItem);

                    printf("\nBerhasil mengambil ");
                    printString(Nama(Makanan(inventoryItem)));
                    printf(" dari kulkas.\n");

                    eventStr = concatString(createString("Take"), ID(Makanan(inventoryItem)));

                    STRING(eType) = eventStr;
                    insertLastStat(&EventsSim(*nextSim), eType);
                    return 1;
                }
            }
        }
        displayKulkas(KulkasSim(*sim));
        printf("\n");
        if (!correctCommand)
            printf("Command yang dimasukkan salah\n\n");
        correctCommand = false;
        printf("Enter command (INSERT/TAKE/EXIT): ");
        commandStr = removeLongSpaces(readLine());
        printf("\n");
    }

    return -1;
}

void removeActions(Simulator *sim) {
    /* KAMUS */
    int i;
    ListStatik eventStrings;
    String event;
    ElTypeStat tmp;

    /* ALGORITMA */
    if (listLengthStat(EventsSim(*sim)) == 0)
        return;

    for (i = listLengthStat(EventsSim(*sim)) - 1; i >= 0; i--) {
        eventStrings = splitString(STRING(ELMTSTAT(EventsSim(*sim), i)));
        event = STRING(ELMTSTAT(eventStrings, 0));

        if (!(stringsAreEqual(event, createString("Deliv")) ||
              stringsAreEqual(event, createString("Exp")))) {
            deleteAtStat(&EventsSim(*sim), &tmp, i);
        }
    }
}

void undoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim, Stack *undoStack,
                 Stack *redoStack) {
    /* KAMUS */
    POINT oldPos;

    /* ALGOITMA */
    if (!StackIsEmpty(*undoStack)) {
        oldPos = PositionSim(*sim);
        Push(redoStack, *sim);
        Pop(undoStack, sim);
        moveTo(oldPos, PositionSim(*sim), peta);
        CopySimulator(*sim, nextSim);
        CreateListStatik(&EventsSim(*nextSim));
    } else {
        printf("Stack undo masih kosong. Belum ada aksi yang dilakukan.\n");
    }
}

void redoCommand(Matrix *peta, Simulator *sim, Simulator *nextSim, Stack *undoStack,
                 Stack *redoStack) {
    /* KAMUS */
    POINT oldPos;

    /* ALGORITMA */
    if (!StackIsEmpty(*redoStack)) {
        oldPos = PositionSim(*sim);
        Pop(redoStack, sim);
        Push(undoStack, *sim);
        moveTo(oldPos, PositionSim(*sim), peta);
        CopySimulator(*sim, nextSim);
        CreateListStatik(&EventsSim(*nextSim));
    } else {
        printf("Stack redo masih kosong. Belum ada aksi undo yang dilakukan.\n");
    }
}

void decrementSim(Simulator *sim, Simulator *nextSim, Stack *undoStack, Stack *redoStack,
                  int nMenit) {
    /* ALGORITMA */
    Push(undoStack, *sim);
    CreateEmptyStack(redoStack);

    TimeSim(*nextSim) = NextNMenit(TimeSim(*nextSim), nMenit);
    decrementTime(&DeliverySim(*nextSim), &InventorySim(*nextSim), &EventsSim(*nextSim), nMenit);

    CopySimulator(*nextSim, sim);
    CreateListStatik(&EventsSim(*nextSim));
}

void initializeSimulator(Simulator *sim, Matrix peta) {
    /* KAMUS */
    String nama;
    POINT pos;
    PrioQueue inventory, delivery;
    ListStatik events;
    TIME time;
    Kulkas kulkas;

    /* ALGORITMA */
    pos = currentPosition(peta);
    MakeEmpty(&inventory, 50);
    MakeEmpty(&delivery, 50);
    CreateTime(&time, 0, 0, 0);
    CreateListStatik(&events);
    createEmptyKulkas(&kulkas);

    printf("\n");
    printf("=========================================");
    printf("\n\n");
    printf("Masukkan nama anda : ");
    nama = readLine();
    nama = removeLongSpaces(nama);

    CreateSimulator(sim, nama, pos, time, inventory, delivery, events, kulkas);
}
