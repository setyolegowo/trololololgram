/*	Nama/NIM	: Setyo Legowo/13511071
	Nama File	: modus_konfigurasi.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "modusKonfigurasi.h"
#include "endecode.h"
#include "mesinkar.h"
#include "list.h"
#include "interface.h"
#include "mesinKata_v1.h"
#include "konfigurasi.h"
#include "penulisan.h"

extern char CC;
extern char * Pita_karakter;
extern unsigned int tDaftarHarga[5];
extern struct {
	unsigned int kode;
	Kata nama;
} tDaftarKar[32];
extern int nKarReg;
extern Kata CKata;
extern List tDaftarPelanggan;

void show_daftarHarga(void)
{
	/* KAMUS LOKAL*/
	int n = 4;
	char * KtgHarga[] = {"Enter/Baris baru","Pendek (<= 11 Karakter)","Panjang (> 11 Karakter)","Tanda Baca","Lain-lain"};
	int i;
	
	/* ALGORITMA */
	DaftarHarga();
	for(i = 1; i <= n; i++)
	{
		printf("     Jenis kata %s seharga %d\n",KtgHarga[i],tDaftarHarga[i]);
	}
	printf("     Jenis kata %s seharga %d\n\n",KtgHarga[0],tDaftarHarga[0]);
}

void show_listItemKamus(void)
{
	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	ListItem();
	for(i = 0; i <= nKarReg; i++)
	{
		if(((i % 14) == 0) && (i != 0)) {
			printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
			Header2();
			printf ("\n                         .:: LIHAT LIST ITEM KAMUS ::.");
			printf ("\n  ---------------------------------------------------------------------------\n\n");
		}
		printf("       %c   - ",(char) tDaftarKar[i].kode);
		CetakKataToLayar(tDaftarKar[i].nama);
		printf("\n");
	}
	printf("\n");
}

void add_listItemKamus(void)
{
	/* KAMUS LOKAL */
	char input;
	Kata inputS;
	
	/* ALGORITMA */
	if(nKarReg < 30) {
		printf("  Masukkan karakter khusus yang akan ditambahkan : ");
		input = getchar();
		getchar();
		ListItem();
		while((SearchKar(input) != -1) || (isalnum(input))) {
			printf("\n  Warning: Karakter yang Anda masukkan terdefinisi di kamus atau termasuk karakter alphanumeric.\n");
			printf("  Masukkan karakter khusus yang akan ditambahkan : ");
			input = getchar();
			getchar();
			ListItem();
		};
		printf("\n  Masukkan kata untuk karakter khusus tersebut : ");
		readJustKata(&inputS);
		ListItem();
		while(MemberKar (inputS) != -1) {
			printf("\n  Warning: Kata yang Anda masukkan sudah terdaftar.\n");
			printf("  Masukkan kata untuk karakter khusus tersebut : ");
			readJustKata(&inputS);
			ListItem();
		}
		nKarReg++;
		tDaftarKar[nKarReg].kode = (int) input;
		tDaftarKar[nKarReg].nama = inputS;
		TulisListItem();
		printf("\n  Berhasil ditambahkan ke kamus.\n");
	} else {
		printf("  Tabel karakter penuh.\n");
	}
}

void del_listItemKamus(void)
{
	/* KAMUS LOKAL */
	char input;
	int Indeks, i;
	Kata TKata;
	
	/* ALGORITMA */
	if(nKarReg > 0) {
		printf("  Masukkan karakter khusus yang akan dihapus : ");
		input = getchar();
		getchar();
		ListItem();
		while((SearchKar(input) == -1) || (isalnum(input))) {
			printf("\n  Warning:\n  Karakter yang Anda masukkan tidak terdefinisi di kamus atau termasuk karakter alphanumeric.\n");
			printf("  Masukkan karakter khusus yang akan dihapus : ");
			input = getchar();
			getchar();
			ListItem();
		};
		Indeks = SearchKar(input);
		Pita_karakter = "Pengaturan/karakterSpesial.txt";
		STARTW();
		for(i = 0; i <= nKarReg; i++)
		{
			if(i != Indeks) {
				if(i != 0) WRITE(' ');
				// Merubah integer ke 3 integer bentuk karakter
				TKata = BilToKata(tDaftarKar[i].kode, 3);
				CetakKataToFile(TKata);
				WRITE(' ');
				CetakKataToFile(tDaftarKar[i].nama);
			}
		}
		WRITE(MARK);
		CLOSETULIS();
		nKarReg--;
		printf("\n  Proses penghapusan berhasil.\n");
	} else {
		printf("  Tabel kosong");
	}
}

