#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "interface.h"

void Header(void)
{
	// printf("\033[2J\033[1;1H"); // WAW, kode yang selalu dicari-cari
	system("cls");
	printf("                           TRO LO LO LO LOL GRAM\n");
	printf("  (~ 'w')~                                                           ~('w' ~)\n");
	printf("  ===========================================================================\n");
	printf("                          THIS IS A MESSAGING TOOL                           \n");
	printf("  ===========================================================================\n");
}
printf("               ###### ####    ##    ##     ##    ##     ##    ##     ##    ##     ##   ##      ###  ####    ##   ##   ##                \n");
	printf("                 ##   ##  # ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ## ##    ##     ##  # ##  ## ### ###                           \n");
	printf("                 ##   ####  ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ## ##    ##  ## ####  ###### ## # ##                       \n");
	printf("                 ##   ##  # ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ##  ##   ##  ## ##    ##   # ##  # ##  ## ##   ##                     \n");
	printf("                 ##   ##  #   ##    ####   ##    ####   ##    ####   ##    ####   ##   ####    ##   ##  # ##  ## ##   ##                      \n");

    printf("  ##################                                  \n");
    printf("  ##################                                         \n");    
    printf("        ####          $$$$$                   @@@                                              \n");
    printf("        ####         $      $        %%%     @   @                                                  \n");    
    printf("        ####        $      $         %%%     @   @          &&&&&&&                      ##      ##    \n");
    printf("        ####       $      $    @@@   %%%      @@@          &&&&&&&&&            $$$$     ###    ###      \n");    
    printf("        ####      $$$$$$      @   @  %%%             @@@   &&&    &&&         $     $    ## #### ##                    \n");
    printf("        ####     $    $       @   @  %%%    ======  @   @  &&          ## ##        $    ##  ##  ##                       \n");    
    printf("        ####    $      $      @   @  %%%    ======  @   @  &&   &&&&&  ###     $$$$$     ##      ##  \n");
    printf("        ####   $      $        @@@   %%%             @@@   &&      &&  ##    $    $      ##      ##           \n");    
    printf("        ####  $       $   $          %%%%%%%               &&&&&&&&&   ##   $    $    $  ##      ##        \n");
    printf("        #### $         $$$           %%%%%%%                 &&&&&&    ##    $$$$ $$$$   ##      ##                         \n");    


}
// *** Menu Utama dan Modus ***
void Menu(void) {
    system("CLS");
    printf("\n  _____________________________\n");
    printf("  #+                         +# =================================\n");
    printf("  ###+                     +### MENU UTAMA                   ==  \n");
    printf("  #####+                 +##### A - Modus Penulisan        ==    \n");
    printf("  ########+           +######## B - Modus Pengiriman     ==      \n");
    printf("  ###########+     +########### C - Modus Penerimaan       ==    \n");
    printf("  ##############+############## D - Modus Pengaturan         ==  \n");
    printf("  ############################# =================================\n");
    printf("  ############################# Pilih modus: ");
}

void ModusA(void) { 
    system("CLS"); 
    printf("\n"); 
    printf("                                =================================\n");
    printf("                                MODUS PENULISAN              ==  \n");                
    printf("  ________________________      ---------------------------==    \n"); 
    printf("  ##| |==================(++    1 - Kirim                ==      \n");
    printf("  ##| |==================(   +  2 - Hitung Harga       ==        \n");
    printf("  ##| |==================(++    3 - Statistik            ==      \n");
    printf("                                8 - Ubah Modus Penggunaan  ==    \n");
    printf("                                9 - Keluar                   ==  \n");
    printf("                                =================================\n");
    printf("                                Pilih menu: ");
}

void ModusB(void) {
    system("CLS");
    printf("\n"); 
    printf("                                =================================\n"); 
    printf("        #                       MODUS PENGIRIMAN             ==  \n");
    printf("       ####        ####         1 - Transmit Semua Pesan   ==    \n");
    printf("       ######    #######======= 7 - Statistik            ==      \n");
    printf("       ######## #######         8 - Ubah Modus Penggunaan  ==    \n");
    printf("    #   ################        9 - Keluar                   ==  \n");
    printf("     ###################        =================================\n");
    printf("     ##################         ||\n");
    printf("       ###############          ||\n");
    printf("         ##########             Pilih menu: ");
}

void ModusC(void) {
    system("CLS");
    printf("\n");
    printf("    $         $    ___\n");
    printf("           $    $ |_  |         =================================\n");
    printf("$                   | |         MODUS PENERIMAAN             ==\n");
    printf("               #####| |######   1 - List Pesan             ==\n");
    printf("              ######| |####  #  2 - Baca Pesan           ==\n");
    printf("             #######|_|###    # 3 - Hapus Pesan        ==            \n");
    printf("             #############    # 7 - Statistik            ==    \n");
    printf("             ############# __ # 8 - Ubah Modus Penggunaan  ==  \n");
    printf("             #############____# 9 - Keluar                   ==  \n");
    printf("                      [ ]       =================================\n");
    printf("                      [ ]       Pilih menu: ");
}

void ModusD(void) {
    system("CLS");
    printf("\n");
    printf("     ___________ ___________    ==========================================\n");
    printf("  #@|  $$$      |           |@# MODUS PENGATURAN                      == \n");
    printf("  ##|  $$$      |           |## ------------------------------------==    \n");
    printf("  #@|  $ $      |           |@# 1 - Daftar Harga                  ==  \n");      
    printf("  #@|  ' '      |           |@# 2 - List Item Kamus             ==    \n");
    printf("  #@|           |           |@# 3 - Penambahan Item Kamus     ==      \n");
    printf("  #@|           |           |@# 4 - Penghapusan Item Kamus  ==        \n");                   
    printf("  #@|           |           |@# 5 - List Pelanggan            ==          \n");               
    printf("  #@|           |           |@# 6 - Penambahan Pelanggan        ==        \n");  
    printf("  #@|           |           |@# 7 - Penghapusan Pelanggan         ==      \n");               
    printf("  #@|           |           |@# 8 - Ubah Modus Penggunaan           ==    \n");            
    printf("  #@|___________|___________|@# 9 - Keluar                            ==  \n");     
    printf("  ############################# ==========================================\n");
    printf("                                Pilih menu: "); 
}

// *** Modus Penulisan ***
void A1(void) {
    //Kamus Lokal
    char humantext[160];
    //Algoritma
    printf("\nPrioritas : ");
    scanf("%s", &humantext);
    printf("Nama Pengirim : ");
    scanf("%s", &humantext);
    printf("Nama Penerima : ");
    scanf("%s", &humantext);
    printf("Pesan : ");
    scanf("%s", &humantext);
}
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
void delay(int jeda) {
    //Kamus Lokal
    int i; int c; int d;
    for (i=jeda; i>0; i--)
        for ( c = 1 ; c <= 32560  ; c++ )
            for ( d = 1 ; d <= 10000 ; d++ )
                {}
}
