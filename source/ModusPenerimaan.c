/* MODUS PENERIMAAN */

#include "interface.h"
#include "boolean.h"
#include "mesinKata_v1.h"
#include "ModusPenerimaan.h"
#include "endecode.h"
#include "konfigurasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include "list.h"

extern char * Pita_karakter;
extern Kata CKata;
extern boolean EndKata;
extern struct {
	unsigned int kode;
	Kata nama;
} tDaftarKar[32];
extern List statistik_inboks;

void TampilListPesan (void)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menampilkan list pesan-pesan yang telah terkirim pada folder inbox. */
{
	// Kamus Lokal
	int i;
	DIR *dir;
	struct dirent *direntry;
	struct stat st;
	char ifile[100];
	
	// Algoritma
	dir = opendir("./Inbox");
	i = 1;
	while ((direntry = readdir(dir)) != NULL) {
		snprintf(ifile,100,"Inbox/%s",direntry->d_name);
		if((stat(ifile,&st) == 0) && (ifile[6] != '.')) {
			if((i % 15) == 0) {
				printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
				Header2();
				printf ("\n                         .:: LIST PESAN PENERIMAAN ::.");
				printf ("\n  ---------------------------------------------------------------------------\n\n");
			}
			printf("  %d. %s",i,ifile);
			printf("\n");
			i++;
		}
	}
	closedir(dir);
	if(i == 0)
		printf("  Pesan tidak ada (kosong).\n");
}

int HitJumlahPesan (void)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menghitung jumlah pesan pada folder inbox */
{
	// Kamus Lokal
	int jumlah;
	DIR *dir;
	struct dirent *direntry;
	struct stat st;
	char ifile[100];
	
	// Algoritma
	dir = opendir("./Inbox");
	jumlah = 0;
	while ((direntry = readdir(dir)) != NULL) {
		snprintf(ifile,100,"Inbox/%s",direntry->d_name);
		if((stat(ifile,&st) == 0) && (ifile[6] != '.')) {
			jumlah++;
		}
	}
	return (jumlah);
}

void AlfabetToSimbol (Kata CKata)
/* Mengubah representasi alfabet dari tanda baca, karakter khusus, dan enter menjadi simbol agar
   lebih mudah dibaca oleh pengguna. */
{
	// Kamus Lokal
	Kata KataENTER;
	sprintf(KataENTER.TabKata, " ENTER");
	KataENTER.Length = 5;
	int iKar;
	
	// Algoritma
	iKar = MemberKar(CKata);
	if (iKar != -1) {
		printf("%c",(char) tDaftarKar[iKar].kode);
	} else if (IsKataSama(CKata, KataENTER)) {
		printf("\n  ");
	} else {  	// CKata selain kata yang menunjukkan tanda baca
		printf(" ");
		CetakKataToLayar(CKata);
	}
}

void BacaPesan (int id)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menampilkan pesan berdasarkan masukan id pesan dari pengguna. */
{
	
	// Kamus Lokal
	int i;
	DIR *dir;
	struct dirent *direntry;
	char ifile[100];
	struct stat st;
	
	// Algoritma
	if ((id > 0) && (id <= HitJumlahPesan())) {
		dir = opendir("./Inbox");
		i = 0;
		while(((direntry = readdir(dir)) != NULL) && (i < id)) {
			sprintf(ifile, "Inbox/%s", direntry->d_name);
			if((stat(ifile,&st) == 0) && (ifile[6] != '.'))
				i++;
		}
		//for (i=0;i<=id+1;i++) {
			//direntry = readdir(dir);
		//}
		//sprintf(ifile, "Inbox/%s", direntry->d_name);
		if((stat(ifile,&st) == 0) && (ifile[6] != '.')) {
			Pita_karakter = ifile;
			STARTKATA();
			printf("  ");
			while (!EndKata) {
				AlfabetToSimbol(CKata);
				ADVKATA();
			}
			CLOSEBACA();
			UpdateStatistikPesan(GetNamaPenerima(id));
			printf ("\n  ___________________________________________________________________________\n");
		} else
			printf("   File pesan tidak ditemukan atau kosong.\n");
	} else {
		printf("  ID pesan tidak ditemukan atau salah.\n");
	}
}
   
void HapusPesan (int id)
/* I.S : List pelanggan dan kamus  pada modus pengaturan telah terdefinisi.
   F.S : Menghapus pesan berdasarkan masukan id pesan dari pengguna. Kika id terdefinisi maka pesan
   akan dihapus dari folder "inbox" dan tidak muncul lagi pada list pesan. */
{
	// Kamus Lokal
	int i;
	DIR *dir;
	struct dirent *direntry;
	char ifile[100];
	struct stat st;
	
	// Algoritma
	if ((id > 0) && (id <= HitJumlahPesan())) {	
		dir = opendir("./Inbox");
		i = 0;
		while(((direntry = readdir(dir)) != NULL) && (i < id)) {
			sprintf(ifile, "Inbox/%s", direntry->d_name);
			if((stat(ifile,&st) == 0) && (ifile[6] != '.'))
				i++;
		}
		if((stat(ifile,&st) == 0) && (ifile[6] != '.')) {
			Pita_karakter = ifile;
			remove(ifile);
			if (remove(ifile) != 0 )
				printf("    Arsip %s terhapus dari sistem.\n", ifile);
			else
				printf("    Gagal menghapus arsip pesan.\n");
		} else {
			printf("   Arsip pesan tidak ditemukan.\n");
		}
	} else {
		printf("    ID pesan tidak ditemukan atau salah.\n");
	}
}

Kata GetNamaPenerima(int id)
/* Mengambil nama penerima berdasarkan id pesan */
{
	// Kamus Lokal
	int i;
	DIR *dir;
	struct dirent *direntry;
	char ifile[100];
	struct stat st;
	
	// Algoritma
	dir = opendir("./Inbox");
	i = 0;
	while(((direntry = readdir(dir)) != NULL) && (i < id)) {
		sprintf(ifile, "Inbox/%s", direntry->d_name);
		if((stat(ifile,&st) == 0) && (ifile[6] != '.'))
			i++;
	}
	if(ifile[6] != '.') {
		Pita_karakter = ifile;
		START();
		for (i=1;i<=13;i++) {
			ADVKATA();
		}
		CLOSEBACA();
	} else {
		CKata.TabKata[0] = '\0';
		CKata.Length = 0;
	}
	return CKata;
}

void UpdateStatistikPesan(Kata NamaPenerima)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Mengupdate statistik pembacaan yang telah diterima meliputi nama penerima, jumlah pesan yang
   diterima, dan jumlah pesan yang dibaca. */
{
	// Kamus Lokal
	address PNama, PTemp;
	
	// Algoritma
	BacaListFromFile(&statistik_inboks,"Pengaturan/statistik.pesan.txt");
	PNama = Search(statistik_inboks,NamaPenerima,1);
	if (PNama != Nil) {
		Info(PNama,3) = BilToKata(1+KataToBil(Info(PNama,3)),3);
	} else {
		PTemp = Alokasi(NamaPenerima,1);
		Info(PTemp,3) = BilToKata(1,3);
		InsertLast(&statistik_inboks, PTemp);
	}
	BacaListForFile(statistik_inboks,"Pengaturan/statistik.pesan.txt");
}

void BacaStatistikPesan(void)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Mencetak statistik pembacaan yang telah diterima meliputi nama penerima, jumlah pesan yang
   diterima, dan jumlah pesan yang dibaca. */
{
	// Kamus Lokal
	address P;
	int i, iS;
	
	// Algoritma
	BacaListFromFile(&statistik_inboks,"Pengaturan/statistik.pesan.txt");
	if(!IsListEmpty(statistik_inboks)) {
		P = First(statistik_inboks);
		i = 1;
		while(P != Nil)
		{
			if((i % 15) == 0) {
				printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
				Header2();
				printf ("\n                         .:: STATISTIK PESAN MASUK ::.");
                printf ("\n  ---------------------------------------------------------------------------\n\n");
			}
			printf("  %d. ",i);
			CetakKataToLayar(Info(P,1));
			for(iS = 1; iS <= 17-Info(P,1).Length; iS++)
				printf(" ");	//Mengatur jarak ke data berikutnya
			printf(" %3d/%d pesan\n",KataToBil(Info(P,2)),KataToBil(Info(P,3)));
			P = Next(P);
			i++;
		}
	} else {
		printf("  Statistik pelanggan kosong.\n");
	}
}
