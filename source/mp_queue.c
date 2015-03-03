#include "p_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	// Kamus
	Queue Q;
	infotype X;
	int Pr;
	void Menu (Queue *Q);
	
	// Algoritma
	CreateEmpty (&Q);
	Menu (&Q);
	printf ("Terima kasih. \n");
	return 0;
}

void Menu (Queue *Q)
{
	// Kamus
	int Option;
	infotype X;
	int Prio;
	
	// Algoritma
	do
	{
		printf ("ADT Queue \n");
		printf ("1. Tambah antrian \n");
		printf ("2. Layani antrian \n");
		printf ("3. Lihat antrian \n");
		printf ("4. Keluar \n");
		printf ("INPUT> ");
		scanf ("%d", &Option);
		printf ("\n");
		if (Option == 1)
		{
			printf ("Masukkan info : ");
			scanf ("%d", &X);
			printf ("Masukkan prioritas : ");
			scanf ("%d", &Prio);
			printf ("\n");
			Add (&*Q, X, Prio);
			PrintQueue (*Q);
		}
		else if (Option == 2)
		{
			if (IsEmpty (*Q))
				printf ("Antrian kosong. \n");
			else
			{
				Del (&*Q, &X, &Prio);
				PrintQueue (*Q);
			}
		}
		else if (Option == 3)
		{
			PrintQueue (*Q);
		}
		printf ("\n");
	} while (Option != 4);
}