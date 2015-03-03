/* NIM/Nama 	: 13511071 / Setyo Legowo
   Nama file 	: P__13511071mList.h
   Topik 		: Abstract Data Type List Berkait Linier
   Tanggal 		: 
   Deskripsi 	: Praktikum 
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	/* KAMUS GLOBAL */
	infotype CInt,X;
	address PREC,PTemp;
	List L1, L2, L3;
	
	/* ALGORITMA */
	
	CreateList(&L1);
	CreateList(&L2);
	CreateList(&L3);
	
	// Test List Kosong
	if(IsListEmpty(L1) == true)
		printf("List 1 kosong\n");
	if(IsListEmpty(L2) == true)
		printf("List 2 kosong\n");
	
	// Insert Value
	printf("\nCara 1 \"InsVFirst\" ke L1\n");
	printf(" Masukkan 999 untuk mengakhiri pengisian.\n");
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	while(CInt != 999)
	{
		InsVFirst(&L1,CInt);
		printf(" Masukkan nilai = ");
		scanf("%d",&CInt);
	}
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	
	/* printf("\nCara 2 \"InsVLast\" ke L2\n");
	printf(" Masukkan 999 untuk mengakhiri pengisian.\n");
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	while(CInt != 999)
	{
		InsVLast(&L2,CInt);
		printf(" Masukkan nilai = ");
		scanf("%d",&CInt);
	}
	printf(" Isi List 2 sekarang : ");
	PrintInfo(L2);
	
	// Insert Address
	printf("\nCara 1 \"InsertFirst\" ke L1\n");
	printf(" Masukkan 999 untuk mengakhiri pengisian.\n");
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	while(CInt != 999)
	{
		InsertFirst(&L1,Alokasi(CInt));
		printf(" Masukkan nilai = ");
		scanf("%d",&CInt);
	}
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	printf("\nCara 2 \"InsertAfter\" ke L1\n");
	printf(" Mencari sampai ketemu infotype yang ada dalam list\n");
	printf("   Masukkan nilai yang dicari = ");
	scanf("%d",&X);
	PREC = Search(L1,X);
	while(PREC == Nil)
	{
		printf("   Masukkan nilai = ");
		scanf("%d",&X);
		PREC = Search(L1,X);
	}
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	InsertAfter(&L1,Alokasi(CInt),PREC);
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	printf("\nCara 3 \"InsertLast\" ke L1\n");
	printf(" Masukkan 999 untuk mengakhiri pengisian.\n");
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	while(CInt != 999)
	{
		InsertLast(&L1,Alokasi(CInt));
		printf(" Masukkan nilai = ");
		scanf("%d",&CInt);
	}
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	
	// Delete Value
	printf("\nCara 1 \"DelVFirst\" ke L1\n");
	printf(" Manghapus elemen pertama list L1.\n");
	DelVFirst(&L1,&X);
	printf(" Elemen yang dihapus adalah %d.\n",X);
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	
	printf("\nCara 2 \"DelVLast\" ke L1\n");
	printf(" Manghapus elemen terakhir list L1.\n");
	DelVLast(&L1,&X);
	printf(" Elemen yang dihapus adalah %d.\n",X);
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	
	// Delete Address
	printf("\nCara 1 \"DeleteFirst\" ke L1\n");
	printf(" Manghapus elemen pertama list L1.\n");
	DeleteFirst(&L1,&PTemp);
	printf(" Elemen yang dihapus adalah %d.\n",Info(PTemp));
	Dealokasi(&PTemp);
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	printf("\nCara 2 \"DeleteP\" ke L1\n");
	printf(" Manghapus elemen X di L1.\n");
	printf(" Masukkan 999 untuk mengakhiri penghapusan.\n");
	printf(" Masukkan nilai = ");
	scanf("%d",&CInt);
	while((CInt != 999) && (IsListEmpty(L1) != true))
	{
		DeleteP(&L1,CInt);
		printf(" Masukkan nilai = ");
		scanf("%d",&CInt);
	}
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	printf("\nCara 3 \"DeleteLast\" ke L1\n");
	printf(" Manghapus elemen terakhir list L1.\n");
	DeleteLast(&L1,&PTemp);
	printf(" Elemen yang dihapus adalah %d.\n",Info(PTemp));
	Dealokasi(&PTemp);
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1);
	printf("\nCara 4 \"DeleteAfter\" ke L1\n");
	printf(" Mencari sampai ketemu infotype yang ada dalam list\n");
	printf("   Masukkan nilai yang dicari = ");
	scanf("%d",&X);
	PREC = Search(L1,X);
	while(PREC == Nil)
	{
		printf("   Masukkan nilai = ");
		scanf("%d",&X);
		PREC = Search(L1,X);
	}
	DeleteAfter(&L1,&PTemp,PREC);
	printf(" Elemen yang dihapus adalah %d.\n",Info(PTemp));
	printf(" Isi List 1 sekarang : ");
	PrintInfo(L1); */
	
	// PROSES ELEMENTER
	printf("\nNilai maksimum di L1 adalah %d (tanpa address).",Max(L1));
	printf("\nNilai maksimum di L1 adalah %d (dengan address).",
		Info(AdrMax(L1)));
	printf("\nNilai minimum di L1 adalah %d (tanpa address).",Min(L1));
	printf("\nNilai minimum di L1 adalah %d (dengan address).",
		Info(AdrMin(L1)));
	printf("\nRata-rata nilai elemen adalah %.2f.\n",Average(L1));
	
	// Proses Terhadap List
	InversList(&L1);
	printf("\nHasil invers (NbElmt = %d) : ",NbElmt(L1));
	PrintInfo(L1);
	CopyList(&L1,&L2);
	printf("\nHasil salin dengan memori sama (L2 == L1) :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	DelVLast(&L2,&X);
	printf("Hasil menghapus elemen terakhir L2 dengan perbandingannya :\n");
	printf(" \"Seharusnya isi L1 dengan L2 akan sama walaupun delete salah satunya\"\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	First(L2) = Nil;
	L2 = FCopyList(L1);
	printf("\nHasil salin dengan memory baru di L2 dari L1 :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	DelVLast(&L2,&X);
	printf("Hasil menghapus elemen terakhir L2 dengan perbandingannya :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	CpAlokList(L1,&L2);
	printf("\nHasil salin dengan memory baru di L2 dari L1 :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	DelVLast(&L2,&X);
	printf("Hasil menghapus elemen terakhir L2 dengan perbandingannya :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	DeleteAll(&L2);
	Concat(L1,L1,&L2);
	printf("\nHasil salin dengan konkatenasi L1 dan L1 ke L2 :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	DelVLast(&L2,&X);
	printf("Hasil menghapus elemen terakhir L2 dengan perbandingannya :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	Concat1(&L1,&L2,&L3);
	printf("\nHasil salin dengan konkatenasi tipe 1 L1 dan L2 ke L3 :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	printf("   L3 : ");
	PrintInfo(L3);
	DelVLast(&L3,&X);
	printf("Hasil menghapus elemen terakhir L3 dengan perbandingannya :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	printf("   L3 : ");
	PrintInfo(L3);
	DeleteAll(&L1);
	DeleteAll(&L2);
	PecahList(&L1,&L2,L3);
	printf("\nHasil pecah list L3 ke L1 dan L2 :\n");
	printf("   L1 : ");
	PrintInfo(L1);
	printf("   L2 : ");
	PrintInfo(L2);
	printf("   L3 : ");
	PrintInfo(L3);
	
	// DEALOKASI SEMUA ELEMENT LIST
	DeleteAll(&L1);
	DeleteAll(&L2);
	DeleteAll(&L3);
	return 0;
}