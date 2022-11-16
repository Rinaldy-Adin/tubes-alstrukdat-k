#ifndef __STRLIB_H_
#define __STRLIB_H_

#include <stdio.h>

#include "../charmachine/charmachine.h"
#include "../waktu/waktu.h"
#include "../wordmachine/wordmachine.h"

#define StrMax 255

typedef struct {
    char Tab[StrMax]; /* container penyimpan kata, indeks yang dipakai
                           [0..NMax-1] */
    int Length;
} String;

/* SELEKTOR */
#define TAB(s) (s).Tab
#define LEN(s) (s).Length

String createString(char charArr[]);
/* menghasilkan struktur data string dari array of characters */

void copyString(String source, String *dest);
/* I.S. source terdefinisi, dest bebas */
/* F.S. string dest memiliki nilai yang sama dengan source */

String readLine();
/* Baca string sampai menemukan karakter '\n' */

boolean stringsAreEqual(String s1, String s2);
/* Membandingkan kesamaan dari dua string */

String concatString(String s1, String s2);
/* Menghasilkan string berupa penggabungan dari
   dua string dengan dipisahkan spasi */

String removeLongSpaces(String str);
/* Mengembalikan str tanpa leading dan trailing zero,
   serta mereduksi Spasi yang panjang menjadi hanya satu
   karakter spasi */

void printString(String str);
/* I.S. str terdefinisi */
/* F.S. string str ditampilkan tanpa ada karakter tambahan */

int stringToInt(String s);
/* Mengubah String s menjadi int. Prekondisi : String s hanya berisi angka */

boolean stringIsIntParsable(String s);
/* Melakukan evaluasi apakah string hanya berisi angka */

TIME stringToTime(String s);
/* Mengubah String s menjadi TIME. Prekondisi : String s memiliki format D H M
 */

#endif