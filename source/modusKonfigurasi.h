/* Nama/NIM	: Setyo Legowo/13511071
 * Nama File	: modus_konfigurasi.h
 * 
*/

#ifndef MODUS_KONFIGURASI_H
#define MODUS_KONFIGURASI_H

void show_daftarHarga(void);
// { Proses : Menampilkan isi tDaftarHarga. }

void show_listItemKamus(void);
// { Proses : Menampilkan isi tDaftarKar. }

void add_listItemKamus(void);
// { Proses : Menambah isi list item kamus secara persisten ke file eksternal. }

void del_listItemKamus(void);
// { Proses : Menghapus isi list item kamus secara persiten di file eksternal. }

void show_listPelanggan(void);
// { Proses : Menampilkan isi tDaftarPelanggan. }

void add_listPelanggan(void);
// { Proses : Menambah pelanggan secara persisten ke file eksternal. }

void del_listPelanggan(void);
// { Proses : Menghapus pelanggan secara persisten di file eksternal. }

#endif
