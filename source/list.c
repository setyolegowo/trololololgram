/* NIM/Nama 	: 13511071 / Setyo Legowo
   Nama file 	: P__13511071list.h
   Topik 		: Abstract Data Type List Berkait Linier
   Tanggal 		: 
   Deskripsi 	: Praktikum 
*/

/* **************************************************************************** */
/*                              MODUL LIST BERKAIT                              */
/* **************************************************************************** */

// List direpresentasi dengan pointer, First dinyatakan secara eksplisit.

/* ********************************* Header *********************************** */
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "list.h"
#include "mesinKata_v1.h"

/* **************************************************************************** */
/*                                  PROTOTYPE                                   */
/* **************************************************************************** */

/* **************************** TEST LIST KOSONG ****************************** */
boolean IsListEmpty(List L) //TESTEDBYSETYO
// { Mengirim true jika list kosong } 
{
	return (First(L) == Nil);
}
/* ************************* PEMBUATAN LIST KOSONG **************************** */
void CreateList (List * L, unsigned int N) //TESTEDBYSETYO
// { I.S. sembarang }
// { F.S. Terbentuk list kosong }
{
	First(*L) = Nil;
	NList(*L) = N;
}
/* *************************** Manajemen Memori ******************************* */
address Alokasi(infotype X, unsigned int N) //TESTEDBYSETYO
// { Mengirimkan address hasil alokasi sebuah elemen }
// { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
//   maka Info(P) = X, Next(P,0) = Nil }
// { Jika alokasi gagal, mengirimkan Nil }
// { Range N [1..LNMax] }
{
	/* KAMUS LOKAL */
	address P;
	unsigned int i;
	
	/* ALGORITMA */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil)
	{
		for(i = 1; i <= N; i++)
			Info(P,i) = X;
		Next(P) = Nil;
	}
	return P;
}
void Dealokasi (address * P) // Gak yakin
// { I.S. P terdefinisi }
// { F.S. P dikembalikan ke sistem }
// { Melakukan dealokasi/pengembalian address P }
{
	free(*P);
}

/* ********************** PENCARIAN SEBUAH ELEMEN LIST ************************ */
address Search (List L, infotype X, unsigned int N) //TESTEDBYSETYO
// { Mencari apakah ada elemen list dengan Info(P,N) = X }
// { Nilai N berada pada [1..NList(L)] }
// { Jika ada, mengirimkan address elemen tersebut }
// { Jika tidak ada, mengirimkan Nil }
{
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	if(IsListEmpty(L) == true) {
		return Nil;
	} else {
		P = First(L);
		while((Next(P) != Nil) && (!IsKataSama(Info(P,N),X)))
			P = Next(P);
		// Next(P) == Nil;
		if(IsKataSama(Info(P,N),X))
			return P;
		else
			return Nil;
	}
}
address SearchPrec(List L, infotype X, unsigned int N) //TESTEDBYSETYO
// { Mengirimkan address elemen sebelum elemen yang nilainya = X }
// { Mencari apakah ada elemen list dengan Info(P,N) = X} 
// { Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P,N) = X }
// { Jika tidak ada, mengirimkan Nil } 
// { Jika P adalah elemen pertama, maka mengirimkan Nil } 
// { Search dengan spesifikasi seperti ini menghindaritraversal ulang jika setelah 
//   Search akan dilakukan operasi lain } 
{
	// KAMUS LOKAS
	address Pb,Pc;
	
	// ALGORITMA
	if(IsListEmpty(L) == true)
		return Nil;
	else {
		Pb = Nil;
		Pc = First(L);
		while((Next(Pc) != Nil) && (IsKataSama(Info(Pc,N),X) == false))
		{
			Pb = Pc;
			Pc = Next(Pc);
		}
		if(IsKataSama(Info(Pc,N),X) == true)
			return Pb;
		else
			return Nil;
	}
}

/* ********************** PRIMITIF BERDASARKAN ALAMAT ************************* */
// { *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** }
void InsertFirst (List * L, address P) //TESTEDBYSETYO
// { I.S. Sembarang, P sudah dialokasi }
// { F.S. Menambahkan elemen ber-address P sebagai elemen pertama }
{
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List * L, address P, address Prec) //TESTEDBYSETYO
// { I.S. Prec pastilah elemen list dan bukan elemen terakhir, P sudah dialokasi }
// { F.S. Insert P sebagai elemen sesudah elemen beralamat Prec }
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
void InsertLast(List * L, address P) //TESTEDBYSETYO
// { I.S. Sembarang, P sudah dialokasi } 
// { F.S. P ditambahkan sebagai elemen terakhir yang baru } 
{
	// KAMUS LOKAL
	address Last;
	
	// ALGORITMA
	if(IsListEmpty(*L) == true) {
		First(*L) = P;
	} else {
		Last = First(*L);
		while(Next(Last) != Nil)
			Last = Next(Last);
		Next(Last) = P;
	}
	Next(P) = Nil;
}

