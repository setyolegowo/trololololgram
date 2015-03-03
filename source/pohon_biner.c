#include "pohon_biner.h"
#include "mesinkar.h"
#include "list_rekursif.h"
#include <stdio.h>
#include <stdlib.h>
extern char CC;

BinTree Tree (tinfotype Akar, BinTree L, BinTree R)
{
	// Kamus
	BinTree P;
	
	// Algoritma
	P = (taddress) malloc (sizeof (Node));
	if (P != Nil)
	{
		Akar(P) = Akar;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}

void MakeTree (tinfotype Akar, BinTree L, BinTree R, BinTree *P)
{
	*P = Tree (Akar, L, R);
}

void BuildTree (BinTree *P)
{
	ADV ();
	if (CC == ')')
		*P = Nil;
	else
	{
		MakeTree (CC, Nil, Nil, &*P);
		ADV ();
		BuildTree (&Left(*P));
		BuildTree (&Right(*P));
	}
	ADV ();
}	

boolean IsTreeEmpty (BinTree P)
{
	return (P == Nil);
}

boolean IsOneElmt (BinTree P)
{
	return (!IsTreeEmpty (P) && Left (P) == Nil && Right (P) == Nil);
}

boolean IsUnerLeft (BinTree P)
{
	return (!IsTreeEmpty (P) && Left (P) != Nil && Right (P) == Nil);
}

boolean IsUnerRight (BinTree P)
{
	return (!IsTreeEmpty (P) && Left (P) == Nil && Right (P) != Nil);
}

boolean IsBiner (BinTree P)
{
	return (!IsTreeEmpty (P) && Left (P) != Nil && Right (P) != Nil);
}

void PrintPreorder (BinTree P)
{
	if (!IsTreeEmpty (P))
	{
		if (IsOneElmt (P))
			printf ("(%c", Akar(P));
		else
			printf ("(%c ", Akar(P));
		PrintPreorder (Left(P));
		PrintPreorder (Right (P));
		printf (")");
	}
	else
		printf (" NIL");
}

void PrintInorder (BinTree P)
{
	if (!IsTreeEmpty (P))
	{
		printf ("(");
		PrintInorder (Left(P));
		printf (" %c ", Akar(P));
		PrintInorder (Right(P));
		printf (")");
	}
	else
		printf ("NIL");
}

void PrintPostorder (BinTree P)
{
	if (!IsTreeEmpty (P))
	{
		printf ("(");
		PrintPostorder (Left(P));
		PrintPostorder (Right(P));
		printf ("%c", Akar(P));
		printf (") ");
	}
	else
		printf ("NIL ");
}

void PrintSpace (int h)
{
	if (h != 0)
	{
		printf (" ");
		PrintSpace (h - 1);
	}
}

void PrintTree (BinTree P, int h)
{
	if (!IsTreeEmpty (P))
	{
		printf ("%c \n", Akar(P));
		if (!IsTreeEmpty (Left(P)))
		{
			PrintSpace (h);
			PrintTree (Left(P), h + 2);
		}
		if (!IsTreeEmpty (Right(P)))
		{
			PrintSpace (h);
			PrintTree (Right(P), h + 2);
		}
	}
}

boolean SearchTree (BinTree P, tinfotype X)
{
	if (IsTreeEmpty (P))
		return false;
	else
	{
		if (Akar(P) == X)
			return true;
		else
			return (SearchTree (Left(P), X) || SearchTree (Right(P), X));
	}
}

int NbTreeElmt (BinTree P)
{
	if (IsTreeEmpty (P))
		return 0;
	else
		return (NbTreeElmt (Left(P)) + NbTreeElmt (Right(P)) + 1);
}

int NbDaun (BinTree P)
{
	if (IsTreeEmpty (P))
		return 0;
	else
	{
		if (IsOneElmt (P))
			return 1;
		else
			return (NbDaun (Left(P)) + NbDaun (Right(P)));
	}
}

boolean IsSkewLeft (BinTree P)
{
	if (IsTreeEmpty (P))
		return false;
	else
	{
		if (IsOneElmt (P))
			return true;
		else
		{
			if (IsUnerLeft (P))
				return (IsSkewLeft (Left(P)));
			else
				return false;
		}
	}
}

boolean IsSkewRight (BinTree P)
{
	if (IsTreeEmpty (P))
		return false;
	else
	{
		if (IsOneElmt (P))
			return true;
		else
		{
			if (IsUnerRight (P))
				return (IsSkewRight (Left(P)));
			else
				return false;
		}
	}
}

int Level (BinTree P, tinfotype X)
{
	if (Akar(P) == X)
		return 0;
	else
	{
		if (SearchTree (Left(P), X))
			return (Level (Left(P), X) + 1);
		else
			return (Level (Right(P), X) + 1);
	}
}

void AddDaunTerkiri (BinTree *P, tinfotype X)
{
	// Kamus
	taddress PNew;
	
	// Algoritma
	if (IsTreeEmpty (*P))
		*P = Tree (X, Nil, Nil);
	else
	{
		if (IsTreeEmpty (Left(*P)))
		{
			PNew = Tree (X, Nil, Nil);
			Left(*P) = PNew;
		}
		else
			AddDaunTerkiri (&Left(*P), X);
	}
}

void AddDaun (BinTree *P, tinfotype X, tinfotype Y, boolean inputKiri)
{
	// Kamus
	taddress PNew;
	
	// Algoritma
	if (Akar(*P) == X)
	{
		PNew = Tree (Y, Nil, Nil);
		if (inputKiri)
			Left(*P) = PNew;
		else
			Right(*P) = PNew;
	}
	else
	{
		if (SearchTree (Left(*P), X))
			AddDaun (&Left(*P), X, Y, inputKiri);
		else if (SearchTree (Right(*P), X))
			AddDaun (&Right(*P), X, Y, inputKiri);
	}
}

void DelDaunTerkiri (BinTree *P, tinfotype *X)
{
	if (Left(*P) == Nil)
	{
		if (Right(*P) == Nil)
		{
			*X = Akar(*P);
			*P = Nil;
			free (*P);
		}
		else
			DelDaunTerkiri (&Right(*P), &*X);
	}
	else
		DelDaunTerkiri (&Left(*P), &*X);
}

void DelDaun (BinTree *P, tinfotype X)
{
	if (Akar(*P) == X && IsOneElmt (*P))
	{
		*P = Nil;
		free (*P);
	}
	else
	{
		if (SearchTree (Left(*P), X))
			DelDaun (&Left(*P), X);
		if (SearchTree (Right(*P), X))
			DelDaun (&Right(*P), X);
	}
}
ListOfNode MakeListDaun (BinTree P)
{
	// Kamus
	ListOfNode L, LG;
	
	// Algoritma
	L = Nil;
	LG = Nil;
	if (IsTreeEmpty (P))
		return L;
	else
	{
		if (IsOneElmt (P))
		{
			L = Konsb (Akar(P), L);
			return L;
		}
		else
		{
			LG = Concat (MakeListDaun (Left(P)), MakeListDaun(Right(P)));
			return LG;
		}
	}
}

ListOfNode MakeListPreorder (BinTree P)
{
	// Kamus
	ListOfNode L, LG;
	
	// Algoritma
	L = Nil;
	LG = Nil;
	if (IsTreeEmpty(P))
		return L;
	else 
	{
		LG = Concat(MakeListPreorder (Left(P)), MakeListPreorder (Right(P)));
		L = Konsb (Akar(P), LG);
		return L;
	}
}

ListOfNode MakeListPostorder (BinTree P)
{
	// Kamus
	ListOfNode L, LG;
	
	// Algoritma
	L = Nil;
	LG = Nil;
	if (IsTreeEmpty(P))
		return L;
	else 
	{
		LG = Concat(MakeListPostorder (Left(P)), MakeListPostorder (Right(P)));
		L = Konse (LG, Akar(P));
		return L;
	}
}

ListOfNode MakeListLevel (BinTree P, int N)
{
	// Kamus
	ListOfNode L, LG;
	
	// Algoritma
	L = Nil;
	LG = Nil;
	if (IsTreeEmpty (P))
		return L;
	else 
	{
		if (N == 0) 
		{
			L = Konsb (N, L);
			return L;
		} 
		else 
		{
			LG = Concat(MakeListLevel (Left(P),N-1), MakeListLevel (Right(P),N-1));
			return LG;
		}
	}
}


BinTree BuildBalanceTree (int n)
{
	// Kamus
	taddress P;
	BinTree L, R;
	int nL, nR;
	tinfotype X;
	
	// Algoritma
	if (n == 0)
		return Nil;
	else
	{
		printf ("Masukkan nilai info : ");
		scanf ("%c", &X);
		P = Tree (X, Nil, Nil);
		if (P != Nil)
		{
			nL = n / 2;
			nR = n - nL - 1;
			L = BuildBalanceTree (nL);
			R = BuildBalanceTree (nR);
			Left(P) = L;
			Right(P) = R;
		}
		return P;
	}
}