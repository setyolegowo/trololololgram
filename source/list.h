/* **************************************************************************** */
/*                              MODUL LIST BERKAIT                              */
/* **************************************************************************** */

#ifndef LIST_LINIER_EKSPLISIT_H
#define LIST_LINIER_EKSPLISIT_H

// List direpresentasi dengan pointer, First dinyatakan secara eksplisit.

/* ********************************* Header *********************************** */
#include "mesinKata_v1.h"
#include "boolean.h"

// { Konstanta }
#define LNMax 6
#define Nil NULL
typedef Kata infotype;
typedef struct ttElmtList *address;
typedef struct ttElmtList {
	infotype Info[LNMax+1];
	address Next;
} ElmtList;
typedef struct {
	unsigned int N;
	address First;
} List;

// { Jika L : List dan P : address (address untuk traversal), maka penulisan :
//   - First(L) menjadi L.First 
// 	 - Next(P) menjadi P->Next 
//   - Info(P) menjadi P->Info } 
#define First(L) (L).First
#define Info(P,N) (P)->Info[N]
#define NList(L) (L).N
#define Next(P) (P)->Next

/* **************************************************************************** */
/*                                  PROTOTYPE                                   */
/* **************************************************************************** */

/* **************************** TEST LIST KOSONG ****************************** */
boolean IsListEmpty(List L);
// { Mengirim true jika list kosong } 

/* ************************* PEMBUATAN LIST KOSONG **************************** */
void CreateList (List * L, unsigned int N);
// { I.S. sembarang }
// { F.S. Terbentuk list kosong }

/* *************************** Manajemen Memori ******************************* */
address Alokasi(infotype X, unsigned int N);
// { Mengirimkan address hasil alokasi sebuah elemen }
// { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
//   maka Info(P,N) = X, Next(P) = Nil dan setiap elemen infotype diisi Length = 0 }
// { Jika alokasi gagal, mengirimkan Nil }
void Dealokasi (address * P);
// { I.S. P terdefinisi }
// { F.S. P dikembalikan ke sistem }
// { Melakukan dealokasi/pengembalian address P }

/* ********************** PENCARIAN SEBUAH ELEMEN LIST ************************ */
address Search (List L, infotype X, unsigned int N);
// { Mencari apakah ada elemen list dengan Info(P,N) = X }
// { Jika ada, mengirimkan address elemen tersebut }
// { Jika tidak ada, mengirimkan Nil }
address SearchPrec(List L, infotype X, unsigned int N);
// { Mengirimkan address elemen sebelum elemen yang nilainya = X }
// { Mencari apakah ada elemen list dengan Info(P,N) = X} 
// { Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P,N) = X }
// { Jika tidak ada, mengirimkan Nil }
// { Jika P adalah elemen pertama, maka mengirimkan Nil } 
// { Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah 
//   Search akan dilakukan operasi lain } 

/* ********************** PRIMITIF BERDASARKAN ALAMAT ************************* */
// { *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** }
void InsertFirst (List * L, address P);
// { I.S. Sembarang, P sudah dialokasi }
// { F.S. Menambahkan elemen ber-address P sebagai elemen pertama }
void InsertAfter (List * L, address P, address Prec);
// { I.S. Prec pastilah elemen list dan bukan elemen terakhir,
//		  P sudah dialokasi }
// { F.S. Insert P sebagai elemen sesudah elemen beralamat Prec }
void InsertLast(List * L, address P);
// { I.S. Sembarang, P sudah dialokasi } 
// { F.S. P ditambahkan sebagai elemen terakhir yang baru } 

// { *** PENGHAPUSAN SEBUAH ELEMEN *** }
// procedureDeleteFirst (input/outputL : List, outputP : address) 
void DeleteFirst(List * L, address * P);
// { I.S. List tidak kosong }
// { F.S. P adalah alamat elemen pertama list sebelum penghapusan
//		  Elemen list berkurang satu (mungkin menjadi kosong)
//		  First element yang baru adalah suksesor elemen pertama yang lama }
void DeleteP (List * L, infotype X, unsigned int N);
// { I.S. Sembarang }
// { F.S. Jika ada elemen list beraddress P, dengan Info(P) = X maka P dihapus
// 		  dari list dan di-dealokasi.
//		  Jika tidak ada elemen list dengan Info(P) = X, maka list tetap.
//		  List mungkin menjadi kosong karena penghapusan }
void DeleteLast (List * L, address * P);
// { I.S. List tidak kosong } 
// { F.S. P adalah alamat elemen terakhir list sebelumpenghapusan
// 		  Elemen list berkurang satu (mungkin menjadi kosong)
//		  Last element baru adalah predesesor elemen pertama yang lama, jika ada }
void DeleteAfter (List * L, address * Pdel, address Prec);
// { I.S. List tidak kosong. Prec adalah anggota list L. } 
// { F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus } 

/* *********************** PROSES SEMUA ELEMEN LIST *************************** */
void PrintInfo(List L, int Kolom);
// { I.S. List mungkin kosong }
// { F.S. Jika list tidak kosong,
//		  Semua info yg disimpan pada elemen list diprint.
//		  Jika list kosong, hanya menuliskan "list kosong" }
int NbElmt(List L);
// { Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong }

// { *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** }

/* ************************* PROSES TERHADAP LIST ***************************** */
void DeleteAll(List * L);
// { Delete semua elemen list dan alamat elemen di-dealokasi }
// { I.S. : L terdefinisi, boleh kosong }
// { F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi }

#endif // LIST_LINIER_EKSPLISIT_H
