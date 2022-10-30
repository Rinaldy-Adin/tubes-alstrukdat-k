#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include "boolean.h"

/* NOTE :
 ADT point digunakan untuk menyimpan posisi simulator pada peta 
 ADT point menggunakan sistem (baris, kolom), bukan (absis, ordinat). contoh: 
* * * * * * * * * * * *
*   S                 *
*         T     X     *
*   M           X     *
*               X     *
*         X X X X     *
*   X                 *
*   X              C  *
*   X X X     F       *
*                     *
*             B       *
* * * * * * * * * * * *
pada peta diatas, posisi simulator disimpan sebagai (1,2)
*/

typedef struct { 
	int row; 
	int col; 
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define ROW(P) (P).row
#define COL(P) (P).col
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
void Geser (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, barisnya sebesar deltaX dan kolomnya sebesar deltaY */

#endif