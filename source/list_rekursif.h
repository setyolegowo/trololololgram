#ifndef LIST_REC_H
#define LIST_REC_H

#include "boolean.h"

// KAMUS
// { List rekursif direpresentasi dengan pointer } 

#define Nil NULL

typedef char linfotype;
typedef struct trElmtList * addressR;
typedef struct trElmtList {
	linfotype info;
	addressR next;
} rElmtList;
typedef addressR ListR;

// Selektor
#define InfoR(P) (P)->info
#define NextR(P) (P)->next

// { *** Manajemen Memori *** } 
addressR LAlokasi (linfotype X);
// { Mengirimkan address hasil alokasi sebuah elemen }
// { Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
// maka Info(P) = X, Next(P) = Nil } 
// { Jika alokasi gagal, mengirimkan Nil } 
void LDealokasi (addressR *P);
// { I.S. P terdefinisi } 
// { F.S. P dikembalikan ke sistem } 
// { Melakukan dealokasi/pengembalian address P } 

// { *** Primitif-primitif yang harus direalisasikan *** } 
// { *** Selektor *** } 
linfotype FirstElmt (ListR L);
// { Mengirimkan elemen pertama sebuah list L yang tidak kosong } 
//ListR Tail (ListR L);
// { Mengirimkan list L yang tidak kosong tanpa elemen pertamanya }

// { *** Konstruktor *** } 
ListR Konsb (linfotype e, ListR L);
// { Mengirimkan list L dengan tambahan e sebagai elemen pertamanya } 
// { e harus dialokasi terlebih dahulu } 
// { Jika alokasi e gagal, mengirimkan L } 
ListR Konse (ListR L, linfotype e); 
// { Mengirimkan list L dengan tambahan e sebagai elemen terakhir } 
// { e harus dialokasi terlebih dahulu } 
// { Jika alokasi e gagal, mengirimkan L } 

// { *** Predikat *** } 
boolean IsListEmptyR (ListR L);
// { Mengirimkan true jika list kosong, false jika tidak kosong } 
// { Mungkin yang dikirimkan adalah sebuah list kosong} 

// { *** Operasi Lain *** } 
ListR Copy (ListR L);
// { Mengirimkan salinan list L (menjadi list baru) } 
// { Jika ada alokasi gagal, mengirimkan L } 
ListR Concat (ListR L1, ListR L2);
// { Mengirimkan salinan hasil konkatenasi list L1 danL2 (menjadi list baru) } 
// { Jika ada alokasi gagal, menghasilkan Nil } 
void PrintList (ListR L);
// { I.S. L terdefinisi. } 
// { F.S. Setiap elemen list dicetak. } 
int NBElmtList (ListR L);
// { Mengirimkan banyaknya elemen list L, Nol jika L kosong } 
boolean SearchR (ListR L, linfotype X);
// { Mengirim true jika X adalah anggota list, false jika tidak } 

#endif
