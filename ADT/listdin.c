/* File: listdin.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 10 September 2022 */
/* Topik praktikum: ADT List Statik dan Dinamik */
/* Deskripsi: implementasi ADT list dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity) {
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
    return;
}

void dealocateList(ListDin *l) {
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    free(BUFFER(*l));
    CAPACITY(*l)=0;
    NEFF(*l)=0;
    return;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l) {
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return 0;
}

IdxType getLastIdx(ListDin l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFF(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < NEFF(l));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFF(l) == 0);
}

/* *** Test list penuh *** */
boolean isFull(ListDin l) {
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    int n;
    IdxType i;

    /* ALGORITMA */
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY(*l));
    NEFF(*l) = n;

    // Membaca elemen list
    for (i=0; i<n; i++){
        scanf("%d", &ELMT(*l,i));
    }
    return;
}

void printList(ListDin l) {
    /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   if (isEmpty(l)) {
      printf("[]");
   }
   else {
      printf("[");
      for (i=getFirstIdx(l);i<getLastIdx(l);i++) {
         printf("%d,",ELMT(l,i));
      }
      printf("%d]", ELMT(l,getLastIdx(l)));
   }
   return;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan IDX_UNDEF */
    /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS LOKAL */
    IdxType i;
    boolean found;

    /* ALGORITMA */
    if (isEmpty(l)) {
        return IDX_UNDEF;
    } else { // Skema searching dengan boolean
        found = false;
        i = IDX_MIN;
        while (i < listLength(l) && !(found)) {
            if (ID(ELMT(l,i)) == ID(val)) {
                found = true;
            } else {
                i++;
            }
        }
        if (found) {
            return i;
        }
        else {
            return IDX_UNDEF;
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */ 
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i=0;i<listLength(lIn);i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
    return;
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l)++;
    return;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    *val = ELMT(*l,listLength(*l)-1);
    NEFF(*l)--;
    return;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS LOKAL */
    IdxType i;
    ListDin tempList;
    int newCap;

    /* ALGORITMA */
    copyList(*l,&tempList);
    newCap = CAPACITY(*l) + num;
    dealocateList(l);
    CreateListDin(l, newCap);
    for (i=0;i<NEFF(tempList);i++) {
        ELMT(*l,i) = ELMT(tempList,i);
        NEFF(*l)++;
    }
    return;
}

void shrinkList(ListDin *l, int num) {
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS LOKAL */
    IdxType i;
    ListDin tempList;
    int newCap;

    /* ALGORITMA */
    copyList(*l,&tempList);
    newCap = CAPACITY(*l) - num;
    dealocateList(l);
    CreateListDin(l, newCap);
    for (i=0;i<NEFF(tempList);i++) {
        ELMT(*l,i) = ELMT(tempList,i);
        NEFF(*l)++;
    }
    return;
}

void compressList(ListDin *l) {
    /* Proses : Mengubah capacity sehingga nEff = capacity */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran nEff = capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (NEFF(*l) < CAPACITY(*l)) {
        shrinkList(l, (CAPACITY(*l)-NEFF(*l)));
    }
    return;
}