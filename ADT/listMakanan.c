/* File: liststatik.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 23 Oktober 2022 */
/* Deskripsi: implementasi ADT list statik untuk Makanan */

#include <stdio.h>
#include "listMakanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *l)
{
   /* I.S. l sembarang */
   /* F.S. Terbentuk ListMakanan l kosong dengan kapasitas CAPACITY */
   /* Proses: Inisialisasi semua elemen List l dengan MARK */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   NEFF(*l) = 0;
   return;
}

/* Membaca makanan dari file */
void loadMakanan(ListMakanan *l) {
    /* Membaca list makanan dari file */
    /* I.S. l sembarang */
    /* F.S. l terisi makanan dari file konfigurasi */
    /* KAMUS LOKAL */
    Makanan m;
    String id, nama, kadal, command, act;
    int N; // Jumlah makanan
    int i;
    char *filename = "pita.txt";

    /* ALGORITMA */
    CreateListMakanan(l);
    STARTWORD(filename);    
    if (endWord) {
        printf("File kosong\n");
    }
    else {
        N = wordToInt(currentWord);
        ADVWORD();
        for (i=0; i<N; i++) {
            readLine(&id);
            readLine(&nama);
            readLine(&kadal);
            readLine(&act);
            readLine(&command);
            
            makeMakanan(&m,id,nama,kadal,act,command);
            insertLast(l,m);
        }
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListMakanan l) {
   /* Mengirimkan banyaknya elemen efektif List */
   /* Mengirimkan nol jika List kosong */  
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFF(l));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(IdxType i) {
   /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
   /* yaitu antara indeks yang terdefinisi utk container*/
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(ListMakanan l, IdxType i) {
   /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
   /* yaitu antara 0..length(l)-1 */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (i >= IDX_MIN && i < listLength(l));
}

IdxType getLastIdx(ListMakanan l) {
   /* Prekondisi : List l tidak kosong */
   /* Mengirimkan indeks elemen l terakhir */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFF(l)-1);

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListMakanan l) {
   /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFF(l) == 0);
}

/* *** Test List penuh *** */
boolean isFull(ListMakanan l) {
   /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFF(l) == CAPACITY);
}

void printList(ListMakanan l) {
   /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
      siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
      karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
   /* I.S. l boleh kosong */
   /* F.S. Jika l tidak kosong tercetak semua informasi makanan yang ada di dalam l */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   if (isEmpty(l)) {
      printf("List makanan kosong");
   }
   else {
      printf("Daftar Makanan\n");
      printf("ID - Nama - Kedaluwarsa - Lama aksi - Cara dapat (B = Buy, M = Mix, C = Chop, F = Fry, O = Boil)\n");
      for (i=IDX_MIN; i <= getLastIdx(l); i++) {
         printf("  %d. ", (i+1));
         printString(ID(ELMT(l,i)));
         printf(" - ");
         printString(Nama(ELMT(l,i)));
         printf(" - ");
         TulisTIME(Kadal(ELMT(l,i)));
         printf(" - ");
         TulisTIME(ActTime(ELMT(l,i)));
         printf(" - ");
         printString(Command(ELMT(l,i)));
         printf("\n");
      }
   }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListMakanan l1, ListMakanan l2) {
   /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
   /* KAMUS LOKAL */
   IdxType i;
   boolean equal;

   /* ALGORITMA */
   if (listLength(l1) == listLength(l2)) {
      equal = true;
      i = IDX_MIN;
      while (i<listLength(l1) && equal) {
         if (!isStringEqual(ID(ELMT(l1,i)),ID(ELMT(l2,i)))) {
            equal = false;
         }
         else {
            i++;
         }
      }
   } else {
      equal = false;
   }
   return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListMakanan l, char* searchId) {
   /* Search apakah ada elemen List l yang ber-ID searchId */
   /* Jika ada, menghasilkan indeks i terkecil, dengan ID(ELMT(l,i)) = searchId */
   /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
   /* Skema Searching yang digunakan bebas */
   /* KAMUS LOKAL */
   IdxType i;
   String search;
   boolean found;

   /* ALGORITMA */
   if (isEmpty(l)) {
      return IDX_UNDEF;
   } else { // Skema searching dengan boolean
      found = false;
      i = IDX_MIN;
      createString(&search,searchId);
      while (i < listLength(l) && !(found)) {
         if (isStringEqual(ID(ELMT(l,i)), search)) {
            found = true;
         }
         else {
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

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListMakanan *l, ElType val) {
   /* Proses: Menambahkan val sebagai elemen pertama List */
   /* I.S. List l boleh kosong, tetapi tidak penuh */
   /* F.S. val adalah elemen pertama l yang baru */
   /* *** Menambahkan elemen pada index tertentu *** */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   if(isEmpty(*l)) {
      ELMT(*l,0) = val;
   }
   else {
      for(i=listLength(*l)-1;i>=0;i--) {
         ELMT(*l,i+1) = ELMT(*l,i);
      }
      ELMT(*l,0) = val;
   }
   NEFF(*l)++;
}

void insertAt(ListMakanan *l, ElType val, IdxType idx) {
   /* Proses: Menambahkan val sebagai elemen pada index idx List */
   /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
   /* F.S. val adalah elemen yang disisipkan pada index idx l */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   for(i=listLength(*l);i>=idx;i--) {
      ELMT(*l,i+1) = ELMT(*l,i);
   }
   ELMT(*l,idx) = val;
   NEFF(*l)++;
}

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListMakanan *l, ElType val) {
   /* Proses: Menambahkan val sebagai elemen terakhir List */
   /* I.S. List l boleh kosong, tetapi tidak penuh */
   /* F.S. val adalah elemen terakhir l yang baru */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   ELMT(*l, listLength(*l)) = val;
   NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListMakanan *l, ElType *val) {
   /* Proses : Menghapus elemen pertama List */
   /* I.S. List tidak kosong */
   /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   *val = ELMT(*l,0);
   for (i=IDX_MIN;i<listLength(*l);i++) {
      ELMT(*l,i) = ELMT(*l,i+1);
   }
   NEFF(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListMakanan *l, ElType *val, IdxType idx) {
   /* Proses : Menghapus elemen pada index idx List */
   /* I.S. List tidak kosong, idx adalah index yang valid di l */
   /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   *val = ELMT(*l,idx);
   for (i=idx;i<listLength(*l)-1;i++) {
      ELMT(*l,i) = ELMT(*l,i+1);
   }
   NEFF(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListMakanan *l, ElType *val) {
   /* Proses : Menghapus elemen terakhir List */
   /* I.S. List tidak kosong */
   /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   *val = ELMT(*l,listLength(*l)-1);
   NEFF(*l)--;
}