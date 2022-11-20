#include "../../programs/makanan/inventory.h"
#include "../../programs/makanan/order.h"
#include "stack.h"

int main() {
    /* KAMUS */
    Simulator sim, copySim;
    POINT loc;
    PrioQueue inventory, delivery;
    ListStatik events;
    TIME t;
    Makanan testM;
    infotype ifM;
    Kulkas kulkas;

    Stack s;

    /* ALGORITMA */
    CreatePoint(&loc, 1, 1);
    CreateTime(&t, 1, 1, 1);
    MakeEmpty(&inventory, 100);
    MakeEmpty(&delivery, 100);
    CreateListStatik(&events);
    createEmptyKulkas(&kulkas);
    CreateSimulator(&sim, createString("BNMO"), loc, t, inventory, delivery, events, kulkas);

    CopySimulator(sim, &copySim);
    printf("Dilakukan perubahan variabel pada simulator salinan\n");
    NamaSim(copySim) = createString("OMNB");
    CreatePoint(&PositionSim(copySim), 2, 2);
    CreateTime(&TimeSim(copySim), 2, 2, 2);
    CreateTime(&t, 10, 10, 10);
    makeMakanan(&testM, createString("100"), createString("Makanan test"), t, t, t,
                createString("Buy"), 10, 10);
    Makanan(ifM) = testM;
    Time(ifM) = t;
    Enqueue(&InventorySim(copySim), ifM);
    Enqueue(&DeliverySim(copySim), ifM);

    printf("========== MEMBUAT STACK BARU ==========\n");
    CreateEmptyStack(&s);
    if (StackIsEmpty(s))
        printf("Stack masih kosong\n");
    printf("Ukuran stack: %d\n", stackSize(s));
    printf("\n");

    printf("========== MENAMBAH ELEMEN BARU ==========\n");
    Push(&s, sim);
    Push(&s, copySim);
    if (!StackIsEmpty(s))
        printf("Stack tidak kosong\n");
    printf("Ukuran stack: %d\n", stackSize(s));
    printf("\n");

    printf("=== ELEMEN SIMULATOR TERATAS ===\n");
    printf("Nama Simulator: ");
    printString(NamaSim(InfoTop(s)));
    printf("\n");
    printf("Lokasi Simulator : ");
    TulisPOINT(PositionSim(InfoTop(s)));
    printf("\n");
    printf("Waktu Simulator : ");
    TulisTIME(TimeSim(InfoTop(s)));
    printf("\n");
    printf("Inventory Simulator : ");
    printf("\n");
    displayInventory(InventorySim(InfoTop(s)));
    printf("\n");
    printf("Delivery Simulator : ");
    printf("\n");
    displayDelivery(DeliverySim(InfoTop(s)));
    printf("\n");
    printf("\n");

    printf("========== MENGAMBIL ELEMEN TERATAS ==========\n");
    Pop(&s, &sim);
    if (!StackIsEmpty(s))
        printf("Stack tidak kosong\n");
    printf("Ukuran stack: %d\n", stackSize(s));
    printf("\n");

    printf("=== ELEMEN SIMULATOR TERATAS ===\n");
    printf("Nama Simulator: ");
    printString(NamaSim(InfoTop(s)));
    printf("\n");
    printf("Lokasi Simulator : ");
    TulisPOINT(PositionSim(InfoTop(s)));
    printf("\n");
    printf("Waktu Simulator : ");
    TulisTIME(TimeSim(InfoTop(s)));
    printf("\n");
    printf("Inventory Simulator : ");
    printf("\n");
    displayInventory(InventorySim(InfoTop(s)));
    printf("\n");
    printf("Delivery Simulator : ");
    printf("\n");
    displayDelivery(DeliverySim(InfoTop(s)));
    printf("\n");
    printf("\n");

    return 0;
}