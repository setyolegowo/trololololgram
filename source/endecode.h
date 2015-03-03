// *** HEADER ENCODER DAN DECODER TELEGRAM <-> MORSE ***
#ifndef ENDECODE_H
#define ENDECODE_H

// *** Modul terkait ***
#include "pohon_biner.h"
#include "mesinkar.h"
#include "mesinKata_v1.h"
#include "boolean.h"

// *** Encoding dan Decoding ***
void EncodeMorse (BinTree P, char X);
// I.S. P terdefinisi. X pasti ada di P 
// F.S. Kode morse dari X ditampilkan 

char DecodeMorse (BinTree P);
// I.S. P terdefinisi. X pasti ada di P 
// F.S. Karakter dari kode morse X ditampilkan 

void DecodeTelegram (Kata NamaFile);
// I.S. Nama file terdefinisi 
// F.S. File di overwrite menjadi file asli (yang dapat dibaca manusia) 

void EncodeTelegram (Kata NamaFile);
// I.S. Nama file terdefinisi 
// F.S. File di overwrite menjadi file telegram 

int SearchKar (char Kar);
// Mengembalikan indeks karakter tanda baca di kamus berdasarkan karakter}
// Mengembalikan -1 jika tidak ada 

int MemberKar (Kata CKata);
// Mengembalikan indeks karakter tanda baca di kamus berdasarkan kata 
// Mengembalikan -1 jika tidak ada 

#endif
