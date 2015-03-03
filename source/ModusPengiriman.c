#include <dirent.h>
#include "p_queue.h"
#include "mesinkar.h"
#include "mesinKata_v1.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "pohon_biner.h"
#include "endecode.h"
#include <unistd.h>
#include "ModusPengiriman.h"
#include "interface.h"

extern char CC;
extern Queue tQueue;
extern List statistik_sending;
extern List statistik_inboks;
extern char *Pita_karakter;
extern Kata CKata;
//extern boolean EndKata;

extern time_t Curtime, timeafter;

void TransmitPesan (void)
{
	// Kamus
	BinTree P;
	TipeNamaFile NamaFileBaru, NamaFileLama;
	
	// Algoritma
	Pita_karakter = "Pengaturan/pitakar.txt";
	START();
	BuildTree (&P);
	CLOSEBACA();
	printf("    %d ",HitJumlahPesanOutbox());
	while (HitJumlahPesanOutbox() != 0)
	{
		NamaFileLama = GetFirstFileOutbox();
		Pita_karakter = NamaFileLama.TabKata;
		START();
		MakeNameFileSending(NamaFileLama, &NamaFileBaru);
		Pita_karakter = NamaFileBaru.TabKata;
		STARTW ();
		EncodeMorse (P, CC);
		ADV();
		while (CC != MARK) 
		{
			WRITE(' ');
			EncodeMorse (P, CC);
			ADV();
		}
		WRITE (' ');
		WRITE ('#');
		CLOSETULIS ();
		CLOSEBACA ();
		remove (NamaFileLama.TabKata);
	}
}

void StatistikPengiriman (void)
{
	// Kamus
	address P;
	int i = 1;
	
	// Contoh Isi di file
	// 2012-12-01 13 002 2012-12-01 14 030#
	// Algoritma
	BacaListFromFile (&statistik_sending,  "Pengaturan/statistik.date.txt");
	if (!IsListEmpty (statistik_sending))
	{
		P = First(statistik_sending);
		while (P != Nil)
		{
			if((i % 15) == 0) {
				printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
				Header2();
				printf ("\n                         .:: STATISTIK PENGIRIMAN ::.");
				printf ("\n  ---------------------------------------------------------------------------\n\n");
			}
			printf ("    %d. ", i);
			CetakKataToLayar(Info(P, 1));
			printf("     ");
			CetakKataToLayar(Info(P, 2));
			printf(" %4d pesan\n",KataToBil(Info(P, 3)));
			i++;
			P = Next(P);
		}
	}
	else
		printf ("  Statistik pesan yang dikirim kosong. \n");
}

void UpdateStatistikPengiriman (void)
{
	// Kamus
	Kata tanggal, jam;
	address P, PCheck;
	struct tm * loctime;
	
	// Algoritma
	loctime = localtime (&Curtime);
	strftime(tanggal.TabKata,20," %Y-%m-%d", loctime);
	tanggal.Length = 10;
	strftime(jam.TabKata,4," %H", loctime);
	jam.Length = 2;
	BacaListFromFile (&statistik_sending, "Pengaturan/statistik.date.txt");
	P = Search (statistik_sending, tanggal, 1);
	if (P != Nil)
	{
		PCheck = Search (statistik_sending, jam, 2);
		if (PCheck != Nil)
			Info(PCheck, 3) = BilToKata(1+KataToBil(Info(PCheck,3)),3);
		else
		{
			P = Alokasi (tanggal, 1);
			Info(P,2) = jam;
			Info(P,3) = BilToKata(1,3);
			InsertLast (&statistik_sending, P);
		}
	}
	else
	{
		P = Alokasi (tanggal, 1);
		Info(P,2) = jam;
		Info(P,3) = BilToKata(1,3);
		InsertLast (&statistik_sending, P);
	}
	BacaListForFile(statistik_sending, "Pengaturan/statistik.date.txt");
}

TipeNamaFile GetFirstFileOutbox(void)
{
	// Kamus
	DIR * dir;
	struct dirent *direntry;
	TipeNamaFile CFile;
	boolean SudahiAja;
	
	// Algoritma
	SudahiAja = false;
	dir = opendir("Outbox");
	while (((direntry = readdir(dir)) != NULL) && !SudahiAja) 
	{
		sprintf(CFile.TabKata, "Outbox/%s", direntry->d_name);
		if(CFile.TabKata [7] != '.') {
			CFile.Length = PanjangNamaFile(CFile.TabKata);
			SudahiAja = true;
		}
	}
	return CFile;
}
TipeNamaFile GetFirstFileSending(void)
{
	// Kamus
	DIR * dir;
	struct dirent *direntry;
	TipeNamaFile CFile;
	boolean SudahiAja;
	
	// Algoritma
	SudahiAja = false;
	dir = opendir("Sending");
	while (((direntry = readdir(dir)) != NULL) && !SudahiAja) 
	{
		sprintf(CFile.TabKata, "Sending/%s", direntry->d_name);
		if(CFile.TabKata [8] != '.') {
			CFile.Length = PanjangNamaFile(CFile.TabKata);
			SudahiAja = true;
		}
	}
	return CFile;
}
int HitJumlahPesanOutbox (void)
/* I.S : List pelanggan dan kamus pada modus pengaturan telah terdefinisi.
   F.S : Menghitung jumlah pesan pada folder outbox */
{
	// Kamus Lokal
	int jumlah;
	DIR *dir;
	struct dirent *direntry;
	struct stat st;
	char ifile[100];
	
	// Algoritma
	dir = opendir("Outbox");
	jumlah = 0;
	while ((direntry = readdir(dir)) != NULL) {
		snprintf(ifile,100,"Outbox/%s",direntry->d_name);
		if((stat(ifile,&st) == 0) && (ifile[7] != '.')) {
			jumlah++;
		}
	}
	return jumlah;
}