// { *** PENGHAPUSAN SEBUAH ELEMEN *** }
// procedureDeleteFirst (input/outputL : List, outputP : address) 
void DeleteFirst(List * L, address * P) //TESTEDBYSETYO
// { I.S. List tidak kosong }
// { F.S. P adalah alamat elemen pertama list sebelum penghapusan
//		  Elemen list berkurang satu (mungkin menjadi kosong)
//		  First element yang baru adalah suksesor elemen pertama yang lama }
{
	*P = First(*L);
	First(*L) = Next(First(*L));
}
void DeleteP (List * L, infotype X, unsigned int N) //TESTEDBYSETYO
// { I.S. Sembarang }
// { F.S. Jika ada elemen list beraddress P, dengan Info(P) = X maka P dihapus
// 		  dari list dan di-dealokasi.
//		  Jika tidak ada elemen list dengan Info(P) = X, maka list tetap.
//		  List mungkin menjadi kosong karena penghapusan }
{
	// KAMUS LOKAL
	address P,PPrec;
	
	// ALGORITMA
	if(IsListEmpty(*L) != true) {
		PPrec = Nil;
		P = First(*L);
		while((Next(P) != Nil) && (IsKataSama(Info(P,N),X) == false)) {
			PPrec = P;
			P = Next(P);
		}
		// Info(P) == X or Next(P) == Nil
		if(IsKataSama(Info(P,N),X) == true) {
			if(PPrec == Nil) {
				First(*L) = Next(P);
			} else {
				Next(PPrec) = Next(P);
			}
			Dealokasi(&P);
		}
	}
}
void DeleteLast (List * L, address * P) //TESTEDBYSETYO
// { I.S. List tidak kosong } 
// { F.S. P adalah alamat elemen terakhir list sebelum penghapusan
// 		  Elemen list berkurang satu (mungkin menjadi kosong)
//		  Last element baru adalah predesesor elemen pertama yang lama, jika ada }
{
	// KAMUS LOKAL
	address Last, PrecLast;
	
	// ALGORITMA
	PrecLast = Nil;
	Last = First(*L);
	while(Next(Last) != Nil) {
		PrecLast = Last;
		Last = Next(Last);
	}
	// Next(Last) == Nil maka elemen terakhir
	*P = Last;
	Next(PrecLast) = Nil;
}
void DeleteAfter (List * L, address * Pdel, address Prec) //TESTEDBYSETYO
// { I.S. List tidak kosong. Prec adalah anggota list L. } 
// { F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus } 
{
	// KAMUS LOKAL
	
	// ALGORITMA
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
}

/* *********************** PROSES SEMUA ELEMEN LIST *************************** */
void PrintInfo(List L, int Kolom) //TESTEDBYSETYO
// { I.S. List mungkin kosong }
// { F.S. Jika list tidak kosong,
//		  Semua info yg disimpan pada elemen list diprint.
//		  Jika list kosong, hanya menuliskan "list kosong" }
// { NMax adalah jumlah kolom yang digunakan oleh list }
{
	// KAMUS LOKAL
	address P;
	int i;
	
	// ALGORITMA
	if(IsListEmpty(L) == true)
		printf("list kosong\n");
	else {
		P = First(L);
		while(P != Nil)
		{
			for(i = 1; i <= NList(L); i++) {
				CetakKataToLayar(Info(P,i));
				printf(" ");
			}
			printf("\n");
			P = Next(P);
		}
	}
}
int NbElmt(List L) //TESTEDBYSETYO
// { Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong }
{
	// KAMUS LOKAL
	address P;
	int NElmt;
	
	// ALGORITMA
	P = First(L);
	NElmt = 0;
	while(P != Nil)
	{
		NElmt++;
		P = Next(P);
	}
	return NElmt;
}

/* ************************* PROSES TERHADAP LIST ***************************** */
void DeleteAll(List * L) //TESTEDBYSETYO
// { Delete semua elemen list dan alamat elemen di-dealokasi }
// { I.S. : L terdefinisi, boleh kosong }
// { F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi }
{
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	while(!IsListEmpty(*L))
	{
		DeleteFirst(L, &P);
		Dealokasi(&P);
	}
}