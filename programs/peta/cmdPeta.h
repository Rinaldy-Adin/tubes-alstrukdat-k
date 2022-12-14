#ifndef __CMDPETA_H__
#define __CMDPETA_H__

#include <stdio.h>

#include "../../ADT/charmachine/charmachine.h"
#include "../../ADT/matrix/matrix.h"
#include "../../ADT/point/point.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../../utils/mathops.h"

void readPetaFromFile(Matrix *container, char *filename);
/* DESKRIPSI
Membaca baris, kolom, dan peta dari file peta.txt dengan bantuan mesin karakter
file lalu memasukkan peta ke dalam Matrix *container I.S. : Matrix *container
sembarang F.S. : Matrix *container berukuran (baris+2)x(kolom+2) berisi peta
dari file peta.txt dan memiliki frame

Contoh konfigurasi:
10 10
S#########
####T##X##
#M#####X##
#######X##
####XXXX##
#X########
#X######C#
#XXX##F###
##########
######B###

Akan Menghasilkan Peta:
* * * * * * * * * * * *
* S                   *
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

*/

void makeFrame(Matrix *rawPeta);
/* DESKRIPSI
Membuat frame peta dari karakter '*'
I.S. : Matrix *rawPeta terdefinisi dan merupakan hasil pembacaan file
F.S : Matrix *rawPeta memiliki frame
*/

POINT currentPosition(Matrix peta);
/* DESKRIPSI
Menentukan posisi simulator saat ini di peta
*/

boolean isPositionAvailable(POINT pos, Matrix peta);
/* DESKRIPSI
Menentukan apakah suatu posisi tersedia untuk ditempati oleh simulator
*/

boolean isAdjacent(POINT pos, Matrix peta, char object);
/* DESKRIPSI
Menentukan apakah suatu objek seperti tempat telepon (T),
tempat mixing (M), tempat menggoreng (F), tempat memotong (C),
dan tempat merebus (B) bersebelahan/adjacent dengan posisi simulator (S)
*/

boolean move(POINT *pos, Matrix *peta, char direction);
/* DESKRIPSI
Memindahkan posisi simulator sesuai arah yang diinginkan
I.S POINT *pos, Matrix *peta terdefinisi
F.S Jika posisi tersedia, posisi simulator akan dipindahkan sesuai arah yang
diinginkan
*/

void moveTo(POINT startPos, POINT endPos, Matrix *peta);
/* DESKRIPSI
Memindahkan posisi simulator sesuai arah yang diinginkan
I.S POINT *startPos, *endPos, Matrix *peta terdefinisi
F.S Jika posisi tersedia, posisi simulator akan dipindahkan sesuai posisi yang
diinginkan
*/

#endif