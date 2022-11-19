#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks() {
    /* Algoritma */
    while (currentChar == BLANK || currentChar == NEWLINE || currentChar == CARRETURN) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD() {
    /* Algoritma */
    START();
    endWord = false;
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *filename) {
    /* Algoritma */
    STARTFILE(filename);
    endWord = false;
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        CopyWord();
    }
}

/* I.S. : currentChar sembarang, file dengan nama filename ada
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord() {
    /* Kamus */
    int i;

    /* Algoritma */
    // Kosongkan TabWord currentWord
    i = 0;
    while (currentWord.TabWord[i] != '\0') {
        currentWord.TabWord[i] = '\0';
        i++;
    }
    currentWord.Length = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE &&
           currentChar != CARRETURN && currentWord.Length < NMax) {
        currentWord.TabWord[currentWord.Length] = currentChar;
        currentWord.Length++;
        ADV();
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */