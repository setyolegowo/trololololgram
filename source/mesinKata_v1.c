/* NIM/Nama 	: 13511071 / Setyo Legowo 										  
   Nama file 	: mesinKata_v1.h
   Topik 		: Abstract Data Type Mesin Kata Akuisisi Versi 1
   Tanggal 		: 
   Deskripsi 	: */
   
/* ################################## HEADER #################################### */
#include <stdio.h>
#include "boolean.h"
#include "mesinKata_v1.h"
#include "mesinkar.h"

/* ******************************** KONSTANTA *********************************** */
// #define MARK '.'
// #define BLANK ' '
// #define NMax 50

/* **************************** Definisi Tipe Kata ****************************** */
// typedef struct {
	// char TabKata[NMax + 1];
	// unsigned int Length;
// } Kata;
// { Tabkata adalah tempat menampung/container kata,
//   Length menyatakan panjangnya kata }

/* ************************ Definisi State Mesin Kata *************************** */
extern char CC;
boolean EndKata;
Kata CKata;

/* ********************** Primitif-Primitif Mesin Kata ************************** */
void Ignore_Blank(void)
// { Mengabaikan satu atau beberapa BLANK } 
// { I.S. : CC sembarang } 
// { F.S. : CC != BLANK atau CC == MARK }
{
	while((CC == BLANK) && (CC != MARK))
		ADV();
}
void STARTKATA(void)
// { I.S. : CC sembarang } 
// { F.S. : EndKata = true, dan CC = Mark; } 
// { atau EndKata = false, CKata adalah kata yang sudah diakuisisi, 
//   CC karakter pertama sesudah karakter terakhir kata }
{
	START();
	Ignore_Blank();
	if(CC == MARK)
		EndKata = true;
	else {
		EndKata = false;
		SalinKata();
	}
}
void ADVKATA(void)
// { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata
//          yg sudah diakuisisi }
// { F.S. : Jika CC = MARK, maka EndKata = true atau EndKata = false, CKAta adalah
//          kata terakhir yang sudah diakuisisi;
//          CC karakter pertama sesudah karakter terakhir kata }
{
	Ignore_Blank();
	if(CC == MARK)
		EndKata = true;
	else
		SalinKata();
}
void SalinKata(void)
// { Mengakuisisi kata, menyimpan dalam CKata } 
// { I.S. : CC adalah karakter pertama dari kata } 
// { F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMAX,
//          sisa "kata" dibuang; CC = BLANK atauCC = MARK; CC adalah karakter
//          sesudah karakter terakhir yang diakuisisi }
{
	// KAMUS
	int i;
	
	// ALGORITMA
	i = 1;
	for(;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		if((CC == MARK) || (CC == BLANK) || (i >= NMax))
			break;
		else
			i++;
	}
	CKata.Length = i;
}

/* ******************************* Operasi Lain ********************************* */
boolean IsKataSama (Kata K1, Kata K2)
// { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama
//   dan urutan karakter yang menyusun kata juga sama }
{
	// KAMUS
	int i;
	
	// ALGORITMA
	if(K1.Length != K2.Length)
		return false;
	else {
		i = 1;
		while((i < K1.Length) && (K1.TabKata[i] == K2.TabKata[i]))
		{
			i++;
		}
		if(K1.TabKata[i] == K2.TabKata[i])
			return true;
		else
			return false;
	}
}
void CetakKataToLayar(Kata K)
{
	/* KAMUS LOKAL */
	unsigned int i;
	
	/* ALGORITMA */
	for(i = 1; i <= K.Length; i++)
		printf("%c",K.TabKata[i]);
}

void CetakKataToFile(Kata K)
{
	/* KAMUS LOKAL */
	unsigned int i;
	
	/* ALGORITMA */
	for(i = 1; i <= K.Length; i++)
		WRITE(K.TabKata[i]);
}

int KarToBil(char kar)
{
	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	
	switch(kar)
	{
		case '0' : i = 0; break;
		case '1' : i = 1; break;
		case '2' : i = 2; break;
		case '3' : i = 3; break;
		case '4' : i = 4; break;
		case '5' : i = 5; break;
		case '6' : i = 6; break;
		case '7' : i = 7; break;
		case '8' : i = 8; break;
		case '9' : i = 9; break;
	}
	return i;
}

int KataToBil(Kata K)
{
	/* KAMUS LOKAL */
	unsigned short int i;
	unsigned int Bil;
	
	/* ALGORITMA */
	i = 1;
	Bil = 0;
	while(i <= K.Length)
	{
		Bil = (10*Bil) + KarToBil(K.TabKata[i]);
		i++;
	}
	return Bil;
}

Kata BilToKata(int Bil, int N)
{
	/* KAMUS LOKAL */
	Kata KataBil;
	int i = N;
	int TBil = Bil;
	
	/* ALGORITMA */
	KataBil.Length = N;
	while(i >= 0)
	{
		KataBil.TabKata[i] = (char) (48 + (TBil % 10));
		TBil = TBil / 10;
		i--;
	}
	return KataBil;
}