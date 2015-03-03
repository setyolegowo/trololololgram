/* MODUS PENERIMAAN */

#ifndef ModusPenerimaan_h
#define ModusPenerimaan_h
#include "boolean.h"
#include "mesinKata_v1.h"

void TampilListPesan(void);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menampilkan list pesan-pesan yang telah terkirim pada folder inbox. Jika pesan berhasil
   terkirim, maka akan diletakkan pada folder "inbox", jika tidak, maka file pada folder "sending"
   harus dihapus. */

int HitJumlahPesan (void);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menghitung jumlah pesan pada folder inbox */
   
void AlfabetToSimbol(Kata CKata);
/* Mengubah representasi alfabet dari tanda baca, karakter khusus, dan enter menjadi simbol agar
   lebih mudah dibaca oleh pengguna. */

void BacaPesan(int i);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menampilkan pesan berdasarkan masukan id pesan dari pengguna. */
   
void HapusPesan(int i);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menghapus pesan berdasarkan masukan id pesan dari pengguna. Jika id terdefinisi maka pesan
   akan dihapus dari folder "inbox" dan tidak muncul lagi pada list pesan. */
   
Kata GetNamaPenerima(int id);
/* Mengambil nama penerima berdasarkan id pesan */

void UpdateStatistikPesan(Kata NamaPenerima);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Mengupdate statistik pembacaan yang telah diterima meliputi nama penerima, jumlah pesan yang
   diterima, dan jumlah pesan yang dibaca. */

void BacaStatistikPesan(void);
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Mencetak statistik pembacaan yang telah diterima meliputi nama penerima, jumlah pesan yang
   diterima, dan jumlah pesan yang dibaca. */

#endif
