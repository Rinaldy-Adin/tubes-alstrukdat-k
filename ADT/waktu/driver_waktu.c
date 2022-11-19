#include "waktu.h"
#include <stdio.h>

int main()
{
    TIME T1, T2, T3;
    CreateTime(&T1, 5, 13, 35);
    printf("Masukkan TIME dalam format DD HH MM : ");
    BacaTIME(&T2);
    printf("\nNilai T1 adalah:\n");
    TulisTIME(T1);
    printf("\nNilai T1 dalam bentuk short adalah:\n");
    TulisTIMEShort(T2);
    printf("\nT2 dalam menit:\n%ld\n", TIMEToMenit(T2));
    long menit = 15840;
    T3 = MenitToTIME(menit);
    printf("T3 jika total menitnya 15840 adalah:\n");
    TulisTIME(T3);
    printf("\nTentukan jika nilai T2 sama dengan T3!\n%d\n", TEQ(T1, T3));
    printf("Tentukan jika nilai T1 tidak sama dengan T2!\n%d\n", TNEQ(T1, T2));
    printf("Tentukan jika nilai T2 lebih kecil dari T3!\n%d\n", TLT(T2, T3));
    printf("Tentukan jika nilai T1 lebih besar dari T3!\n%d\n", TGT(T1, T3));
    printf("Waktu T3 jika dimajukan 1 menit adalah : \n");
    TIME T4 = NextMenit(T3);
    TulisTIME(T4);
    printf("\nWaktu T2 jika dimajukan 15 menit adalah : \n");
    TIME T5 = NextNMenit(T2, 15);
    TulisTIME(T5);
    printf("\nWaktu T1 jika dimundurkan 1 menit adalah : \n");
    TIME T6 = PrevMenit(T1);
    TulisTIME(T6);
    printf("\nWaktu T3 jika dimundurkan 15 menit adalah : \n");
    TIME T7 = PrevNMenit(T3, 15);
    TulisTIME(T7);
    printf("\nT7 jika dimajukan sebanyak 1 Hari 12 Jam 15 Menit adalah : \n");
    TIME T8 = SkipTime(T7,1,12,15);
    TulisTIME(T8);
    printf("\nT7 jila dimundurkan sebanyak 3 Hari 22 Jam 25 Menit adalah : \n");
    TIME T9 = RewindTime(T7,3,22,25);
    TulisTIME(T9);
    printf("\nPerbedaan waktu antara T1 dan T3 adalah:\n%ld\n", Durasi(T1, T3));
    printf("\nPerbedaan waktu antara T3 dan T1 adalah:\n%ld\n", Durasi(T3, T1));
}