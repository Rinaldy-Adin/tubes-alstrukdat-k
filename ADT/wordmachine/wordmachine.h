#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>

#include "../boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'
#define CARRETURN '\r'

typedef struct {
    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai
                           [0..NMax-1] */
    int Length;
} Word;

#define WordLength(W) (W).Length
#define CharAt(W, idx) (W).TabWord[idx]

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *filename);
/* I.S. : currentChar sembarang, file dengan nama filename ada
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void duplicateWord(Word *word1, Word *word2);
/* Duplicate word1 into word2 */

int wordToInt(Word w);
/* Mengubah Word w menjadi integer */

#endif