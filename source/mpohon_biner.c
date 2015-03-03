#include "pohon_biner.h"
#include "mesinkar.h"
#include "list_rekursif.h"
#include <stdio.h>
#include <stdlib.h>
extern char CC;

int main ()
{
	// Kamus
	BinTree T = Nil;
	
	// Algoritma
	START ();
	BuildTree (&T);
	PrintTree (T, 3);
	return 0;
}