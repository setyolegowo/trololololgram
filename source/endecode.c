// *** BODY ENCODER DAN DECODER TELEGRAM <-> MORSE ***

// *** Modul terkait ***
#include "pohon_biner.h"
#include "endecode.h"
#include "list.h"
#include "mesinkar.h"
#include "mesinKata_v1.h"
#include "boolean.h"

extern char CC;
extern char *Pita_karakter;
extern struct 
{
	unsigned int kode;
	Kata nama;
} tDaftarKar[30];
extern int nKarReg;
extern Kata CKata;

// *** Encoding dan Decoding ***
void EncodeMorse (BinTree P, char X)
{
	while (Akar(P) != X)
	{
		if (SearchTree (Left(P), X))
		{
			WRITE ('.');
			P = Left(P);
		}
		else if (SearchTree (Right(P), X))
		{
			WRITE ('-');
			P = Right(P);
		}
	}
}

char DecodeMorse (BinTree P)
{
	// Kamus
	int i;
	
	// Algoritma
	for (i = 1;i <= CKata.Length; i++)
	{
		if (CKata.TabKata[i] == '.')
			P = Left(P);
		else if (CKata.TabKata[i] == '-')
			P = Right(P);
	}
	return Akar(P);
}

void EncodeTelegram (Kata NamaFile)
{
	// KAMUS LOKAL
	int i;
	
	// ALGORITMA
	Pita_karakter = NamaFile.TabKata;
	STARTW ();
	START ();
	while (!EOP())
	{
		i = SearchKar(CC);
		if (i != -1)
		{
			WRITE (' ');
			CetakKataToFile (tDaftarKar[i].nama);
		}
		else
			WRITE (CC);
		ADV();
	}
	CLOSETULIS ();
	CLOSEBACA ();
}

void DecodeTelegram (Kata NamaFile)
{
	// Kamus
	int Idx;
	char C;
	
	// Algoritma
	Pita_karakter = NamaFile.TabKata;
	STARTW ();
	Pita_karakter = NamaFile.TabKata;
	START ();
	
	Idx = MemberKar (CKata);
	while (!EOP())
	{
		if (Idx != -1)
		{
			C = (char) tDaftarKar[Idx].kode;
			WRITE (C);
			WRITE (' ');
		}
		else
		{
			CetakKataToFile (CKata);
			WRITE (' ');
		}
		ADVKATA ();
	}
	CLOSETULIS ();
	CLOSEBACA ();
}

int SearchKar (char Kar)
{
	// Kamus
	boolean Found = false;
	int i = 0;
	
	// Algoritma
	while (!Found && i <= nKarReg)
	{
		if ((int) Kar == tDaftarKar[i].kode)
			Found = true;
		else
			i++;
	}
	if (Found)
		return i;
	else
		return -1;
}

int MemberKar (Kata CKata)
{
	// Kamus
	boolean Found = false;
	int i = 0;
	
	// Algoritma
	while (!Found && i <= nKarReg)
	{
		if (IsKataSama (CKata, tDaftarKar[i].nama))
			Found = true;
		else
			i++;
	}
	if (Found)
		return i;
	else
		return -1;
}