int PanjangNamaFile (char * nama)
{
	// Kamus Lokal
	int i = 0;
	
	// ALgoritma
	while(nama[i] != '\0')
		i++;
	return i;
}

void MakeNameFileSending (TipeNamaFile NamaFile1, TipeNamaFile * NamaFile2)
{
	int i;
	
	(*NamaFile2).TabKata[0] = 'S'; (*NamaFile2).TabKata[1] = 'e'; 
	(*NamaFile2).TabKata[2] = 'n'; (*NamaFile2).TabKata[3] = 'd';
	(*NamaFile2).TabKata[4] = 'i'; (*NamaFile2).TabKata[5] = 'n';
	(*NamaFile2).TabKata[6] = 'g'; (*NamaFile2).TabKata[7] = '/';
	for(i=8; i <= NamaFile1.Length; i++)
		(*NamaFile2).TabKata[i] = NamaFile1.TabKata[i-1];
	(*NamaFile2).TabKata[i+1] = '\0';
	(*NamaFile2).TabKata[i+2] = '\0';
	(*NamaFile2).Length = i;
}

void MakeNameFileInbox (TipeNamaFile NamaFile1, TipeNamaFile * NamaFile2)
{
	int i;
	
	(*NamaFile2).TabKata[0] = 'I'; (*NamaFile2).TabKata[1] = 'n'; 
	(*NamaFile2).TabKata[2] = 'b'; (*NamaFile2).TabKata[3] = 'o';
	(*NamaFile2).TabKata[4] = 'x'; (*NamaFile2).TabKata[5] = '/';
	for(i=6; i <= NamaFile1.Length; i++)
		(*NamaFile2).TabKata[i] = NamaFile1.TabKata[i+2];
	(*NamaFile2).TabKata[i+1] = '\0';
	(*NamaFile2).TabKata[i+2] = '\0';
	(*NamaFile2).Length = i;
}

int GetPriorityFile(TipeNamaFile NamaFile)
{	
	Pita_karakter = NamaFile.TabKata;
	STARTKATA();
	ADVKATA();
	ADVKATA();
	CLOSEBACA();
	return ((int) (CKata.TabKata[1] - '0'));
}

void UpdateStatistikPsn (Kata NamaPenerima)
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
		Info(PNama,2) = BilToKata(1+KataToBil(Info(PNama,2)),3);
	} else {
		PTemp = Alokasi(NamaPenerima,1);
		Info(PTemp,2) = BilToKata(1,3);
		Info(PTemp,3) = BilToKata(0,3);
		InsertLast(&statistik_inboks, PTemp);
	}
	BacaListForFile(statistik_inboks,"Pengaturan/statistik.pesan.txt");
}

void SendingAfter30seconds(void)
{
	/* KAMUS LOKAL */
	TipeNamaFile FileInbox, FileSending;
	BinTree P;
	qinfotype X;
	int Pr, i;
	
	/*  ALGORITMA  */
	Curtime = time(NULL);
	Pita_karakter = "Pengaturan/pitakar.txt";
	START ();
	BuildTree (&P);
	CLOSEBACA ();
	BacaPQueue (&tQueue);
	if(IsEmpty (tQueue))
		timeafter = Curtime;
	else 
	{
		while (difftime (Curtime,timeafter) >= 30) 
		{
			Del (&tQueue,&X,&Pr);
			Pita_karakter = X.TabKata;
			STARTKATA ();
			FileSending = ConvertToNamaFile (X);
			MakeNameFileInbox (FileSending,&FileInbox);
			Pita_karakter = FileInbox.TabKata;
			STARTW ();
			WRITE (DecodeMorse (P));
			ADVKATA ();
			while (CC != MARK) 
			{
				WRITE (DecodeMorse (P));
				ADVKATA ();
			}
			WRITE ('#');
			CLOSETULIS ();
			CLOSEBACA ();
			remove (X.TabKata);
			Curtime = time (NULL);
			UpdateStatistikPengiriman ();
			Pita_karakter = FileInbox.TabKata;
			START ();
			for (i=1; i <= 13; i++)
				ADVKATA ();
			CLOSEBACA ();
			UpdateStatistikPsn (CKata);
			timeafter += 30;
		}
	}
}

TipeNamaFile ConvertToNamaFile(Kata NamaFile)
{
	// Kamus
	int i;
	TipeNamaFile TempTNF;
	
	// Algoritma
	for (i=0; i <= NamaFile.Length; i++) 
		TempTNF.TabKata[i] = NamaFile.TabKata[i];
	TempTNF.Length = NamaFile.Length;
	return TempTNF;
}
