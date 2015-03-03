#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

// ADT priority queue berkait dengan representasi fisik pointer 
// Representasi qaddress dengan pointer 
// qinfotype adalah integer 
// Prioritas berdasarkan nilai elemen prio yang menunjukkan prioritas 
// Queue terurut mengecil berdasarkan prioritas 
#include "mesinKata_v1.h"
#include "boolean.h"
#define Nil NULL

// *** Definisi Type Queue *** 
typedef Kata qinfotype;
typedef struct tElmtQueue *qaddress;
typedef struct tElmtQueue 
{
	qinfotype Info;
	int Prio;
	qaddress Next;
} ElmtQueue;
typedef struct {
	qaddress HEAD;
	qaddress TAIL;
} Queue;

// Selektor
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define NextQ(P) (P)->Next
#define InfoQ(P) (P)->Info
#define Prio(P) (P)->Prio

// Definisi priority queue : } 
// Queue kosong : Head(Q) = Nil } 
// Setiap elemen dengan qaddress P dapat diacu info(P), Next(P) } 
// Elemen terakhir list : jika qaddressnya Last, makaNext(Last)=Nil } 

// *** Prototype manajemen memori *** } 
void QAlokasi (qaddress *P, qinfotype X);
// I.S. P sembarang, X terdefinisi } 
// F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil } 
// P = Nil jika alokasi gagal } 
void QDealokasi (qaddress *P);
// I.S. P adalah hasil alokasi, P <> Nil } 
// F.S. Alamat P didealokasi, dikembalikan ke sistem} 

// *** Predikat Pemeriksaan Kondisi Queue *** } 
boolean IsEmpty (Queue Q);
// Mengirim true jika Q kosong: HEAD(Q) = Nil dan TAIL(Q) = Nil } 
int NBElmt (Queue Q);
// Mengirimkan banyaknya elemen queue. Mengirimkan 0jika Q kosong. } 

// *** Konstruktor *** } 
void CreateEmpty (Queue *Q);
// I.S. sembarang } 
// F.S. Sebuah Q kosong terbentuk } 

// *** Primitif Add/Delete *** } 
void Add (Queue *Q, qinfotype X, int Pr);
// Proses : Mengalokasi X dan menambahkan X pada bagian TAIL dari Q jika alokasi 
// berhasil dengan memperhatikan prioritas;jika alokasi gagal Q tetap } 
// I.S. Q mungkin kosong, X terdefinisi } 
// F.S. X menjadi elemen Q sesuai prioritas Pr, 
// Q tetap terurut mengecil sesuai prioritas } 
void Del (Queue *Q, qinfotype *X, int *Pr);
// Proses : Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD, 
// X berisi elemen dengan prioritas tertinggi } 
// I.S. Q tidak kosong } 
// F.S. X = nilai elemen HEAD dan Pr = nilai elemen prioritas HEAD pd I.S., 
// HEAD "maju" }
void DelAll (Queue *Q);
// Membuat Q menjadi kosong dengan mendealokasikan memori antrian yang dihapus }
#endif
