/* File: ListDinMakanan.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 26 Oktober 2022 */
/* Deskripsi: implementasi ADT list dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "ListDinMakanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinMakanan(ListDinMakanan *l, int capacity) {
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    BUFFERDIN(*l) = (ElType *) malloc(capacity*sizeof(ElType));
    NEFFDIN(*l) = 0;
    CAPACITYDIN(*l) = capacity;
    return;
}

void dealocateList(ListDinMakanan *l) {
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITYDIN(l)=0; NEFF(l)=0 */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    free(BUFFERDIN(*l));
    CAPACITYDIN(*l)=0;
    NEFFDIN(*l)=0;
    return;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthDin(ListDinMakanan l) {
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return NEFFDIN(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxDin(ListDinMakanan l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return 0;
}

IdxType getLastIdxDin(ListDinMakanan l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFDIN(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidDin(ListDinMakanan l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < CAPACITYDIN(l));
}

boolean isIdxEffDin(ListDinMakanan l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFFDIN(l) */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < NEFFDIN(l));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyDin(ListDinMakanan l) {
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFDIN(l) == 0);
}

/* *** Test list penuh *** */
boolean isFullDin(ListDinMakanan l) {
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFDIN(l) == CAPACITYDIN(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDinMakanan *l) {
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYDIN(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITYDIN(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    int n;
    IdxType i;

    /* ALGORITMA */
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITYDIN(*l));
    NEFFDIN(*l) = n;

    // Membaca elemen list
    for (i=0; i<n; i++){
        scanf("%d", &ELMTDIN(*l,i));
    }
    return;
}

void printListDin(ListDinMakanan l) {
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
   if (isEmptyDin(l)) {
      printf("[]");
   }
   else {
      printf("[");
      for (i=getFirstIdxDin(l);i<getLastIdxDin(l);i++) {
         printf("%d,",ELMTDIN(l,i));
      }
      printf("%d]", ELMTDIN(l,getLastIdxDin(l)));
   }
   return;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfDin(ListDinMakanan l, char* searchId) {
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan IDX_UNDEF */
    /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS LOKAL */
    IdxType i;
    String search;
    boolean found;

    /* ALGORITMA */
    if (isEmptyDin(l)) {
        return IDX_UNDEF;
    } else { // Skema searching dengan boolean
        found = false;
        createString(&search, searchId);
        i = IDX_MIN;
        while (i < listLengthDin(l) && !(found)) {
            if (isStringEqual(ID(ELMTDIN(l,i)),search)) {
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
void copyListDin(ListDinMakanan lIn, ListDinMakanan *lOut) {
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, NEFFDIN dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */ 
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    CreateListDinMakanan(lOut, CAPACITYDIN(lIn));
    NEFFDIN(*lOut) = NEFFDIN(lIn);
    for (i=0;i<listLengthDin(lIn);i++) {
        ELMTDIN(*lOut,i) = ELMTDIN(lIn,i);
    }
    return;
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastDin(ListDinMakanan *l, ElType val) {
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTDIN(*l, listLengthDin(*l)) = val;
    NEFFDIN(*l)++;
    return;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastDin(ListDinMakanan *l, ElType *val) {
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    *val = ELMTDIN(*l,listLengthDin(*l)-1);
    NEFFDIN(*l)--;
    return;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDinMakanan *l, int num) {
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS LOKAL */
    IdxType i;
    ListDinMakanan tempList;
    int newCap;

    /* ALGORITMA */
    copyListDin(*l,&tempList);
    newCap = CAPACITYDIN(*l) + num;
    dealocateList(l);
    CreateListDinMakanan(l, newCap);
    for (i=0;i<NEFFDIN(tempList);i++) {
        ELMTDIN(*l,i) = ELMTDIN(tempList,i);
        NEFFDIN(*l)++;
    }
    return;
}

void shrinkList(ListDinMakanan *l, int num) {
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS LOKAL */
    IdxType i;
    ListDinMakanan tempList;
    int newCap;

    /* ALGORITMA */
    copyListDin(*l,&tempList);
    newCap = CAPACITYDIN(*l) - num;
    dealocateList(l);
    CreateListDinMakanan(l, newCap);
    for (i=0;i<NEFFDIN(tempList);i++) {
        ELMTDIN(*l,i) = ELMTDIN(tempList,i);
        NEFFDIN(*l)++;
    }
    return;
}

void compressList(ListDinMakanan *l) {
    /* Proses : Mengubah capacity sehingga nEff = capacity */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran nEff = capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (NEFFDIN(*l) < CAPACITYDIN(*l)) {
        shrinkList(l, (CAPACITYDIN(*l)-NEFFDIN(*l)));
    }
    return;
}