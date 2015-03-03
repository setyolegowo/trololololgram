#ifndef MESINKAR1_H
#define MESINKAR1_H
#include <stdio.h>
#include "boolean.h"
#ifndef MARK
	#define MARK '#'
#endif

void START(void);
/*I.S. sembarang  */
/*F.S. CC adalah karakter pertama pita  */
/*      Jika CC==MARK, EOP menyala  (true)  */
/*      Jika CC  != MARK, EOP padam  (false)  */

void STARTW(void);

void ADV(void); 
/*I.S. CC  != MARK  */
/*F.S. CC adalah karakter berikutnya dari CC pada I.S.  */
/*      Jika CC==MARK, EOP menyala  (true)  */

boolean EOP();
/* true jika CC  == MARK  */

void WRITE(char w);

void WRITESENTENCE(char * sentence);

void CLOSEBACA(void);
/* I.S. : sembarang */
/* F.S. : menutup dari pembukaan file */

void CLOSETULIS(void);

boolean IsTandaBaca(char Karakter);
// true jika karakter termasuk tanda baca, false jika karakter bukan termasuk tanda baca.

#endif
