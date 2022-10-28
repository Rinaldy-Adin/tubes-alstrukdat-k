#include "strlib.h"

#include <stdio.h>

#include "charmachine.h"

// Membuat struktur data string dari array of characters
String createString(char charArr[]) {
    /* KAMUS */
    String str;
    int i;

    /* ALGORITMA */
    i = 0;
    while (charArr && i < StrMax && charArr[i] != '\0') {
        str.Tab[i] = charArr[i];
        i++;
    }
    str.Length = i;

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

    str.Length = 0;
    while (currentChar != '\n' && str.Length < StrMax) {
        str.Tab[str.Length] = currentChar;
        str.Length++;
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
    while (str.Tab[i] == ' ') {
        i++;
    }
    while (i < str.Length) {
        while (i > 0 && i < str.Length && str.Tab[i] == ' ' &&
               str.Tab[i - 1] == ' ') {
            i++;
        }
        if (i < str.Length) {
            removed.Tab[removed.Length] = str.Tab[i];
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
    for (i = 0; i < str.Length; i++) {
        printf("%c", str.Tab[i]);
    }
}
