#include "p_queue.h"
#include <stdio.h>
#include <stdlib.h>

void QAlokasi (qaddress *P, qinfotype X)
{
	*P = (qaddress) malloc (sizeof (ElmtQueue));
	if (P != Nil)
	{
		InfoQ(*P) = X;
		NextQ(*P) = Nil;
	}
}

void QDealokasi (qaddress *P)
{
	free (*P);
}

boolean IsEmpty (Queue Q)
{
	return (Head(Q) == Nil);
}

int NBElmt (Queue Q)
{
	// Kamus
	int Count = 0;
	qaddress P = Head(Q);
	
	// Algoritma
	if (IsEmpty (Q))
		return 0;
	else
	{
		while (P != Nil)
		{
			Count++;
			P = NextQ(P);
		}
		return Count;
	}
}

void CreateEmpty (Queue *Q)
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void Add (Queue *Q, qinfotype X, int Pr)
{
	// Kamus
	qaddress P, CP, Prec;
	boolean Stop = false;
	
	// Address
	QAlokasi (&P, X);
	if (P != Nil)
	{
		Prio(P) = Pr;
		if (IsEmpty (*Q))
		{
			Head(*Q) = P;
			Tail(*Q) = P;
		}
		else
		{
			CP = Head(*Q);
			Prec = Nil;
			while (CP != Nil && !Stop)
			{
				if (Prio(CP) <= Prio(P))
				{
					Prec = CP;
					CP = NextQ(CP);
				}
				else
					Stop = true;
			}
			if (Prec == Nil)
			{
				NextQ(P) = Head(*Q);
				Head(*Q) = P;
			}
			else
			{
				NextQ(Prec) = P;
				NextQ(P) = CP;
				if (Tail(*Q) == Prec)
					Tail(*Q) = P;
			}
		}
	}
}

void Del (Queue *Q, qinfotype *X, int *Pr)
{
	// Kamus
	qaddress P;
	
	// Algoritma
	*X = InfoHead(*Q);
	P = Head(*Q);
	*Pr = Prio(P);
	Head(*Q) = NextQ(Head(*Q));
	if (Head(*Q) == Nil)
		Tail(*Q) = Nil;
	QDealokasi (&P);
}

void DelAll (Queue *Q)
{
	// Kamus
	qinfotype X;
	int Pr;
	
	// Algoritma
	while(!IsEmpty(*Q))
	{
		Del(Q,&X,&Pr);
	}
}
