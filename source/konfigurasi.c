#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "list.h"
#include "p_queue.h"
#include "mesinkar.h"
#include "mesinKata_v1.h"

extern char CC;
extern char * Pita_karakter;
extern unsigned int tDaftarHarga[5];
extern struct {
	unsigned int kode;
	Kata nama;
} tDaftarKar[32];
extern int nKarReg;
extern Kata CKata;
extern List statistik_inboks;
extern List statistik_outboks;
extern List statistik_sending;
extern List tDaftarPelanggan;

void DaftarHarga(void) // Bisa update juga
{
	/* KAMUS LOKAL */
	FILE * dh;
	int i;
	
	/* ALGORITMA */
	//Pita_karakter = (char *) malloc(sizeof("Pengaturan/listHarga.txt"));
	Pita_karakter = "Pengaturan/listHarga.txt";
	START();
	if (CC == MARK) {
		// Membuat konfigurasi
		dh = fopen("Pengaturan/listHarga.txt","w");
		fprintf(dh,"0 0 1 500 2 800 3 200 4 700%c",MARK);
		fclose(dh);
	}
	CLOSEBACA();
	STARTKATA();
	// Mengambil konfigurasi
	while(!EOP()) {
		i = KataToBil(CKata);
		ADVKATA();
		tDaftarHarga[i] = KataToBil(CKata);
		ADVKATA();
	}
	CLOSEBACA();
	//free(Pita_karakter);
}

void ListItem(void)
{
	/* KAMUS LOKAL */
	FILE * li;
	unsigned int k, bil1;
	
	/* ALGORITMA */
	Pita_karakter = "Pengaturan/karakterSpesial.txt";
	START();
	if (CC == MARK) {
		li = fopen("Pengaturan/karakterSpesial.txt","w");
		fprintf(li,"033 TANDASERU 034 KUTIPGANDA 035 XHASH 036 XDOLLAR 037 XPERCENTAGE ");
		fprintf(li,"038 XAND 039 XAPOSTROPHE 040 KURUNGBUKA 041 KURUNGTUTUP 042 XASTERISK ");
		fprintf(li,"043 OPERATORTAMBAH 044 XKOMA 045 OPERATORKURANG 046 XTITIK 047 MIRINGKANAN ");
		fprintf(li,"058 XTITIKDUA 059 XTITIKKOMA 060 LEBIHKECILDARI 061 OPERANSAMADENGAN ");
		fprintf(li,"062 LEBIHBESARDARI 063 TANDATANYA 064 XAT 091 KURUNGSIKUKIRI 092 MIRINGKIRI ");
		fprintf(li,"093 KURUNGSIKUKANAN 094 XCHARET 095 XDASH 123 KURAWALKIRI ");
		fprintf(li,"124 VERTICALBAR 125 KURAWALKANAN 126 XTILDE%c",MARK);
		fclose(li);
	}
	CLOSEBACA();
	k=0;
	STARTKATA();
	while(!EOP())
	{
		bil1 = (100*KarToBil(CKata.TabKata[1])) + (10*KarToBil(CKata.TabKata[2])) + KarToBil(CKata.TabKata[3]);
		tDaftarKar[k].kode = bil1;
		ADVKATA();
		tDaftarKar[k].nama = CKata;
		k++;
		ADVKATA();
	}
	// EOP() dan k dalam keadaan nextnya
	nKarReg = k - 1;
	CLOSEBACA();
	//free(Pita_karakter);
}
void TulisListItem(void)
{
	/* KAMUS LOKAL */
	int i;
	Kata TKata;
	
	/* ALGORITMA */
	Pita_karakter = "Pengaturan/karakterSpesial.txt";
	i = 0;
	STARTW();
	while (i < nKarReg) {
		// Merubah integer ke 3 integer bentuk karakter
		TKata = BilToKata(tDaftarKar[i].kode, 3);
		CetakKataToFile(TKata);
		WRITE(' ');
		CetakKataToFile(tDaftarKar[i].nama);
		WRITE(' ');
		i++;
	}
	// i == nKarReg
	TKata = BilToKata(tDaftarKar[i].kode, 3);
	CetakKataToFile(TKata);
	WRITE(' ');
	CetakKataToFile(tDaftarKar[i].nama);
	WRITE(MARK);
	CLOSETULIS();
}
void BacaListFromFile(List * L, char * pitaKarakter)
{
	/* KAMUS LOKAL */
	address P;
	unsigned int i;
	boolean IsKosong;
	
	/* ALGORITMA */
	Pita_karakter = pitaKarakter;
	DeleteAll(L);
	START();
	if(!EOP())
		IsKosong = false;
	else
		IsKosong = true;
	CLOSEBACA();
	if(!IsKosong) {
		STARTKATA();
		while(!EOP())
		{
			P = Alokasi(CKata,1);
			for(i=2; i<=NList(*L); i++) {
				ADVKATA();
				Info(P,i) = CKata;
			}
			InsertLast(L,P);
			ADVKATA();
		}
		if(NList(*L) == 1) {
			P = Alokasi(CKata,1);
			InsertLast(L,P);
		}
		CLOSEBACA();
	}
}
void BacaListForFile(List L, char * pitaKarakter)
{
	/* KAMUS LOKAL */
	address P;
	int i;
	
	/* ALGORITMA */
	if(!IsListEmpty(L)) {
		P = First(L);
		Pita_karakter = pitaKarakter;
		STARTW();
		while(Next(P) != Nil)
		{
			CetakKataToFile(Info(P,1));
			for(i=2; i<=NList(L); i++) {
				WRITE(' ');
				CetakKataToFile(Info(P,i));
			}
			WRITE(' ');
			P = Next(P);
		}
		// Next(P) == Nil (Elemen terakhir)
		CetakKataToFile(Info(P,1));
		for(i=2; i<=NList(L); i++) {
			WRITE(' ');
			CetakKataToFile(Info(P,i));
		}
		WRITE(MARK);
		CLOSETULIS();
	}
}
void BacaPQueue(Queue * PQ)
{
	// Kamus
	Kata K;
	int i;
	DIR *dir;
	struct dirent *direntry;
	struct stat st;
	
	// Algoritma
	dir = opendir("Sending");
	DelAll(PQ);
	while ((direntry = readdir(dir)) != NULL) {
		snprintf(K.TabKata,71,"Sending/%s",direntry->d_name);
		if((stat(K.TabKata,&st) == 0) && (K.TabKata[8] != '.')) {
			Pita_karakter = K.TabKata;
			i = 0;
			while(K.TabKata[i] != '\0') {
				i++;
			}
			K.Length = i;
			STARTKATA();
			ADVKATA();
			ADVKATA();
			Add(PQ,K,KataToBil(CKata));
			CLOSEBACA();
		}
	}
	closedir(dir);
}
void TulisPitakar(void)
{
	FILE * pk;
	
	/* ALGORITMA */
	Pita_karakter = "Pengaturan/pitakar.txt";
	START();
	if(CC == MARK) {
		pk = fopen("Pengaturan/pitakar.txt","w");
		fprintf(pk,"(~(E(I(S(H(5()())(4()()))(V()(3()())))(U(F()())(!()(2()()))))");
		fprintf(pk,"(A(R(L()())())(W(P()())(J()(1()())))))(T(N(D(B(6()())())");
		fprintf(pk,"(X()()))(K(C()())(Y()())))(M(G(Z(7()())())(Q()()))");
		fprintf(pk,"(O( (8()())())( (9()())(0()()))))))");
		fclose(pk);
	}
	CLOSEBACA();
}
