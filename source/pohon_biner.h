#ifndef POHON_BINER_H
#define POHON_BINER_H
// { ADT Pohon Biner } 
// { Modul lain yang digunakan : } 
#include "list_rekursif.h"
#include "mesinkar.h"
#include "boolean.h"

// { *** Definisi Type Pohon Biner *** } 
typedef char tinfotype;
typedef struct tNode *taddress;
typedef struct tNode
{
	tinfotype Info;
	taddress Left;
	taddress Right;
} Node;
typedef taddress BinTree;

// { *** Definisi Type List of Node *** } 
typedef ListR ListOfNode;

#define Akar(P) (P)->Info
#define Left(P) (P)->Left
#define Right(P) (P)->Right
// { *** PROTOTYPE *** } 
// { *** Konstruktor *** } 
BinTree Tree (tinfotype Akar, BinTree L, BinTree R);
// { Menghasilkan sebuah pohon biner dari A, L, dan R,jika alokasi berhasil } 
// { Menghasilkan pohon kosong (Nil) jika alokasi gagal } 
void MakeTree (tinfotype Akar, BinTree L, BinTree R, BinTree *P);
// { I.S. Sembarang } 
// { F.S. Menghasilkan sebuah pohon P } 
// { Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil } 
// { Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal } 
void BuildTree (BinTree *P);
// { Membentuk sebuah pohon biner P dari pita karakteryang dibaca } 
// { I.S. Pita berisi "konstanta" pohon dalam bentuk prefix. 
// Memori pasti cukup, alokasi pasti berhasil. } 
// { F.S. P dibentuk dari ekspresi dalam pita } 

// { *** Predikat-Predikat Penting *** } 
boolean IsTreeEmpty (BinTree P);
// { Mengirimkan true jika P adalah pohon biner kosong} 
boolean IsOneElmt (BinTree P);
// { Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 
// elemen } 
boolean IsUnerLeft (BinTree P);
// { Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya 
// mempunyai subpohon kiri } 
boolean IsUnerRight (BinTree P);
// { Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya 
// mempunyai subpohon kanan} 
boolean IsBiner (BinTree P);
// { Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai 
// subpohon kiri dan subpohon kanan} 

// { *** Traversal *** } 
void PrintPreorder (BinTree P);
// { I.S. P terdefinisi } 
// { F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon 
// kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). } 
void PrintInorder (BinTree P);
// { I.S. P terdefinisi } 
// { F.S. Semua simpul P sudah dicetak secara inorder:pohon kiri, akar, dan pohon 
// kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). } 
void PrintPostorder (BinTree P);
// { I.S. P terdefinisi } 
// { F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan 
// akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). } 
void PrintSpace (int h);
// { I.S. Sembarang. h terdefinisi }
// { F.S. Terbentuk spasi sebanyak h }
void PrintTree (BinTree P, int h);
// { I.S. P terdefinisi, h adalah jarak indentasi } 
// { F.S. Semua simpul P sudah ditulis dengan indentasi } 

// { *** Searching *** } 
boolean SearchTree (BinTree P, tinfotype X);
// { Mengirimkan true jika ada node dari P yang bernilai X } 

// { *** Fungsi-Fungsi Lain *** } 
int NbTreeElmt (BinTree P);
// { Mengirimkan banyaknya elemen (node) pohon biner P} 
int NbDaun (BinTree P);
// { Mengirimkan banyaknya daun (node) pohon biner P }
boolean IsSkewLeft (BinTree P);
// { Mengirimkan true jika P adalah pohon condong kiri} 
boolean IsSkewRight (BinTree P);
// { Mengirimkan true jika P adalah pohon condong kiri} 
int Level (BinTree P, tinfotype X);
// { Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner 
// P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. } 

// { *** Operasi lain *** } 
void AddDaunTerkiri (BinTree *P, tinfotype X);
// { I.S. P boleh kosong } 
// { F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri } 
void AddDaun (BinTree *P, tinfotype X, tinfotype Y, boolean inputKiri);
// { I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P } 
// { F.S. P bertambah simpulnya, dengan Y sebagai anakkiri X (jika Kiri = true), atau 
// sebagai anak Kanan X (jika Kiri = false) } 
void DelDaunTerkiri (BinTree *P, tinfotype *X);
// { I.S. P tidak kosong } 
// { F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
// disimpan pada daun terkiri yang dihapus } 
void DelDaun (BinTree *P, tinfotype X); 
// { I.S. P tidak kosong, X adalah salah satu daun } 
// { F.S. Semua daun bernilai X dihapus dari P } 
ListOfNode MakeListDaun (BinTree P);
// { Jika P adalah pohon kosong, maka menghasilkan list kosong. } 
// { Jika P bukan pohon kosong : menghasilkan list yang elemennya adalah semua daun 
// pohon P, jika semua alokasi list berhasil. Menghasilkan list kosong jika ada 
// alokasi yang gagal. } 
ListOfNode MakeListPreorder (BinTree P);
// { Jika P adalah pohon kosong, maka menghasilkan list kosong. } 
// { Jika P bukan pohon kosong: menghasilkan list yangelemennya adalah semua elemen 
// pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan list 
// kosong jika ada alokasi yang gagal. } 
ListOfNode MakeListPostorder (BinTree P); 
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */ 
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen 
pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan list 
kosong jika ada alokasi yang gagal dan sekaligus mendealokasi semua elemen yang 
sudah telanjur dialokasi. */
ListOfNode MakeListLevel (BinTree P, int N);
// { Jika P adalah pohon kosong, maka menghasilkan list kosong. } 
// { Jika P bukan pohon kosong: menghasilkan list yangelemennya adalah semua elemen 
// pohon P yang levelnya=N, jika semua alokasi berhasil. Menghasilkan list kosong jika 
// ada alokasi yang gagal. } 

// { *** Balanced tree *** } 
BinTree BuildBalanceTree (int n);
// { Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca } 

// { *** Binary Search Tree *** } 
boolean BSearch (BinTree P, tinfotype X);
// { Mengirimkan true jika ada node dari P yang bernilai X } 
BinTree InsSearch (BinTree P, tinfotype X);
// { Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum 
// ada simpul P yang bernilai X. } 
void DelBtree (BinTree *P, tinfotype X);
// { I.S. Pohon P tidak kosong } 
// { F.S. Nilai X yang dihapus pasti ada } 
// { Sebuah node dengan nilai X dihapus } 
#endif