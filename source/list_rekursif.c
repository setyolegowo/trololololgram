#include "list_rekursif.h"
#include <stdio.h>
#include <stdlib.h>

addressR LAlokasi (linfotype X)
{
	// Kamus
	addressR P;
	
	// Algoritma
	P = (addressR) malloc (sizeof (rElmtList));
	if (P != Nil)
	{
		InfoR(P) = X;
		NextR(P) = Nil;
	}
	return P;
}

void LDealokasi (addressR *P)
{
	free (*P);
}

linfotype FirstElmt (ListR L)
{
	return InfoR(L);
}

ListR Tail (ListR L)
{
	return NextR(L);
} 

ListR Konsb (linfotype e, ListR L)
{
	// Kamus
	addressR P;
	
	// Algoritma
	P = LAlokasi (e);
	if (P == Nil)
		return L;
	else
	{
		NextR(P) = L;
		return P;
	}
}

ListR Konse (ListR L, linfotype e)
{
	// Kamus
	addressR P;
	
	// Algoritma
	if (IsListEmptyR (L))
		return LAlokasi(e);
	else
	{
		if (NextR(L) == Nil)
			NextR(L) = LAlokasi (e);
		else {
			//P = Konse (Tail (L), e);
			P = L;
			L = Konsb(InfoR(P),Konse(Tail(L),e));
			LDealokasi(&P);
		}
		return L;
	}
}

boolean IsListEmptyR (ListR L)
{
	return (L == Nil);
}

ListR Copy (ListR L)
{
	if (IsListEmptyR(L))
		return Nil;
	else
		return (Konsb (FirstElmt (L), Tail (L)));
}

ListR Concat (ListR L1, ListR L2)
{
	if (IsListEmptyR (L1))
		return (Copy (L2));
	else
		return (Konsb (FirstElmt (L1), Concat (Tail (L1), L2)));
}

void PrintList (ListR L)
{
	if (!IsListEmptyR (L))
	{
		printf ("%d ", FirstElmt (L));
		PrintList (Tail(L));
	}
}

int NBElmtList (ListR L)
{
	if (IsListEmptyR (L))
		return 0;
	else
		return (NBElmtList (Tail (L)) + 1);
}

boolean SearchR (ListR L, linfotype X)
{
	if (IsListEmptyR (L))
		return false;
	else
	{
		if (FirstElmt (L) == X)
			return true;
		else
			return (SearchR (Tail (L), X));
	}
}
