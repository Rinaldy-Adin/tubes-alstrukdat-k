/* File: set.h */
/* Definisi Set Makanan */

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "../boolean.h"
#include "../liststatik/listStatik.h"
#include "../prioqueue/prioqueue.h"
#include "../tree/tree.h"

// Set memakai struktur data list statik dan dalam bentuk multiset (setiap elemen bisa ada lebih dari 1, karena di inventory bisa > 1)
typedef ListStatik Set;

void CreateSet(Set *s, ListStatik makanan);
/* I.S. s sembarang */
/* F.S. s terbentuk menjadi Set "kosong" dengan jumlah indeks yang dipakai sesuai indeks pada ListStatik makanan */

boolean isSubset(Set s1, Set s2);
/* Mengembalikan true jika s2 adalah subset dari s1 */

void AddElmtSet(Set *s, ElTypeStat e, ListStatik makanan);
/* I.S. s terdefinisi, mungkin kosong */
/* F.S. e ditambahkan sebagai elemen s */

void RemoveElmtSet(Set *s, ElTypeStat e, ListStatik makanan);
/* I.S. s terdefinisi, tidak kosong */
/* F.S. e dithapus dari s (jika ada) */

boolean CompareInvWTree(Set *S, Set inv, Tree T, ListStatik katalog);
/* Mengembalikan true jika makanan di inventory bisa membuat makanan di resep T */

void RecommendMakanan(PrioQueue inventory, ListStatik resep, ListStatik katalog);
/* Memberikan rekomendasi makanan berdasarkan makanan yang ada di inventory */
/* I.S. inventory, resep, dan katalog terdefinisi */
/* F.S. Rekomendasi makanan tercetak ke layar */
#endif