void show_listPelanggan(void)
{
	/* KAMUS LOKAL */
	address P;
	int i, NElmt;
	
	/* ALGORITMA */
	BacaListFromFile(&tDaftarPelanggan, "Pengaturan/listPelanggan.txt");
	if(!IsListEmpty(tDaftarPelanggan)) {
		P = First(tDaftarPelanggan);
		NElmt = NbElmt(tDaftarPelanggan);
		for(i = 1; i <= NElmt; i++)
		{
			if((i % 15) == 0) {
				printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
				Header2();
				printf ("\n                         .:: LIHAT LIST PELANGGAN ::.");
                printf ("\n  ---------------------------------------------------------------------------\n\n");
			}
			printf("  %d. ",i);
			CetakKataToLayar(Info(P,1));
			printf("\n");
			P = Next(P);
		}
	} else {
		printf("  Daftar pelanggan kosong.\n");
	}
}

void add_listPelanggan(void)
{
	/* KAMUS LOKAL */
	Kata inputS;
	address PBaru;
	
	/* ALGORITMA */
	printf("  Masukkan nama pengguna baru : ");
	readJustKata(&inputS);
	BacaListFromFile(&tDaftarPelanggan, "Pengaturan/listPelanggan.txt");
	while((Search (tDaftarPelanggan, inputS, 1) != Nil) || (inputS.Length == 0)) {
		printf("\n  Warning: Nama pengguna baru yang Anda masukkan sudah terdaftar atau gagal membaca.\n");
		printf("  Masukkan nama pengguna baru : ");
		readJustKata(&inputS);
		BacaListFromFile(&tDaftarPelanggan, "Pengaturan/listPelanggan.txt");
	}
	PBaru = Alokasi(inputS,1);
	if(IsListEmpty(tDaftarPelanggan))
		InsertFirst(&tDaftarPelanggan, PBaru);
	else
		InsertLast(&tDaftarPelanggan, PBaru);
	BacaListForFile(tDaftarPelanggan,"Pengaturan/listPelanggan.txt");
	printf("\n  Nama pengguna baru tersimpan dengan baik.\n\n");
}

void del_listPelanggan(void)
{
	/* KAMUS LOKAL */
	Kata inputS;
	
	/* ALGORITMA */
	if(!IsListEmpty(tDaftarPelanggan)) {
		printf("  Masukkan nama pengguna yang akan dihapus : ");
		readJustKata(&inputS);
		BacaListFromFile(&tDaftarPelanggan, "Pengaturan/listPelanggan.txt");
		while(Search (tDaftarPelanggan, inputS, 1) == Nil) {
			printf("\n  Warning:\n  Nama pengguna baru yang Anda masukkan tidak terdaftar.\n");
			printf("  Masukkan nama pengguna yang akan dihapus : ");
			readJustKata(&inputS);
			BacaListFromFile(&tDaftarPelanggan, "Pengaturan/listPelanggan.txt");
		}
		DeleteP(&tDaftarPelanggan, inputS, 1);
		BacaListForFile(tDaftarPelanggan,"Pengaturan/listPelanggan.txt");
		printf("\n  Nama pengguna ");
		CetakKataToLayar(inputS);
		printf(" dihapus dari daftar.\n");
	} else {
		printf("  List pelanggan kosong. Proses menghapus pengguna dibatalkan.\n");
	}
}
