/* File: time.c */
/* NIM: 13521172 */
/* Nama: Nathan Tenka */
/* Tanggal: 23 Oktober 2022 */
/* Deskripsi: implementasi ADT time */

#include <stdio.h>
#include "waktu.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M)
{
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (D >= 0 && H >= 0 && M >= 0 && H <= 23 && M <= 59);
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, HH, MM valid untuk membentuk TIME */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    Hari(*T) = DD;
    Jam(*T) = HH;
    Menit(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen DD, HH, MM sehingga membentuk T */
    /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
    dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
    diulangi hingga didapatkan jam yang valid. */
    /* Contoh: 
    60 3 4
    Jam tidak valid
    1 3 4
    --> akan terbentuk TIME <1,3,4> */
    /* KAMUS LOKAL */
    int d,h,m;

    /* ALGORITMA */
    do {
        scanf("%d %d %d", &d, &h, &m);
        if (IsTIMEValid(d,h,m) == 0) {
            printf("Jam tidak valid\n");
        }
    } while(IsTIMEValid(d,h,m) == 0);

    CreateTime(T, d, h, m);
}
   
void TulisTIME (TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format DD:HH:MM */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM
    tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
    /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("%d hari %d jam %d menit", Hari(T), Jam(T), Menit(T));
}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*DD + 60*HH + MM */
    /* Nilai maksimum = 3600*23+59*60+59 */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return (1440*Hari(T) + 60*Jam(T) + Menit(T));
}

TIME MenitToTIME (long N)
{
    /* Mengirim  konversi menit ke TIME */
    /* KAMUS LOKAL */
    TIME t;
    int d,h,m;

    /* ALGORITMA */
    d = (int) N/1440;
    h = (int) ((N%1440) / 60);
    m = ((N%1440) % 60);

    CreateTime(&t, d,h,m);
    return t;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (Hari(T1) == Hari(T2) && Jam(T1) == Jam(T2) && Menit(T1) == Menit(T2));
}

boolean TNEQ (TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (Hari(T1) != Hari(T2) || Jam(T1) != Jam(T2) || Menit(T1) != Menit(T2));
}

boolean TLT (TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) < TIMEToMenit(T2));
}

boolean TGT (TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (TIMEToMenit(T1) > TIMEToMenit(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextMenit (TIME T)
{
    /* Mengirim 1 menit setelah T dalam bentuk TIME */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return MenitToTIME(TIMEToMenit(T)+1);
}

TIME NextNMenit (TIME T, int N)
{
    /* Mengirim N menit setelah T dalam bentuk TIME */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return MenitToTIME(TIMEToMenit(T)+N);
}

TIME PrevMenit (TIME T) 
{
    /* Mengirim 1 menit sebelum T dalam bentuk TIME. Diasumsikan jumlah menit selalu > 0 (karena hari negatif tidak terdefinisi). */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return MenitToTIME(TIMEToMenit(T)-1);
}

TIME PrevNMenit (TIME T, int N)
{
    /* Mengirim N menit sebelum T dalam bentuk TIME. Diasumsikan jumlah menit selalu > N (karena hari negatif tidak terdefinisi). */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return MenitToTIME(TIMEToMenit(T)-N);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm menit. Jika negatif berarti TAkh sebelum TAw */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return ((TIMEToMenit(TAkh)) - TIMEToMenit(TAw));
}
