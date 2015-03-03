/* NIM/Nama 	: 13511087 / Dinah Kamilah Ulfa 										  
   Nama file 	: penulisan.h
   Topik 		: 
   Tanggal 		: 
   Deskripsi 	: */

#ifndef penulisan_h
#define penulisan_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "boolean.h"
#include "endecode.h"
#include "mesinKata_v1.h"
#include "list.h"
#include "modusKonfigurasi.h"
#include "konfigurasi.h"

#define size 100
time_t timer;
char str[size];
const char *format;
struct tm *timeptr;
typedef struct 
{
	char TabKata[size];
	int Length;
} TipeNamaFile;

boolean identitas (Kata snd);
// { Mengembalikan nilai true jika nama pengirim dan penerima telah }
// { terdaftar pada sistem sebagai pelanggan, false jika tidak. }
// { Keterangan : snd : sender   : pengirim }
// {              rcv : receiver : penerima }

boolean teschar (Kata psn);
// { Mengembalikan nilai true jika seluruh tanda baca dan karakter khusus telah terdefinisi di kamus,
// { false jika tidak. }

void readJustKata (Kata *k);
// { Proses : Membaca hanya kata pertama yang ditulis dengan kata lain karakter-karakter }
// { sebelum karakter enter, spasi, dan karakter selain alphanumeric }

void Read (Kata *k);
// { Proses : membaca nama pengirim, penerima, dan pesan. }

void MakeNameFile (Kata Nama, TipeNamaFile *NamaFile);
// { Proses : Membuat nama file sesuai waktu pesan dibuat. }

void translate (char Prio, Kata snd, Kata rcv, Kata psn);
// { Proses : Mengubah dan merekam pesan ke file ke folder outbox. }

void Kirim (void);
// { Proses : Menulis pesan dan membuat file pesan baru di folder Outbox. }
// { Prosedur ini juga menperbaharui statistik di modus penulisan. }

void HitungHarga (Kata snd, Kata rcv);
// { Proses : Mengembalikan nilai total harga telegram yang dibaca dari file konfigurasi. }

void HitungHargaTerakhir (void);
// { Proses : Menampilkan statistik harga terakhir pesan yang dikirim. }
// { Jika tidak ada pesan yang dikirim, maka ditampilkan harga kosong (0). }

void StatistikTulis(void);
// { Proses : Menampilkan total jumlah pesan yang dikirim, total harga, dan jumlah rata-rata kata per pesan }
// { per pelanggan yang terdaftar (yang sudah pernah mengirimkan pesan). }

void UpdateStatistik(Kata NamaPengirim);
// { Proses : Memperbaharui statistik setiap pengguna yang telah mengirimkan pesan. }

#endif
