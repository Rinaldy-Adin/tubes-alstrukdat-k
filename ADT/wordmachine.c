/* File: wordmachine.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 25 September 2022 */
/* Topik praktikum: ADT ADT Mesin Kata */
/* Deskripsi: implementasi ADT ADT Mesin Kata */

#include "wordmachine.h"
#include "stdlib.h"

Word currentWord;
boolean endWord;

// boolean isWordFull(Word w) {
//     /* Menentukan apakah Word w kapasitasnya sudah penuh */
//     /* KAMUS LOKAL */

//     /* ALGORITMA */
//     return(w.TabWord[w.Length-1] != NULL);
// }

// void expandWord(Word *w) {
//     /* Menambah ukuran array penampung kata. Hanya dipakai saat w penuh */
//     /* KAMUS LOKAL */
//     Word wCopy;
//     int i;

//     /* ALGORITMA */
//     wCopy.TabWord = (char *) malloc((*w).Length*sizeof(char));
//     wCopy.Length = (*w).Length;
//     for (i=0; i<(*w).Length; i++) {
//         wCopy.TabWord[i] = (*w).TabWord[i];
//     }
//     free((*w).TabWord);
//     (*w).TabWord = (char *) malloc(wCopy.Length * 2 * sizeof(char));
//     for (i=0; i<wCopy.Length; i++) {
//         (*w).TabWord[i] = wCopy.TabWord[i];
//     }
// }

void IgnoreBlanks() {
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    while (currentChar == BLANK) {
        ADV();
    }
    while (currentChar == NEWLINE) {
        ADVNewline();
    }
}


void STARTWORD(char* filename) {
    /* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    START(filename);
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    }
    else {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    }
    else {
        CopyWord();
    }
}

void CopyWord() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = NEWLINE atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    i = 0;
    while  (currentChar != MARK && currentChar != NEWLINE && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

/* FUNGSI KONVERSI WORD KE BENTUK LAIN */
int wordToInt(Word w) {
    /* Mengubah Word w menjadi int. Diasumsikan w hanya berisi angka. Jika kosong diasumsikan nilainya 0. */
    /* KAMUS LOKAL */
    int i;
    int result;

    /* ALGORITMA */
    result = 0;
    for (i=0; i<w.Length; i++) {
         if (i > 0) {
            result *= 10;
         }
         result += ((int) (w.TabWord[i]) - '0');
    }
    return result;
}

TIME wordToTime (Word w) {
    /* Mengubah Word w menjadi TIME. Diasumsikan w ada dalam format D H M */
    /* KAMUS LOKAL */
    int i, j, ctr, d, h, m;
    Word bil; // Word lebih kecil untuk penampung angka per bagian (D,H,M)
    TIME t;

    /* ALGORITMA */
    i = 0;
    ctr = 0;
    while (i < w.Length) {
        j = 0;
        while(w.TabWord[i] != ' ' && i < w.Length) {
            bil.TabWord[j] = w.TabWord[i];
            i++;
            j++;
        }
        bil.Length = j;
        if (ctr == 0) { // Untuk hari
            d = wordToInt(bil);
        }
        else if (ctr == 1) { // Untuk jam
            h = wordToInt(bil);
        }
        else { // Untuk menit
            m = wordToInt(bil);
        }
        ctr++;
        i++;
    }   
    CreateTime(&t,d,h,m);
    return t;
}

boolean isWordEqual(Word w1, Word w2) {
    /* Mengecek apakah Word w1 dan w2 sama */
    /* KAMUS LOKAL */
    boolean isEqual;
    int i;

    /* ALGORITMA */
    if (w1.Length != w2.Length) {
        isEqual = false;
    }
    else {
        isEqual = true;
        i = 0;
        while (i < w1.Length && isEqual) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                isEqual = false;
            }
            else {
                i++;
            }
        }
    }
    return isEqual;
}
void printWord (Word w) {
    /* I.S. w terdefinisi */
    /* F.S. w tercetak ke layar */
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i=0; i<w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}

char* readWord(Word w) {
    /* Mengembalikan (null terminated) string dari Word w */
    /* KAMUS LOKAL */
    int i;
    char* str;
    /* ALGORITMA */
    str = (char*) malloc((w.Length + 1) * sizeof(char));
    for (i = 0; i < w.Length; i++) {
        str[i] = w.TabWord[i];
    }
    str[w.Length] = '\0';
    return str;
}

boolean wordCmp(Word w1, Word w2) {
    /* Mengembalikan true jika w1 == w2 */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (w1.Length != w2.Length) {
        return false;
    }
    for (i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) {
            return false;
        }
    }
    return true;
}