// *** BODY INTERFACE ***
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "interface.h"

void ClearScreen(void)
{
    system("clear");
    //printf("\033[2J\033[1;1H"); // WAW, kode yang selalu dicari-cari
	//system("cls"); // Jika Windows
}

void InisialisasiUI(void)
{
	ClearScreen();
	printf("\n  ===========================================================================\n");
	printf("  Tahapan inisialisasi :\n");
}

/*void Welcome(void) {
    ClearScreen();
    printf("\n\n\n  --------------------------------------------------------- \n");
    printf("                       $$                                         \n");
    printf("                        $                                         \n");
    printf("  $         $ $$$$     $      $$$$    $$$$   $$ $$  $$      $$$$  \n");
    printf("   $      $  $    $   $     $    $  $     $   $   $   $    $    $ \n");
    printf("   $  $  $  $$$$$$   $     $       $     $   $   $   $    $$$$$$  \n");
    printf("  $  $$ $   $     $ $   $ $    $  $     $   $   $   $   $ $     $ \n");
    printf("   $   $     $$$$    $$$   $$$$    $$$$    $   $     $$    $$$$   \n");
    printf("\n\n\n       $   \n");
    printf("      $          \n");
    printf("     $           \n");
    printf("    $$$$    $$$  \n");
    printf("   $      $    $ \n");
    printf("  $    $ $    $  \n");
    printf("   $$$    $$$    \n");
    printf("  ---------------------------------------------------------\n");
}*/
    
void Header(void)
{
	ClearScreen();
	printf("  ===========================================================================\n");
	printf("  \\ ( ^ u ^ ) /                                                 \\ ( ^ u ^ ) /\n");
	printf("                                                                             \n");
	printf("  (~  ' w ')~                 TRO LO LO LO LOL GRAM               ~(' w '  ~)\n");
	printf("                                                                             \n");
	printf("  (b  ^ _ ^)b                                                     d(^ _ ^  d)\n");
	printf("  ===========================================================================\n");
	printf("              Created By : Arief - Azalea - Dinah - Rifki - Setyo            \n");
	printf("  ===========================================================================\n");
}

void Header2(void)
{
	ClearScreen();
	printf("  ===========================================================================\n");
	printf("  \\ ( ^ u ^ ) /                 TRO LO LO LO LOL GRAM           \\ ( ^ u ^ ) /\n");
	printf("  ===========================================================================\n");
}

void Menu(void) {
    printf("\n    _____________________________\n\n");
    printf("    #+                         +#     =================================\n");
    printf("    ###+                     +###     MENU UTAMA                   ==\n");
    printf("    #####+                 +#####     1 - Modus Penulisan        ==\n");
    printf("    ########+           +########     2 - Modus Pengiriman     ==\n");
    printf("    ###########+     +###########     3 - Modus Penerimaan       ==\n");
    printf("    ##############+##############     4 - Modus Pengaturan         ==\n");
    printf("    #############################     =================================\n");
    printf("    #############################     Pilih modus: ");
}

void ModusA(void) {  
    printf("\n"); 
    printf("                                      =================================\n");
    printf("                                      MODUS PENULISAN              ==\n");                
    printf("     ________________________         ---------------------------==\n"); 
    printf("     ##| |==================(++       1 - Kirim                ==\n");
    printf("     ##| |==================(   +     2 - Hitung Harga       ==\n");
    printf("     ##| |==================(++       3 - Statistik            ==\n");
    printf("                                      8 - Ubah Modus Penggunaan  ==\n");
    printf("                                      9 - Keluar                   ==\n");
    printf("                                      =================================\n");
    printf("                                      Pilih menu: ");
}

void ModusB(void) {
    printf("\n"); 
    printf("                                      =================================\n"); 
    printf("          #                           MODUS PENGIRIMAN             ==\n");
    printf("         ####        ####             1 - Transmit Semua Pesan   ==\n");
    printf("         ######    ########==         7 - Statistik            ==\n");
    printf("         ######## #######             8 - Ubah Modus Penggunaan  ==\n");
    printf("      #   ################            9 - Keluar                   ==\n");
    printf("      ####################            =================================\n");
    printf("      ####################            ||\n");
    printf("       ##################             ||\n");
    printf("         ###############              ||\n");
    printf("           ##########                 Pilih menu: ");
}

void ModusC(void) {
    printf("\n");
    printf("      $         $    ___\n");
    printf("             $    $ |_  |             =================================\n");
    printf("  $                   | |             MODUS PENERIMAAN             ==\n");
    printf("                 #####| |######       1 - List Pesan             ==\n");
    printf("                ######| |####  #      2 - Baca Pesan           ==\n");
    printf("               #######|_|###    #     3 - Hapus Pesan        ==\n");
    printf("               #############    #     7 - Statistik            ==\n");
    printf("               ############# __ #     8 - Ubah Modus Penggunaan  ==\n");
    printf("               #############____#     9 - Keluar                   ==\n");
    printf("                        [ ]           =================================\n");
    printf("                        [ ]           Pilih menu: ");
}

void ModusD(void) {
    printf("\n");
    printf("      ___________ ___________    ==========================================\n");
    printf("   #@|  $$$      |           |@# MODUS PENGATURAN                      == \n");
    printf("   ##|  $$$      |           |## ------------------------------------==\n");
    printf("   #@|  $ $      |           |@# 1 - Daftar Harga                  ==\n");      
    printf("   #@|  ' '      |           |@# 2 - List Item Kamus             ==\n");
    printf("   #@|           |           |@# 3 - Penambahan Item Kamus     ==\n");
    printf("   #@|           |           |@# 4 - Penghapusan Item Kamus  ==\n");                   
    printf("   #@|           |           |@# 5 - List Pelanggan            ==\n");               
    printf("   #@|           |           |@# 6 - Penambahan Pelanggan        ==\n");  
    printf("   #@|           |           |@# 7 - Penghapusan Pelanggan         ==\n");               
    printf("   #@|           |           |@# 8 - Ubah Modus Penggunaan           ==\n");            
    printf("   #@|___________|___________|@# 9 - Keluar                            ==\n");     
    printf("   ############################# ==========================================\n");
    printf("                                 Pilih menu: "); 
}

void penutup(void)
{
	Header();
	printf ("\n\n\n  ---------------------------------------------------------------------------");
	printf ("\n                             .:: TERIMA KASIH ::.");
	printf ("\n  ---------------------------------------------------------------------------\n\n\n\n");
}

// *** Pendukung Lainnya ***
void delay(int jeda) {
    //Kamus Lokal
    int i; int c; int d;
    for (i=jeda; i>0; i--)
        for ( c = 1 ; c <= 32560  ; c++ )
            for ( d = 1 ; d <= 10000 ; d++ )
                {}
} //procedure iseng, untuk efek doang
