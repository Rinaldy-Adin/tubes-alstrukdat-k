#include "strlib.h"
#include <stdio.h>

// Membuat struktur data string dari array of characters
String createString(char charArr[]) {
    /* KAMUS */
    String str;
    int i;

    /* ALGORITMA */
    i = 0;
    while (charArr && i < StrMax && charArr[i] != '\0') {
        TAB(str)[i] = charArr[i];
        i++;
    }
    LEN(str) = i;

    return str;
}

// Baca string sampai menemukan karakter '\n'
String readLine() {
    /* KAMUS */
    String str;

    /* ALGORITMA */
    if (currentChar == '\n') {
        ADV();
    }

    LEN(str) = 0;
    while (currentChar != '\n' && LEN(str) < StrMax && currentChar != MARK) {
        TAB(str)[LEN(str)] = currentChar;
        LEN(str)++;
        ADV();
    }

    return str;
}

// Membandingkan kesamaan dari dua string
boolean stringsAreEqual(String s1, String s2) {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    if (s1.Length != s2.Length)
        return false;

    for (i = 0; i < s1.Length; i++) {
        if (s1.Tab[i] != s2.Tab[i])
            return false;
    }

    return true;
}

// Menghilangkan leading dan trailing zero, serta mereduksi
// Nilai Spasi yang panjang menjadi hanya satu karakter spasi
String removeLongSpaces(String str) {
    /* KAMUS */
    String removed;
    int i, j;

    /* ALGORITMA */
    i = 0;
    removed.Length = 0;
    while (TAB(str)[i] == ' ') {
        i++;
    }
    while (i < LEN(str)) {
        while (i > 0 && i < LEN(str) && TAB(str)[i] == ' ' &&
               TAB(str)[i - 1] == ' ') {
            i++;
        }
        if (i < LEN(str)) {
            removed.Tab[removed.Length] = TAB(str)[i];
            removed.Length++;
            i++;
        }
    }

    while (removed.Tab[removed.Length - 1] == ' ' && removed.Length > 0) {
        removed.Tab[removed.Length - 1] = 0;
        removed.Length--;
    }

    return removed;
}

// Print string ke terminal tanpa ada penambahan karakter
void printString(String str) {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < LEN(str); i++) {
        printf("%c", TAB(str)[i]);
    }
}

int stringToInt(String s) {
    /* Mengubah String s menjadi integer */
    /* KAMUS LOKAL */
    int i;
    int result;

    /* ALGORITMA */
    result = 0;
    for (i=0; i<LEN(s); i++) {
         if (i > 0) {
            result *= 10;
         }
         result += ((int) (TAB(s)[i] - '0'));
    }
    return result;
}

TIME stringToTime(String s) {
    /* Mengubah String s menjadi TIME */
    /* KAMUS LOKAL */
    TIME result;
    int d,h,m;
    int i, j, ctr;
    String temp;

    /* ALGORITMA */
    i = 0;
    ctr = 0;
    while (i < LEN(s)) {
        LEN(temp) = 0;
        while (TAB(s)[i] != ' ' && i < LEN(s)) {
            TAB(temp)[LEN(temp)] = TAB(s)[i];
            i++;
            LEN(temp)++;
        }
        if (ctr == 0) {
            d = stringToInt(temp);
        }
        else if (ctr == 1) {
            h = stringToInt(temp);
        }
        else {
            m = stringToInt(temp);
        }
        ctr++;
        i++;
        // Kosongkan temp
        j = 0;
        while (TAB(temp)[j] != '\0') {
            TAB(temp)[j] = '\0';
            j++;
        }
    }
    CreateTime(&result, d,h,m);
    return result;
}

String wordToString(Word w) {
    /* KAMUS */
    String str;
    int i;

    /* ALGORITMA */
    for (i = 0; i < WordLength(w); i++) {
        TAB(str)[i] = CharAt(w, i);
    }
    
    LEN(str) = WordLength(w);

    return str;
}
/* Mengubah Word w menjadi String. */