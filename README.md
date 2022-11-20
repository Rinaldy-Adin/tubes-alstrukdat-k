# Tugas Besar 2 Alstrukdat Kelompok K K2

# BINOMO Cooking Simulator

## Penjelasan Singkat Program

Suatu hari BNMO diminta temannya untuk membantu membuat suatu makanan yang spesial. Akan tetapi, BNMO perlu belajar memasak terlebih dahulu. Untuk itu, BNMO memerlukan sebuah program simulasi memasak.

Program simulasi memasak ini adalah program berbasis CLI yang dibuat dalam bahasa C. Dalam program ini digunakan berbagai ADT seperti list statik, priority queue berbasis list dinamik, stack, dll. Pengguna bisa melakukan beragam aksi, seperti berpindah posisi, mengolah dan memesan makanan, dll.

## Cara Kompilasi dan Menjalankan Program

1. Pada directory utama, ketik command `make` untuk mengcompile semua file yang ada. ([Pengguna windows perlu install make terlebih dahulu](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows))
    ```
    $ make
    ```
2. Pastikan sudah memiliki GCC atau compiler C lainnya. Lalu, ketik "main" atau "main.exe" untuk menjalankan program.
    ```
    $ ./main.exe
    ```
3. Akan muncul splash screen dan permintaan input START/EXIT. Untuk masuk ke simulasi, ketik START dan masukkan nama pengguna.

    ```
    Enter START/EXIT: START

    =========================================

    Masukkan nama anda :
    ```

4. Berikutnya akan muncul peta dan perintah-perintah lain sudah bisa langsung dijalankan.
    ```
    Enter command:
    ```

## Pembagian Tugas

| Nama                  | NIM      | Pembagian Tugas                                                                                      |
| --------------------- | -------- | ---------------------------------------------------------------------------------------------------- |
| Naufal Nalendra       | 13521152 | ADT Waktu                                                                                            |
| Ammar Rasyad Chaeroel | 13521136 | ADT Tree, ADT Priority Queue                                                                         |
| Rinaldy Adin          | 13521134 | Inisiasi Program, Command Parser, ADT Stack, ADT Simulator, UNDO/REDO, Notifikasi, Main loop program |
| Haziq Abiyyu Mahdy    | 13521170 | ADT Point, ADT Matrix, Peta, ADT Kulkas                                                              |
| Nathan Tenka          | 13521172 | ADT Makanan, ADT List Statik, ADT Set, ADT Tree, Load makanan dan resep, Rekomendasi makanan         |

## Daftar Fitur dan Status Pengerjaannya

1. Start Screen : Selesai
2. Load katalog makanan, resep, dan peta dari file : Selesai
3. Kadaluarsa makanan : Selesai
4. Mekanisme waktu termasuk lama aksi yang berbeda per jenis makanan (Bonus 2) : Selesai
5. MOVE : Selesai
6. CATALOG : Selesai
7. COOKBOOK : Selesai
8. INVENTORY : Selesai
9. RECOMMEND (Rekomendasi makanan, Bonus 3) : Selesai
10. DELIVERY (Daftar pesanan) : Selesai
11. UNDO/REDO : Selesai
12. KULKAS (Bonus 1) : Selesai
13. BUY : Selesai
14. FRY,MIX,CHOP,BOIL (Pengolahan makanan) : Selesai
15. WAIT : Selesai
16. Notifikasi : Selesai
17. EXIT : Selesai

## Struktur Program

```
├── ADT
│   ├── boolean.h
│   ├── charmachine
│   │   ├── charmachine.c
│   │   ├── charmachine.h
│   │   └── driver_charmachine.c
│   ├── kulkas
│   │   ├── driver_kulkas.c
│   │   ├── driver_kulkas.exe
│   │   ├── kulkas.c
│   │   └── kulkas.h
│   ├── liststatik
│   │   ├── driver_listStatik.c
│   │   ├── driver_listStatik.exe
│   │   ├── listStatik.c
│   │   ├── listStatik.h
│   │   ├── pita.txt
│   │   └── pitaResep.txt
│   ├── makanan
│   │   ├── driver_makanan.c
│   │   ├── driver_makanan.exe
│   │   ├── makanan.c
│   │   └── makanan.h
│   ├── matrix
│   │   ├── driver_matrix.c
│   │   ├── driver_matrix.exe
│   │   ├── matrix.c
│   │   └── matrix.h
│   ├── point
│   │   ├── driver_point.c
│   │   ├── driver_point.exe
│   │   ├── point.c
│   │   └── point.h
│   ├── prioqueue
│   │   ├── driver_prioqueue.c
│   │   ├── driver_prioqueue.exe
│   │   ├── prioqueue.c
│   │   └── prioqueue.h
│   ├── set
│   │   ├── driver_set.c
│   │   ├── driver_set.exe
│   │   ├── pita.txt
│   │   ├── pitaResep.txt
│   │   ├── set.c
│   │   └── set.h
│   ├── simulator
│   │   ├── driver_simulator.c
│   │   ├── driver_simulator.exe
│   │   ├── simulator.c
│   │   └── simulator.h
│   ├── stack
│   │   ├── stack.c
│   │   └── stack.h
│   ├── strlib
│   │   ├── driver_strlib.c
│   │   ├── driver_strlib.exe
│   │   ├── strlib.c
│   │   └── strlib.h
│   ├── tree
│   │   ├── driver_tree.c
│   │   ├── driver_tree.exe
│   │   ├── tree.c
│   │   └── tree.h
│   ├── waktu
│   │   ├── driver_waktu.c
│   │   ├── driver_waktu.exe
│   │   ├── waktu.c
│   │   └── waktu.h
│   └── wordmachine
│       ├── driver_wordmachine.c
│       ├── wordmachine.c
│       └── wordmachine.h
├── Makefile
├── README.md
├── boolean.h
├── main.c
├── main.exe
├── peta.txt
├── pita.txt
├── pitaResep.txt
├── programs
│   ├── iolib
│   │   ├── boolean.h
│   │   ├── cmdline.c
│   │   ├── cmdline.h
│   │   ├── driver_cmdline.exe
│   │   ├── peta.txt
│   │   ├── pita.txt
│   │   ├── pitaResep.txt
│   │   ├── splash.c
│   │   └── splash.h
│   ├── makanan
│   │   ├── inventory.c
│   │   ├── inventory.h
│   │   ├── order.c
│   │   └── order.h
│   └── peta
│       ├── cmdPeta.c
│       ├── cmdPeta.h
│       ├── driver_CmdPeta.c
│       ├── driver_CmdPeta.exe
│       └── peta.txt
└── utils
    ├── mathops.c
    └── mathops.h
```
