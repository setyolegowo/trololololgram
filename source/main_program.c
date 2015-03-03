/* ######################### TUGAS BESAR ###############################
 * 
 * Kelompok : 2
 * Nama/NIM :
 * 	-> Arief Rahman/13511020
 *  -> Azalea Fisitania/13511028
 *  -> Dinah Kamilah Ulfa/13511087
 *  -> Rifki Afina Putri/13511066
 *  -> Setyo Legowo/13511071
 * 
 * Kelas : 3
 * Mata Kuliah : IF2030/Algoritma dan Struktur Data
 * Tahun Ajaran : 2012/2013
 * Nama File : main_program.c
 * Deskripsi : 
*/

/* ****************************************************************** */
/*                              HEADER                                */
/* ****************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "boolean.h"
#include "list.h"
#include "p_queue.h"
#include "mesinkar.h"
#include "interface.h"
#include "konfigurasi.h"
#include "modusKonfigurasi.h"
#include "ModusPenerimaan.h"
#include "ModusPengiriman.h"
#include "penulisan.h"

// ######################### KAMUS GLOBAL ########################### 
extern char * Pita_karakter;
extern char CC;
boolean EndKata;

List statistik_inboks;
List statistik_outboks;
List statistik_sending;
unsigned int tDaftarHarga[5];
struct {
	unsigned int kode;
	Kata nama;
} tDaftarKar[32];
int nKarReg;
time_t Curtime, timeafter;
List tDaftarPelanggan;
Queue tQueue;

// ############# DEFINISI DAN SPESIFIKASI SUB-PROGRAM ############### 
void CheckFileFolder(char * name, char dOf);
// { I.S. : name dan dOf terdefinisi }
// { F.S. : Terbentuk folder atau file kosong sesuai dengan namanya jika
//          file yang ditunjuk tidak ditemukan }
// { Name adalah nama hierarki file atau folder dari program tersebut berjalan }
// { Jika dOf = 'd' maka name adalah direktori, jika dOf = 'f' maka name adalah
//   nama file. }
boolean __inisialisasi();
// { Inisialisasi berguna untuk mengecek dan mempersiapkan segala sesuatu yang
//   akan digunakan saat program berjalan. }

// ######################## PROGRAM UTAMA ########################### 
int main() {
	// KAMUS LOKAL
	boolean IsInitSukses;
	unsigned int pilih1, pilih2, id;
	// i_menu digunakan untuk kondisi menu mana yang dipilih
	
	// ALGORITMA
	InisialisasiUI();
	IsInitSukses = __inisialisasi();
	printf("\n Tekan tombol Enter untuk melanjutkan...");
	getchar();
	SendingAfter30seconds();
	if(IsInitSukses == true) {
		do {
			Header();
			Menu();
			scanf("%d", &pilih1);
			getchar();
			SendingAfter30seconds();
			switch(pilih1) {
				case 1:
					do {
						Header();
						ModusA();
						scanf("%d",&pilih2);
						SendingAfter30seconds();
						getchar();
						Header2();
						switch(pilih2) {
							case 1:
								printf ("\n                              .:: TULIS PESAN ::.");
								printf ("\n  ---------------------------------------------------------------------------\n");
								Kirim();
								printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Penulisan > ");
								getchar();
							    break;
							case 2:
                                printf ("\n                      .:: HITUNG HARGA PESAN TERAKHIR ::.");
                                printf ("\n  ---------------------------------------------------------------------------\n");
								HitungHargaTerakhir();
                                printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Penulisan > ");
								getchar();
							    break;
							case 3:
                                printf ("\n                      .:: STATISTIK PESAN PENGIRIMAN ::.");
                                printf ("\n  ---------------------------------------------------------------------------\n");
								StatistikTulis();
                                printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Penulisan > ");
								getchar();
							    break;
						}
						SendingAfter30seconds();
					} while ((pilih2 != 8) && (pilih2 != 9));
				break;
				case 2:
					do {
						Header();
						ModusB();
						scanf("%d",&pilih2);
						getchar();
						SendingAfter30seconds();
						Header2();
						switch(pilih2) {
							case 1:
								printf ("\n                         .:: TRANSMIT SEMUA PESAN ::.");
								printf ("\n  ---------------------------------------------------------------------------\n\n");
								TransmitPesan();
								printf ("pesan telah dikirim.\n");
								printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Pengiriman > ");
								getchar();
							    break;
							case 7:
                                printf ("\n                         .:: STATISTIK PENGIRIMAN ::.");
								printf ("\n  ---------------------------------------------------------------------------\n\n");
								StatistikPengiriman ();
								printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Pengiriman > ");
								getchar();
							    break;
                        }
						SendingAfter30seconds();
					} while ((pilih2 != 8) && (pilih2 != 9));
				break;
				case 3:
					do {
						Header();
						ModusC();
						scanf("%d",&pilih2);
						SendingAfter30seconds();
						getchar();
						if (((pilih2 <= 3) && (pilih2 >= 1)) || (pilih2 == 7)) {
							Header2();
							switch(pilih2) {
								case 1 :
									printf ("\n                         .:: LIST PESAN PENERIMAAN ::.");
									printf ("\n  ---------------------------------------------------------------------------\n\n");
									TampilListPesan();
								    break;
								case 2 : 
                                    printf ("\n                              .:: BACA PESAN ::.");
									printf ("\n  ---------------------------------------------------------------------------\n\n");
									printf ("  Perhatian: ID pesan dapat dilihat di \"List Pesan\"\n\n");
									printf ("  Masukkan id pesan : ");
									scanf ("%d", &id);
									getchar();
									printf ("  ___________________________________________________________________________\n\n");
									BacaPesan(id);
								    break;
								case 3 : 
                                    printf ("\n                              .:: HAPUS PESAN ::.");
									printf ("\n  ---------------------------------------------------------------------------\n\n");
									printf ("  Perhatian:\n");
									printf ("    - Pesan yang sudah dihapus tidak dapat dikembalikan\n");
									printf ("    - ID pesan dapat dilihat di \"List Pesan\"\n\n");
									printf ("  Masukkan id pesan : ");
									scanf ("%d", &id);
									getchar();
									HapusPesan(id);
								    break;
								case 7 : 
                                    printf ("\n                         .:: STATISTIK PESAN MASUK ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									BacaStatistikPesan(); 
                                    break;
							}
							printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Penerimaan > ");
							getchar();
							SendingAfter30seconds();
						}
					} while ((pilih2 != 8) && (pilih2 != 9));
				break;
				case 4:
					do {
						Header();
						ModusD();
						scanf("%d",&pilih2);
						SendingAfter30seconds();
						getchar(); // Menghapus karakter enter
						if((pilih2 != 9) && (pilih2 != 8) && (pilih2 < 8) && (pilih2 >= 1)) {
							Header2();
							switch(pilih2) {
								case 1 : 
                                    printf ("\n                              .:: DAFTAR HARGA ::.");
									printf ("\n  ---------------------------------------------------------------------------\n\n");
                                    show_daftarHarga(); 
                                    break;
								case 2 : 
                                    printf ("\n                         .:: LIHAT LIST ITEM KAMUS ::.");
									printf ("\n  ---------------------------------------------------------------------------\n\n");
                                    show_listItemKamus();
                                    break;
								case 3 : 
                                    printf ("\n                        .:: TAMBAH LIST ITEM KAMUS ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									add_listItemKamus(); 
                                    break;
								case 4 : 
                                    printf ("\n                           .:: HAPUS ITEM KAMUS ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									del_listItemKamus(); 
                                    break;
								case 5 : 
                                    printf ("\n                         .:: LIHAT LIST PELANGGAN ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									show_listPelanggan(); 
                                    break;
								case 6 : 
                                    printf ("\n                            .:: TAMBAH PELANGGAN ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									add_listPelanggan(); 
                                    break;
								case 7 : 
                                    printf ("\n                            .:: HAPUS PELANGGAN ::.");
                                    printf ("\n  ---------------------------------------------------------------------------\n\n");
									del_listPelanggan(); 
                                    break;
							}
							printf("\n  Tekan tombol ENTER atau RETURN untuk kembali ke Modus Pengaturan > ");
							SendingAfter30seconds();
							getchar();
						}
					} while((pilih2 != 9) && (pilih2 != 8));
				break;
			}
		} while (pilih2 != 9);
	} else {
		// Tampilkan informasi kenapa inisialisasi gagal
	}
	penutup();
	delay(2);
	return 0;
}

// #################### REALISASI SUB-PROGRAM #######################
void CheckFileFolder(char * name, char dOf)
{
	struct stat st;
	FILE *fp;
	
	if(stat(name,&st) != 0)
	{
		printf(" %s tidak ditemukan. Create it...",name);
		if(dOf == 'd') {
			mkdir(name,S_IRWXU);
		} else if (dOf == 'f') {
			fp = fopen(name,"w");
			fprintf(fp,"%c",MARK);
			fclose(fp);
		}
		printf("\n");
	} //else printf(" %s ditemukan.\n",name);
}

boolean __inisialisasi()
{
	// KAMUS LOKAL
	boolean CurrentBoolean;
	
	// ALGORITMA
	CurrentBoolean = false;
	// Cek apakah direktori dan file yang digunakan program ini ada atau
	// tidak. Lalu, jika tidak ada dibuat direktori dan file defaultnya.
	CheckFileFolder("Inbox",'d');
	CheckFileFolder("Outbox",'d');
	CheckFileFolder("Pengaturan",'d');
	CheckFileFolder("Pengaturan/karakterSpesial.txt",'f');
	CheckFileFolder("Pengaturan/listHarga.txt",'f');
	CheckFileFolder("Pengaturan/listPelanggan.txt",'f');
	CheckFileFolder("Pengaturan/pitakar.txt",'f');
	CheckFileFolder("Pengaturan/statistik.date.txt",'f');
	CheckFileFolder("Pengaturan/statistik.pelanggan.txt",'f');
	CheckFileFolder("Pengaturan/statistik.pesan.txt",'f');
	CheckFileFolder("Sending",'d');
	
	// Mengambil informasi konfigurasi dari file
	// -> Mengambil informasi daftar harga
	printf("    Membaca daftar Harga... ");
	DaftarHarga();
	printf("SELESAI\n");
	// -> Mengambil list item kamus
	printf("    Membaca daftar karakter khusus... ");
	ListItem();
	printf("SELESAI\n");
	// -> List pelanggan
	printf("    Membaca daftar pelanggan... ");
	CreateList(&tDaftarPelanggan,1);
	BacaListFromFile(&tDaftarPelanggan,"Pengaturan/listPelanggan.txt");
	printf("SELESAI\n");
	
	// Mengambil informasi statistik dari file
	// -> Baca statistik pelanggan
	printf("    Membaca statistik Penulisan... ");
	CreateList(&statistik_outboks,4);
	BacaListFromFile(&statistik_outboks,"Pengaturan/statistik.pelanggan.txt");
	printf("SELESAI\n");
	// -> Baca statistik 
	printf("    Membaca statistik Pengiriman... ");
	CreateList(&statistik_sending,3);
	BacaListFromFile(&statistik_sending,"Pengaturan/statistik.date.txt");
	printf("SELESAI\n");
	// -> Baca statistik pesan
	printf("    Membaca statistik Penerimaan... ");
	CreateList(&statistik_inboks,3);
	BacaListFromFile(&statistik_inboks,"Pengaturan/statistik.pesan.txt");
	printf("SELESAI\n");
	// Reset Time
	Curtime = time(NULL);
	timeafter = Curtime;
	
	// Menulis pitakar
	TulisPitakar();
	
	// Mengurutkan kembali queue
	printf("    Mengantrikan kembali pesan yang dikirim... ");
	CreateEmpty(&tQueue);
	BacaPQueue(&tQueue);
	printf("SELESAI\n");
	
	CurrentBoolean = true;
	return CurrentBoolean;
}
