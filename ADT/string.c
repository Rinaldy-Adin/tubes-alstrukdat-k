/* File: String.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 26 Oktober 2022 */
/* Deskripsi: implementasi ADT list dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateString(String *l, int capacity) {
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    BUFFERString(*l) = (ElType *) malloc(capacity*sizeof(ElType));
    NEFFString(*l) = 0;
    CAPACITYString(*l) = capacity;
    return;
}

void dealocateString(String *l) {
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITYString(l)=0; NEFF(l)=0 */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    free(BUFFERString(*l));
    CAPACITYString(*l)=0;
    NEFFString(*l)=0;
    return;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int stringLength(String l) {
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* *** Daya tampung container *** */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return NEFFString(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxString(String l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return 0;
}

IdxType getLastIdxString(String l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFString(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidString(String l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < CAPACITYString(l));
}

boolean isIdxEffString(String l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFFString(l) */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (i >= 0 && i < NEFFString(l));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyString(String l) {
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFString(l) == 0);
}

/* *** Test list penuh *** */
boolean isFullString(String l) {
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    return (NEFFString(l) == CAPACITYString(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readString(String *l) {
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYString(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITYString(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS LOKAL */

    /* ALGORITMA*/
    int n;
    IdxType i;

    /* ALGORITMA */
    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITYString(*l));
    NEFFString(*l) = n;

    // Membaca elemen list
    for (i=0; i<n; i++){
        scanf("%c", &ELMTString(*l,i));
    }
    return;
}

void printString(String l) {
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
   if (isEmptyString(l)) {
      printf("\n");
   }
   else {
      for (i=getFirstIdxString(l);i<getLastIdxString(l);i++) {
         printf("%c",ELMTString(l,i));
      }
   }
   return;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */

/* ********** OPERASI LAIN ********** */
void copyString(String lIn, String *lOut) {
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, NEFFString dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */ 
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    CreateString(lOut, CAPACITYString(lIn));
    NEFFString(*lOut) = NEFFString(lIn);
    for (i=0;i<listLengthString(lIn);i++) {
        ELMTString(*lOut,i) = ELMTString(lIn,i);
    }
    return;
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastString(String *l, ElType val) {
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTString(*l,stringLength(*l)) = val;
    NEFFString(*l)++;
    return;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastString(String *l, ElType *val) {
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    *val = ELMTString(*l,stringLength(*l)-1);
    NEFFString(*l)--;
    return;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(String *l, int num) {
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS LOKAL */
    IdxType i;
    String tempList;
    int newCap;

    /* ALGORITMA */
    copyString(*l,&tempList);
    newCap = CAPACITYString(*l) + num;
    dealocateList(l);
    CreateString(l, newCap);
    for (i=0;i<NEFFString(tempList);i++) {
        ELMTString(*l,i) = ELMTString(tempList,i);
        NEFFString(*l)++;
    }
    return;
}

void shrinkList(String *l, int num) {
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS LOKAL */
    IdxType i;
    String tempList;
    int newCap;

    /* ALGORITMA */
    copyString(*l,&tempList);
    newCap = CAPACITYString(*l) - num;
    dealocateString(l);
    CreateString(l, newCap);
    for (i=0;i<NEFFString(tempList);i++) {
        ELMTString(*l,i) = ELMTString(tempList,i);
        NEFFString(*l)++;
    }
    return;
}

void compressList(String *l) {
    /* Proses : Mengubah capacity sehingga nEff = capacity */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran nEff = capacity */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (NEFFString(*l) < CAPACITYString(*l)) {
        shrinkList(l, (CAPACITYString(*l)-NEFFString(*l)));
    }
    return;
}

void readLine(String *s) {
    /* I.S. s sembarang, mesin kata sudah ada di awal kata pertama baris yang ingin diakuisisi */
    /* F.S. s terisi dengan karakter di baris */
    /* KAMUS LOKAL */
    int i,j;

    /* ALGORITMA */
    // Alokasi ukuran string sebesar 2 kali ukuran Word maksimum
    CreateString(s, NMax*2);
    while (!endWord && currentChar != NEWLINE) {
        for (i=0; i<currentWord.Length; i++) {
            insertLastString(s,currentWord.TabWord[i]);
        }
        ADVWORD();
        if (CAPACITYString(*s) - NEFFString(*s) < 20) { // Jika string sudah hampir penuh, ubah ukuran list jadi 2x lipat
            expandList(s, CAPACITYString(*s)*2);
        }
        if (!endWord && currentChar != NEWLINE) {
            insertLastString(s, ' ');
        }
    }
    compressList(s);
}

int stringToInt(String s) {
    /* Mengubah String s menjadi integer */
    /* KAMUS LOKAL */
    int i;
    int result;

    /* ALGORITMA */
    result = 0;
    for (i=0; i<NEFFString(s); i++) {
         if (i > 0) {
            result *= 10;
         }
         result += ((int) (ELMTString(s,i) - '0'));
    }
    return result;
}

TIME stringToTime(String s) {
    /* Mengubah String s menjadi TIME */
    /* KAMUS LOKAL */
    TIME result;
    int d,h,m;
    int i, ctr;
    String temp;

    /* ALGORITMA */
    i = 0;
    ctr = 0;
    CreateString(&temp, NMax); // Inisialisasi penampung sementara angka
    while (i < NEFFString(s)) {
        while (ELMT(s,i) != ' ' && i < NEFFString(s)) {
            insertLastString(&temp, ELMT(s,i));
            i++;
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
    }
    CreateTime(&result, d,h,m);
    return result;
}