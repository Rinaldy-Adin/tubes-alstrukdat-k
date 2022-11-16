/* Deskripsi: implementasi ADT time */

#include "waktu.h"

#include <stdio.h>

/* *** Fungsi Aritmatika *** */
#define mod(x, k) (((x % k) + k) % k)

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid(int D, int H, int M) {
    /* Mengirim true jika D,H,M dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return ((D >= 0) && (D <= 30) && ((H >= 0) && (H <= 23)) &&
            ((M >= 0) && (M <= 59)));
}

boolean IsTimeZero(TIME *T) {
    /* Mengirim true jika D,H,M dari Time T berbentuk 0:0:0 */
    return (Hari(*T) == 0) && (Jam(*T) == 0) && (Menit(*T) == 0);
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int DD, int HH, int MM) {
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, HH, MM valid untuk membentuk TIME */
    if (IsTIMEValid(DD, HH, MM) == true) {
        Hari(*T) = DD;
        Jam(*T) = HH;
        Menit(*T) = MM;
    }
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME(TIME *T) {
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen DD, HH, MM sehingga membentuk T */
    /* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan
       pembacaan diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
       60 3 4
       Jam tidak valid
       1 3 4
       --> akan terbentuk TIME <1,3,4> */

    int DD, HH, MM;
    boolean valid = false;

    while (valid != true) {
        scanf("%d %d %d", &DD, &HH, &MM);

        if (IsTIMEValid(DD, HH, MM) == true) {
            CreateTime(T, DD, HH, MM);
            valid = true;
        } else
            printf("Time tidak valid\n");
    }
}

void TulisTIME(TIME T) {
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format DD:HH:MM */
    /* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter,
       dll.*/
    int DD, HH, MM;

    DD = Hari(T);
    HH = Jam(T);
    MM = Menit(T);

    printf("%d hari %d jam %d menit", DD, HH, MM);
}

void TulisTIMEShort(TIME T) {
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format D hari H jam M menit secara singkat */
    int DD, HH, MM;

    DD = Hari(T);
    HH = Jam(T);
    MM = Menit(T);

    if (DD > 0) {
        printf("%d hari %d jam %d menit", DD, HH, MM);
    } else if (HH > 0) {
        printf("%d jam %d menit", HH, MM);
    } else {
        printf("%d menit", MM);
    }
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit(TIME T) {
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah Menit dari pukul 0:0:0
     */
    /* Rumus : minute = 1440 * DD + 60 * HH + MM */
    /* Nilai maksimum = 29 * 1440 + 23*60 + 59 */
    /*KAMUS LOKAL*/

    long jumlah = Hari(T) * 1440 + Jam(T) * 60 + Menit(T);

    return jumlah;
}

TIME MenitToTIME(long N) {
    /* Mengirim  konversi minute ke TIME */
    /* Catatan: Jika N >= 43200, maka harus dikonversi dulu menjadi jumlah
       minute yang mewakili jumlah minute yang mungkin dalam 1 hari, yaitu
       dengan rumus: N1 = N mod 43200, baru N1 dikonversi menjadi TIME */
    long N1;
    long DD, HH, MM, sisa;
    TIME T;
    boolean loop;

    N1 = mod(N, 43200);

    DD = (int)N1 / 1440;
    sisa = N1 % 1440;
    HH = (int)sisa / 60;
    MM = (int)sisa % 60;

    CreateTime(&T, DD, HH, MM);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2) {
    /* Mengirimkan true jika T1=T2, false jika tidak */

    return (Hari(T1) == Hari(T2)) && (Jam(T1) == Jam(T2)) &&
           (Menit(T1) == Menit(T2));
}
boolean TNEQ(TIME T1, TIME T2) {
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    return (Hari(T1) != Hari(T2)) || (Jam(T1) != Jam(T2)) ||
           (Menit(T1) != Menit(T2));
}
boolean TLT(TIME T1, TIME T2) {
    /* Mengirimkan true jika T1<T2, false jika tidak */
    /*KAMUS LOKAL*/
    long minute1, minute2;

    /*ALGORITMA*/
    minute1 = TIMEToMenit(T1);
    minute2 = TIMEToMenit(T2);

    return (minute1 < minute2);
}
boolean TGT(TIME T1, TIME T2) {
    /* Mengirimkan true jika T1>T2, false jika tidak */
    /*KAMUS LOKAL*/
    long minute1, minute2;

    /*ALGORITMA*/
    minute1 = TIMEToMenit(T1);
    minute2 = TIMEToMenit(T2);

    return (minute1 > minute2);
}
/* *** Operator aritmatika TIME *** */
TIME NextMenit(TIME T) {
    /* Mengirim 1 minute setelah T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long minute;

    /*ALGORITMA*/
    minute = TIMEToMenit(T);
    minute = minute + 1;

    return MenitToTIME(minute);
}
TIME NextNMenit(TIME T, int N) {
    /* Mengirim N minute setelah T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long minute;

    /*ALGORITMA*/
    minute = TIMEToMenit(T);
    minute = minute + N;

    return MenitToTIME(minute);
}
TIME PrevMenit(TIME T) {
    /* Mengirim 1 minute sebelum T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long minute;

    /*ALGORITMA*/
    minute = TIMEToMenit(T);
    minute = minute - 1;

    return MenitToTIME(minute);
}
TIME PrevNMenit(TIME T, int N) {
    /* Mengirim N minute sebelum T dalam bentuk TIME */
    /*KAMUS LOKAL*/
    long minute;

    /*ALGORITMA*/
    minute = TIMEToMenit(T);
    minute = minute - N;

    return MenitToTIME(minute);
}
TIME SkipTime(TIME T, int D, int H, int M) {
    /* Memajukan Time sebanyak D hari, H jam, dan M menit */
    /*KAMUS LOKAL*/
    long current;
    long skip;

    /*ALGORITMA*/
    current = TIMEToMenit(T);
    skip = D * 1440 + 60 * H + M;
    current = current + skip;

    return MenitToTIME(current);
}
TIME RewindTime(TIME T, int D, int H, int M) {
    /* Memundurkan Time sebanyak D hari, H jam, dan M menit */
    /*KAMUS LOKAL*/
    long current;
    long rewind;

    /*ALGORITMA*/
    current = TIMEToMenit(T);
    rewind = D * 1440 + 60 * H + M;
    current = current - rewind;

    return MenitToTIME(current);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh) {
    /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
    /*KAMUS LOKAL*/
    long minute1, minute2, difference;

    /*ALGORITMA*/
    minute1 = TIMEToMenit(TAw);
    minute2 = TIMEToMenit(TAkh);

    if (minute1 > minute2) {
        difference = 43200 - (minute1 - minute2);
    } else {
        difference = minute2 - minute1;
    }

    return difference;
}