/* File : prioqueue.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit
 * dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioqueue_H
#define prioqueue_H

#include <stdlib.h>

#include "../boolean.h"
#include "../liststatik/listStatik.h"
#include "../makanan/makanan.h"
#include "../waktu/waktu.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    TIME time;       /* [1..100], waktu dengan nilai 1..100 (1 adalah waktu adalah
                        terendah) */
    Makanan makanan; /* elemen karakter */
} infotype;
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype *T;  /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
#define Time(e) (e).time
#define Makanan(e) (e).makanan
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty(PrioQueue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

void CopyPrioqueue(PrioQueue Source, PrioQueue *Dest);
/* I.S. Source terdefinisi dan Dest sembarang */
/* F.S. List Dest berisi nilai yang sama dengan Source */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueue *Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar
 * berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas. */
void Dequeue(PrioQueue *Q, infotype *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.
        Q mungkin kosong */

void deleteAtPQ(PrioQueue *Q, infotype *val, IdxType idx);

/* *** Searching indeks makanan *** */
int idxInventory(PrioQueue Q, Makanan m);
/* Mengembalikan indeks Makanan m di inventory */

/* Operasi Tambahan */
void Ambil(PrioQueue *Q, infotype X, infotype *result);
/* Proses: Mengambil X pada Q dan dihapus setelah operasi */
/* I.S. Q tidak mungkin kosong, mungkin ada X */
/* F.S. Q mungkin kosong. Jika X tidak ditemukan maka result tidak berubah */

boolean Cook(String IDMakanan, PrioQueue *Q, ListStatik resep);
/* Proses: Memasak makanan dengan ID IDMakanan jika ada di resep dan bahannya
 * ada di inventory */
/* I.S. IDMakanan, *Q, resep terdefinisi */
/* F.S. Jika bahan dan resep ada, makanan dengan ID IDMakanan terbentuk. Makanan
 * di Q berkurang. Q mungkin kosong. */
#endif