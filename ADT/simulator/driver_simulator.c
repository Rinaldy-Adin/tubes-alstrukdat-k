#include "../../programs/makanan/inventory.h"
#include "../../programs/makanan/order.h"
#include "simulator.h"

int main() {
    /* KAMUS */
    Simulator sim, copySim;
    POINT loc;
    PrioQueue inventory, delivery;
    ListStatik events;
    TIME t;
    Makanan testM;
    infotype ifM;

    /* ALGORITMA */
    printf("========== MEMBUAT SIMULATOR BARU ==========\n");
    CreatePoint(&loc, 1, 1);
    CreateTime(&t, 1, 1, 1);
    MakeEmpty(&inventory, 100);
    MakeEmpty(&delivery, 100);
    CreateListStatik(&events);
    CreateSimulator(&sim, createString("BNMO"), loc, t, inventory, delivery,
                    events);
    printf("Nama Simulator : ");
    printString(NamaSim(sim));
    printf("\n");
    printf("Lokasi Simulator : ");
    TulisPOINT(PositionSim(sim));
    printf("\n");
    printf("Waktu Simulator : ");
    TulisTIME(TimeSim(sim));
    printf("\n");
    printf("\n");

    printf("========== MEMBUAT SALINAN SIMULATOR ==========\n");
    CopySimulator(sim, &copySim);
    printf("Dilakukan perubahan variabel pada simulator salinan\n");
    NamaSim(copySim) = createString("OMNB");
    CreatePoint(&PositionSim(copySim), 2, 2);
    CreateTime(&TimeSim(copySim), 2, 2, 2);
    CreateTime(&t, 10, 10, 10);
    makeMakanan(&testM, createString("100"), createString("Makanan test"), t, t,
                t, createString("Buy"), 10, 10);
    Makanan(ifM) = testM;
    Time(ifM) = t;
    Enqueue(&InventorySim(copySim), ifM);
    Enqueue(&DeliverySim(copySim), ifM);

    printf("=== SIMULATOR SALINAN ===\n");
    printf("Nama Simulator Salinan : ");
    printString(NamaSim(copySim));
    printf("\n");
    printf("Lokasi Simulator Salinan : ");
    TulisPOINT(PositionSim(copySim));
    printf("\n");
    printf("Waktu Simulator Salinan : ");
    TulisTIME(TimeSim(copySim));
    printf("\n");
    printf("Inventory Simulator Salinan : ");
    printf("\n");
    displayInventory(InventorySim(copySim));
    printf("\n");
    printf("Delivery Simulator Salinan : ");
    printf("\n");
    displayDelivery(DeliverySim(copySim));
    printf("\n");
    printf("\n");

    printf("=== SIMULATOR AWAL ===\n");
    printf("Nama Simulator : ");
    printString(NamaSim(sim));
    printf("\n");
    printf("Lokasi Simulator : ");
    TulisPOINT(PositionSim(sim));
    printf("\n");
    printf("Waktu Simulator : ");
    TulisTIME(TimeSim(sim));
    printf("\n");
    printf("Inventory Simulator : ");
    printf("\n");
    displayInventory(InventorySim(sim));
    printf("\n");
    printf("Delivery Simulator : ");
    printf("\n");
    displayDelivery(DeliverySim(sim));
    printf("\n");
    printf("\n");
}