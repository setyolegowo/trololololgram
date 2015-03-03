#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "interface.h"

int main() {
	//Kamus Umum
	char pilih1;
    int pilih2;
    int jeda;
	//Algoritma
	system("CLS");
	printf("           TRA LA LA LA LA GRAM         \n");
    printf("  (~ 'w')~                      ~('w' ~)\n");
    printf("  ======================================\n");
    printf("        THIS IS A MESSAGING TOOL        \n");
    printf("  ======================================\n\n\nLoading main menu_");
    jeda = 1; delay(jeda);
    do {
        Welcome();
        
        Menu();
        scanf("%c", &pilih1); //pilihan: A, B, C, atau D
        switch(pilih1) {
            case 'A':
                do {
                    ModusA();
                    scanf("%d", &pilih2);
                    switch(pilih2) {
                        case 1:
                            A1();
                            printf("\nPesan berhasil direkam_\n");
                            delay(jeda);
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                    }
                } while ((pilih2 != 8) && (pilih2 != 9));
                break;
            case 'B':
                do {
                    ModusB();
                    scanf("%d", &pilih2);
                    switch(pilih2) {
                        case 1:
                            A1();
                            printf("\nPesan berhasil direkam_\n");
                            delay(jeda);
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                    }
                } while ((pilih2 != 8) && (pilih2 != 9));
                break;
            case 'C':
                ModusC();
                break;
            case 'D':
                ModusD();
                break;
        }
    } while (pilih2 != 9);
	return 0;
}
