#ifndef __STRLIB_H_
#define __STRLIB_H_

#include <stdio.h>

#include "charmachine.h"
#include "waktu.h"
#include "wordmachine.h"

#define StrMax 255

typedef struct {
    char Tab[StrMax]; /* container penyimpan kata, indeks yang dipakai
                           [0..NMax-1] */
    int Length;
} String;

/* SELEKTOR */
#define TAB(s) (s).Tab
#define LEN(s) (s).Length

// Baca string sampai menemukan karakter '\n'
String readLine();

// Membuat struktur data string dari array of characters
String createString(char charArr[]);

// Membandingkan kesamaan dari dua string
boolean stringsAreEqual(String s1, String s2);

// Menghilangkan leading dan trailing zero, serta mereduksi
// Nilai Spasi yang panjang menjadi hanya satu karakter spasi
String removeLongSpaces(String str);

// Print string ke terminal tanpa ada penambahan karakter
void printString(String str);


/* Konversi String ke bentuk lain */
int stringToInt(String s);
/* Mengubah String s menjadi int. Prekondisi : String s hanya berisi angka */

TIME stringToTime(String s);
/* Mengubah String s menjadi TIME. Prekondisi : String s memiliki format D H M */

/* Konversi bentuk lain ke string */
String wordToString(Word w);
/* Mengubah Word w menjadi String. */

#endif