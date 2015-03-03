#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "penulisan.h"

extern char * Pita_karakter;
extern char CC;
boolean EndKata;

List statistik_inboks;
List statistik_outboks;
List statistik_sending;
unsigned int tDaftarHarga[5];
struct {unsigned int kode;
		Kata nama;
		} tDaftarKar[30];
int nKarReg;
List tDaftarPelanggan;
Queue tQueue;

int main()
{
	/* Kamus */
	FILE *f;
	Kata rcv, snd, psn;
	int retval, i, n;
	boolean found;
	time_t timer;
	struct tm w;
	
	/* Algoritma */
	timer = time(NULL);
	printf("Nama pengirim: "); 
	read(&snd);
	printf("%d\n", snd.Length);
	printf("Pesan: "); 
	read(&psn);
	printf("%d\n", psn.Length);
	printf("The current time is %s.\n",mktime(&w));
	getchar();
	return 0;
}
	
	
	
	
	