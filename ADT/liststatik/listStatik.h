/* MODUL LIST MAKANAN STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan
 * elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdio.h>

#include "../boolean.h"
#include "../makanan/makanan.h"
#include "../strlib/strlib.h"
#include "../tree/tree.h"
#include "../wordmachine/wordmachine.h"

/*  Kamus Umum */
#define CAPACITYSTAT 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

/* type elemen List */
typedef union {
    Makanan m;
    Tree t;
    String s;
    int i;
} ElTypeStat;

typedef int IdxType;
typedef struct {
    ElTypeStat
        contents[CAPACITYSTAT]; /* memori tempat penyimpan elemen (container) */
    int NEff;                   /* Jumlah elemen efektif [0..CAPACITYSTAT] */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITYSTAT-1] */

/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTSTAT(l, i) (l).contents[(i)]
#define NEFFSTAT(l) (l).NEff
#define MAKANAN(e) (e).m
#define TREE(e) (e).t
#define STRING(e) (e).s
#define INTEGER(e) (e).i

/* Definisi List kosong : NEFF(l) == 0 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITYSTAT */

void CopyListStatikString(ListStatik Source, ListStatik *Dest);
/* I.S. Source terdefinisi dan Dest sembarang, kedua list berisi string */
/* F.S. List Dest berisi nilai yang sama dengan Source */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthStat(ListStatik l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* *** Selektor INDEKS *** */
IdxType getLastIdxStat(ListStatik l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidStat(IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffStat(ListStatik l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyStat(ListStatik l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullStat(ListStatik l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void printListString(ListStatik l);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong tercetak semua informasi string yang ada di
 * dalam l */

void printListMakanan(ListStatik l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualStat(ListStatik l1, ListStatik l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfMakanan(ListStatik l, String searchID);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

int indexOfResep(ListStatik l, String searchID);
/* Search apakah ada elemen List l yang ber-ID searchId */
/* Jika ada, menghasilkan indeks i terkecil, dengan ID(ELMTSTAT(l,i)) = searchId
 */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstStat(ListStatik *l, ElTypeStat val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtStat(ListStatik *l, ElTypeStat val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l
 */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLastStat(ListStatik *l, ElTypeStat val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstStat(ListStatik *l, ElTypeStat *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtStat(ListStatik *l, ElTypeStat *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLastStat(ListStatik *l, ElTypeStat *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortListStat(ListStatik *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

void loadMakanan(ListStatik *l, char *filename);
/* Membaca list makanan dari file */
/* I.S. l sembarang */
/* F.S. l terisi makanan dari file konfigurasi */

void loadResep(ListStatik *l, ListStatik makan, char *filename);
/* Membaca resep makanan dari file */
/* I.S. l sembarang */
/* F.S. l terisi resep dari file konfigurasi */

void printResep(ListStatik resep);
/* I.S. resep terdefinisi */
/* F.s. Isi resep tercetak di layar */

ListStatik listMakananCommand(String com, ListStatik l);
/* Mengembalikan list statik yang berisi makanan dengan cara mendapat sesuai com
 * dari list l */

ListStatik splitString(String str);
/* Mengembalikan list statik yang berisi string satu kata yang berupa
   setiap kata yang terpisah spasi pada str */

#endif