#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#include "list.h"
#include "p_queue.h"

void DaftarHarga(void);
// { Proses : Membaca listHarga.txt dan memasukkannya ke array yang berisi daftar harga (tDaftarHarga). }

void ListItem(void);
// { Proses : Membaca karakterSpesial.txt dan memasukkannya ke array yang berisi daftar karakter khusus }
// { beserta kode ASCII-nya (tDaftarKar). }

void TulisListItem(void);
// { Proses : Menampilkan isi list karakter khusus ke layar. }
// { Pembacaan karakter khusus dilakukan langsung dari file eksternal. }

void BacaListFromFile(List * L, char * pitaKarakter);
// { Proses : Melakukan perekaman file ke suatu list yang telah terdefinisi }
// { Jika list tujuan telah terisi, hapus semua isi list tersebut terlebih dahulu. }

void BacaListForFile(List L, char * pitaKarakter);
// { Proses : Melakukan perekaman isi list ke suatu file. }
// { File ditulis dari awal (isi file sebelumnya ditimpa). }

void BacaPQueue(Queue * PQ);
// { Proses : Membaca file di folder Sending untuk ditambahkan ke priority queue. }
// { Jika priority queue telah diisi, hapus semua isi priority queue terlebih dahulu. }

void TulisPitakar(void);
// { Proses : Merekam pohon biner standar untuk kode Morse ke pitakar.txt }

#endif //KONFIGURASI_H
