#include "prioqueue.h"

int main() {
    PrioQueue Q;
    MakeEmpty(&Q, 10);
    printf("%d\n", MaxEl(Q));
    printf("%d\n", NBElmt(Q));
    printf("%s\n", IsEmpty(Q) ? "true" : "false");
    printf("%s\n", IsFull(Q) ? "true" : "false");

    infotype X;
    Makanan testM;

    Time(X) = MenitToTIME(10);
    Makanan(X) = testM;
    Enqueue(&Q, X);
    printf("%d\n", NBElmt(Q));
    printf("%s\n", IsEmpty(Q) ? "true" : "false");
    printf("%s\n", IsFull(Q) ? "true" : "false");
    Dequeue(&Q, &X);
    Enqueue(&Q, X);
    printf("%d\n", idxInventory(Q, testM));
    DeAlokasi(&Q);
    printf("%d\n", MaxEl(Q));
    printf("%d\n", NBElmt(Q));
    return 0;
}
