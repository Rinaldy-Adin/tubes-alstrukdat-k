#include "wordmachine.h"

int main() {
    printf("========== STARTWORD ==========\n");
    STARTWORD();
    printf("currentWord = %s\n\n", currentWord);
    printf("========== ADVWORD ==========\n");
    ADVWORD();
    printf("currentWord = %s\n\n", currentWord);    
    printf("========== CEK EOP ==========\n");
    if (EOP) {
        printf("EOP\n\n");
    }
    else {
        printf("BELUM EOP\n\n");
    }
    printf("========== STARTWORDFILE pita.txt ==========\n");
    STARTWORDFILE("../../pita.txt");
    printf("currentWord = %s\n\n", currentWord);
    printf("========== ADVWORD ==========\n");
    ADVWORD();
    printf("currentWord = %s\n\n", currentWord); 
    return 0;
}