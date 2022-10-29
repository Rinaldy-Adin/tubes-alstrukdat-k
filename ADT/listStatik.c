/* File: liststatik.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 23 Oktober 2022 */
/* Deskripsi: implementasi ADT list statik untuk Makanan */

#include <stdio.h>
#include "listStatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
   /* I.S. l sembarang */
   /* F.S. Terbentuk ListStatik l kosong dengan kapasitas CAPACITYSTAT */
   /* Proses: Inisialisasi semua elemen List l dengan MARK */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   NEFFSTAT(*l) = 0;
   return;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthStat(ListStatik l) {
   /* Mengirimkan banyaknya elemen efektif List */
   /* Mengirimkan nol jika List kosong */  
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFFSTAT(l));
}

IdxType getLastIdxStat(ListStatik l) {
   /* Prekondisi : List l tidak kosong */
   /* Mengirimkan indeks elemen l terakhir */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFFSTAT(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidStat(IdxType i) {
   /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
   /* yaitu antara indeks yang terdefinisi utk container*/
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (i >= IDX_MIN && i < CAPACITYSTAT);
}

boolean isIdxEffStat(ListStatik l, IdxType i) {
   /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
   /* yaitu antara 0..length(l)-1 */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (i >= IDX_MIN && i < listLengthStat(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyStat(ListStatik l) {
   /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFFSTAT(l) == 0);
}

/* *** Test List penuh *** */
boolean isFullStat(ListStatik l) {
   /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   return (NEFFSTAT(l) == CAPACITYSTAT);
}

void printListStat(ListStatik l) {
   /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
      siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
      karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
   /* I.S. l boleh kosong */
   /* F.S. Jika l tidak kosong tercetak semua informasi makanan yang ada di dalam l */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   if (isEmptyStat(l)) {
      printf("List makanan kosong");
   }
   else {
      printf("Daftar Makanan\n");
      printf("ID - Nama - Kedaluwarsa - Lama antar - Lama aksi (selain pengantaran) - Cara dapat (B = Buy, M = Mix, C = Chop, F = Fry, O = Boil)\n");
      for (i=IDX_MIN; i <= getLastIdxStat(l); i++) {
         printf("  %d. ", (i+1));
         printString(ID(MAKANAN(ELMTSTAT(l,i))));
         printf(" - ");
         printString(Nama(MAKANAN(ELMTSTAT(l,i))));
         printf(" - ");
         TulisTIME(Kadal(MAKANAN(ELMTSTAT(l,i))));
         printf(" - ");
         TulisTIME(DelTime(MAKANAN(ELMTSTAT(l,i))));
         printf(" - ");
         TulisTIME(ActTime(MAKANAN(ELMTSTAT(l,i))));
         printf(" - ");
         printString(Command(MAKANAN(ELMTSTAT(l,i))));
         printf("\n");
      }
   }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualStat(ListStatik l1, ListStatik l2) {
   /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
   /* KAMUS LOKAL */
   IdxType i;
   boolean equal;

   /* ALGORITMA */
   if (listLengthStat(l1) == listLengthStat(l2)) {
      equal = true;
      i = IDX_MIN;
      while (i<listLengthStat(l1) && equal) {
         if (!stringsAreEqual((ID(MAKANAN(ELMTSTAT(l1,i)))),(ID(MAKANAN(ELMTSTAT(l2,i)))))) {
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
int indexOfStat(ListStatik l, String searchID) {
   /* Search apakah ada elemen List l yang ber-ID searchId */
   /* Jika ada, menghasilkan indeks i terkecil, dengan ID(ELMTSTAT(l,i)) = searchId */
   /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
   /* Skema Searching yang digunakan bebas */
   /* KAMUS LOKAL */
   IdxType i;
   boolean found;

   /* ALGORITMA */
   if (isEmptyStat(l)) {
      return IDX_UNDEF;
   } else { // Skema searching dengan boolean
      found = false;
      i = IDX_MIN;
      while (i < NEFFSTAT(l) && !(found)) {
         if (stringsAreEqual(ID(MAKANAN(ELMTSTAT(l,i))), searchID) == true) {
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
void insertFirstStat(ListStatik *l, ElTypeStat val) {
   /* Proses: Menambahkan val sebagai elemen pertama List */
   /* I.S. List l boleh kosong, tetapi tidak penuh */
   /* F.S. val adalah elemen pertama l yang baru */
   /* *** Menambahkan elemen pada index tertentu *** */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   if(isEmptyStat(*l)) {
      ELMTSTAT(*l,0) = val;
   }
   else {
      for(i=listLengthStat(*l)-1;i>=0;i--) {
         ELMTSTAT(*l,i+1) = ELMTSTAT(*l,i);
      }
      ELMTSTAT(*l,0) = val;
   }
   NEFFSTAT(*l)++;
}

void insertAtStat(ListStatik *l, ElTypeStat val, IdxType idx) {
   /* Proses: Menambahkan val sebagai elemen pada index idx List */
   /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
   /* F.S. val adalah elemen yang disisipkan pada index idx l */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   for(i=listLengthStat(*l)-1;i>=idx;i--) {
      ELMTSTAT(*l,i+1) = ELMTSTAT(*l,i);
   }
   ELMTSTAT(*l,idx) = val;
   NEFFSTAT(*l)++;
}

/* *** Menambahkan elemen terakhir *** */
void insertLastStat(ListStatik *l, ElTypeStat val) {
   /* Proses: Menambahkan val sebagai elemen terakhir List */
   /* I.S. List l boleh kosong, tetapi tidak penuh */
   /* F.S. val adalah elemen terakhir l yang baru */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   ELMTSTAT(*l, listLengthStat(*l)) = val;
   NEFFSTAT(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstStat(ListStatik *l, ElTypeStat *val) {
   /* Proses : Menghapus elemen pertama List */
   /* I.S. List tidak kosong */
   /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   *val = ELMTSTAT(*l,0);
   for (i=IDX_MIN;i<listLengthStat(*l);i++) {
      ELMTSTAT(*l,i) = ELMTSTAT(*l,i+1);
   }
   NEFFSTAT(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAtStat(ListStatik *l, ElTypeStat *val, IdxType idx) {
   /* Proses : Menghapus elemen pada index idx List */
   /* I.S. List tidak kosong, idx adalah index yang valid di l */
   /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */
   IdxType i;

   /* ALGORITMA */
   *val = ELMTSTAT(*l,idx);
   for (i=idx;i<listLengthStat(*l)-1;i++) {
      ELMTSTAT(*l,i) = ELMTSTAT(*l,i+1);
   }
   NEFFSTAT(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLastStat(ListStatik *l, ElTypeStat *val) {
   /* Proses : Menghapus elemen terakhir List */
   /* I.S. List tidak kosong */
   /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
   /*      Banyaknya elemen List berkurang satu */
   /*      List l mungkin menjadi kosong */
   /* KAMUS LOKAL */

   /* ALGORITMA */
   *val = ELMTSTAT(*l,listLengthStat(*l)-1);
   NEFFSTAT(*l)--;
}

/* Membaca makanan dari file */
void loadMakanan(ListStatik *l) {
    /* Membaca list makanan dari file */
    /* I.S. l sembarang */
    /* F.S. l terisi makanan dari file konfigurasi */
    /* KAMUS LOKAL */
    ElTypeStat e, temp;
    String Nmakanan, id, nama, kadal, command, del, act;
    int N; // Jumlah makanan
    int i, idx;
    char *filename = "pita.txt";

    /* ALGORITMA */
    CreateListStatik(l);
    STARTWORDFILE(filename);    
    if (endWord) {
        printf("File kosong\n");
    }
    else {
         Nmakanan = createString(currentWord.TabWord);
         N = stringToInt(Nmakanan);
         for (i=0; i<N; i++) {
            id = readLine();
            nama = readLine();
            kadal = readLine();
            del = readLine();
            act = readLine();
            command = readLine();
            
            makeMakanan(&MAKANAN(e), id, nama, stringToTime(kadal), stringToTime(del), stringToTime(act), command);
            idx = indexOfStat(*l,id);
            if (idx != IDX_UNDEF) {
               deleteAtStat(l,&temp,idx);
               insertAtStat(l,e,idx);
            } else {
               insertLastStat(l,e);
            }
         }
    }
}

void loadResep(ListStatik *l, ListStatik makan) {
    /* Membaca list resep dari file */
    /* I.S. l sembarang, makan terdefinisi dan sudah berisi semua makanan yang ada */
    /* F.S. l terisi resep dari file konfigurasi */
    /* KAMUS LOKAL */
    ElTypeStat e, temp;
    ListStatik test;
    String NResep, NChild, IDParent, IDChild;
    int N, M; // Jumlah resep dan bahan per makanan
    int i, j, idx;
    char *filename = "pitaResep.txt";

    /* ALGORITMA */
    CreateListStatik(l);
    CreateListStatik(&test);
    STARTWORDFILE(filename);    
    if (endWord) {
        printf("File kosong\n");
    }
    else {
         NResep = createString(currentWord.TabWord);
         N = stringToInt(NResep);
         ADVWORD();
         for (i=0; i<N; i++) {
            IDParent = createString(currentWord.TabWord);
            idx = indexOfStat(makan,IDParent);
            ADVWORD();
            CreateTree(&TREE(e));
            AddChild(&TREE(e), MAKANAN(ELMTSTAT(makan,idx)));
            NChild = createString(currentWord.TabWord);
            M = stringToInt(NChild);
            ADVWORD();
            for (j=0; j<M; j++) {
               IDChild = createString(currentWord.TabWord);
               idx = indexOfStat(makan,IDChild);
               AddChild(&TREE(e), MAKANAN(ELMTSTAT(makan,idx)));
               ADVWORD();
            }
            TREE(temp) = duplicateTree(TREE(e));
            insertLastStat(l, temp);
            deleteTree(&TREE(e));
         }
    }
}

void printResep(ListStatik resep) {
   /* I.S. resep terdefinisi */
   /* F.s. Isi resep tercetak di layar */
   /* KAMUS LOKAL */
   int i;

   /* ALGORITMA */
   printf("Daftar resep : \n");
   for (i=0; i<NEFFSTAT(resep); i++) {
      printf("    %d. ", i+1);
      printTreeResep(TREE(ELMTSTAT(resep,i)));
   }
}