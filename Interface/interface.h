#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef interface_h
#define interface_h

void Welcome(void);
void Menu(void);
//Menampilkan Menu Utama
void ModusA(void);
//Menampilkan Modus Penulisan
void ModusB(void);
//Menampilkan Modus Pengiriman
void ModusC(void);
//Menampilkan Modus Penerimaan
void ModusD(void);
//Menampilkan Modus Pengaturan

// *** Modus Penulisan ***
void A1(void);
void A2(void);
void A3(void);

// *** Modus Pengiriman ***
void B1(void);
void B7(void);

// *** Modus Penerimaan ***
void C1(void);
void C2(void);
void C3(void);
void C7(void);

// *** Modus Pengaturan ***
void D1(void);
void D2(void);
void D3(void);
void D4(void);
void D5(void);
void D6(void);
void D7(void);

// *** Pendukung Lainnya ***
void delay(int jeda); 
//Membuat delay
#endif
