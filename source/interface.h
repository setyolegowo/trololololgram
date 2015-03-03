// *** HEADER INTERFACE ***
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef interface_h
#define interface_h

void InisialisasiUI(void);
//Menampilkan tampilan khusus inisialisasi
void Header(void);
//Menampilkan header
void Header2(void);
//Menampilkan header untuk submenu
void Menu(void);
//Menampilkan Menu
void ModusA(void);
//Menampilkan Modus Penulisan
void ModusB(void);
//Menampilkan Modus Pengiriman
void ModusC(void);
//Menampilkan Modus Penerimaan
void ModusD(void);
//Menampilkan Modus Pengaturan
void penutup(void);
//Menampilkan penutup

// *** Pendukung Lainnya ***
void delay(int jeda); 
//Membuat delay
#endif
