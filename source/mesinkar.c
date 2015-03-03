/* File  : mesinkar1.c */ 
/* Body mesinkar1.h  */ 
#ifndef MESINKAR_C 
#define MESINKAR_C 
#include <assert.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include "boolean.h" 
#include "mesinkar.h" 

/* definisi states  */ 
char CC; 

/* definisi pita  */ 

char * Pita_karakter;
static FILE * FILEBACA; 
static FILE * FILETULIS;

void START(void)  {
 /*I.S. sembarang  */ 
/*F.S. CC adalah karakter pertama pita  */ 
/*      Jika CC==MARK, EOP menyala  (true)  */
/*      Jika CC  != MARK, EOP padam  (false)  */
	FILEBACA  = fopen(Pita_karakter,"r"); 
	fscanf(FILEBACA,"%c",&CC);
} 

void STARTW(void) {
	FILETULIS = fopen(Pita_karakter,"w");
}

void ADV(void)  {
/*I.S. CC  != MARK  */ 
/*F.S. CC adalah karakter berikutnya dari CC pada I.S.  */ 
/*Jika CC==MARK, EOP menyala  (true)  */ 
	fscanf(FILEBACA,"%c",&CC);
}

void CLOSEBACA(void)
{
	fclose(FILEBACA);
}

void CLOSETULIS(void)
{
	fclose(FILETULIS);
}

boolean EOP()  { 
/* true jika CC  == MARK  */ 
	return (CC == MARK);
}

void WRITE(char w) {
	fprintf(FILETULIS,"%c",w);
}
void WRITESENTENCE(char * sentence)
{
	/* KAMUS LOKAL */
	int i;
	
	/*  ALGORITMA  */
	i = 0;
	while(sentence[i] != '\0')
	{
		fprintf(FILETULIS,"%c",sentence[i]);
		i++;
	}
}

boolean IsTandaBaca(char Karakter)
// true jika karakter termasuk tanda baca, false jika karakter bukan termasuk tanda baca.
{
	/* KAMUS LOKAL */
	int KtgTandaBaca[] = {33,34,39,46,47,58,59,63,92,96};
	boolean IsTrue;
	int i;
	
	/*  ALGORITMA  */
	IsTrue = true;
	i = 0;
	while(i <= 9 && IsTrue)
	{
		if((int) Karakter != KtgTandaBaca[i])
			IsTrue = false;
	}
	return IsTrue;
}

#endif 
