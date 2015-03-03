#include "mesinkar1.h"
#include "mesinKata_v1.h"
#include <stdio.h>

/* ************************ Definisi State Mesin Kata *************************** */
extern boolean EndKata;
extern Kata CKata;

int main() {
	// KAMUS
	unsigned int i,Sum,Count,CountWhile;
	float rata2;
	Kata KataWhile;
	
	// ALGORITMA
	// Mengisi KataWhile
	KataWhile.TabKata[1] = 'w';
	KataWhile.TabKata[2] = 'h';
	KataWhile.TabKata[3] = 'i';
	KataWhile.TabKata[4] = 'l';
	KataWhile.TabKata[5] = 'e';
	KataWhile.Length = 5;
	
	Sum = 0;
	Count = 0;
	CountWhile = 0;
	STARTKATA();
	while(!EndKata)
	{
		// printf("%s ",CKata.TabKata);
		for(i=1;i<=CKata.Length;i++)
		{
			printf("%c",CKata.TabKata[i]);
		}
		if(IsKataSama(KataWhile,CKata) == true)
			CountWhile++;
		printf("\n");
		Sum += CKata.Length;
		Count++;
		ADVKATA();
	}
	rata2 = (float) Sum / (float) Count;
	printf("\nRata-rata panjang karakter dari kata-kata diatas adalah %.3f\n",rata2);
	printf("Jumlah kata while pada file tersebut adalah = %d\n",CountWhile);
	return 0;
}