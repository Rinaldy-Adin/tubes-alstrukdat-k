#include "charmachine.h"

int main() {
    printf("========== START ==========\n");
    START();
    printf("currentChar = %c\n\n", currentChar);
    printf("========== ADV ==========\n");
    ADV();
    printf("currentChar = %c\n\n", currentChar);
    printf("========== STARTFILE pita.txt ==========\n");
    STARTFILE("../../pita.txt");
    printf("currentChar = %c\n\n", currentChar);
    printf("========== ADV ==========\n");
    ADV();
    printf("currentChar = %c\n\n", currentChar);    
    printf("========== ADV ==========\n");
    ADV();
    printf("currentChar = %c\n\n", currentChar); 
    printf("========== CEK EOP ==========\n");
    if (EOP) {
        printf("EOP\n\n");
    }
    else {
        printf("Belum EOP\n\n");
    }
    return 0;
}