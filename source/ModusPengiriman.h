#ifndef M_PENGIRIMAN
#define M_PENGIRIMAN

#include "penulisan.h"
#include "mesinKata_v1.h"

void TransmitPesan (void);
// { Proses : Melakukan transmit pesan dengan melihat priority queue yang telah didefinisikan. }
// { Transmit pesan dilakukan dengan membuat file baru untuk diletakkan di folder setting. }
// { Pesan di folder setting telah diencode ke kode Morse. }
// { Encode ke Morse dilakukan dengan menggunakan pohon biner standar Morse (pitakar.txt) }

TipeNamaFile GetFirstFileOutbox(void);
// { Mengembalikan file pertama yang ada di outbox. }
// { Fungsi ini tidak akan membaca file berupa "." atau ".." (pointer current file). }

int HitJumlahPesanOutbox (void);
// { Mengembalikan jumlah pesan yang ada di outbox, 0 jika outbox kosong. }

void MakeNameFileSending (TipeNamaFile NamaFileLama, TipeNamaFile * NamaFileBaru);
// { Proses : Membuat nama direktori untuk file di folder Sending. }

void MakeNameFileInbox (TipeNamaFile NamaFileSending, TipeNamaFile * NamaFileInbox);
// { Proses : Membuat nama direktori untuk file di folder Inobx. }

void StatistikPengiriman (void);
// { Proses : Menampilkan statistik berupa jumlah pesan yang dikirim setiap jamnya. }
// { Statistik sebelumnya disimpan di sebuah file konfigurasi dan direkam ke dalam list. }

void UpdateStatistikPengiriman (void);
// { Proses : Memperbaharui statistik pengiriman jika proses transmisi untuk satu pesan selesai. }

int PanjangNamaFile (char * nama);
// { Mengembalikan jumlah karakter dari nama file pesan. }

int GetPriorityFile(TipeNamaFile NamaFile);
// { Mengembalikan nilai prioritas dari pesan. }

void SendingAfter30seconds(void);
// { Proses : Melakukan transmisi pesan setiap 30 detik. }
// { Pada proses ini juga terjadi perbaharuan statistik pengiriman. }
// { Prosesdur ini digunakan di semua modus agar transmisi dapat dilakukan }
// { walaupun pengguna tidak sedang berada di modus pengiriman. }

TipeNamaFile ConvertToNamaFile(Kata NamaFile);
// { Mengembalikan NamaFile yang bertipe Kata menjadi TipeNamaFile. }
// { Fungsi ini digunakan untuk menghindari konflik tipe. }

void UpdateStatistikPsn (Kata NamaPenerima);
// { Proses : Melakukan pembaharuan statistik pesan di modus penerimaan. }
// { Statistik yang diperbaharui meliputi jumlah pesan yang diterima dan }
// { jumlah pesan yang telah dibaca oleh pengguna tersebut. }

#endif
