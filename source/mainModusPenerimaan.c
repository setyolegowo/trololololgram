/* MODUS PENERIMAAN */

#include "boolean.h"
#include "mesinKata_v1.h"
#include "ModusPenerimaan.h"
#include <stdio.h>

int main ()
{
	// Kamus
	int pilihan, id;
	// Algoritma
	while (pilihan != 9) {
		printf ("************ MENU MODUS PENERIMAAN ************\n");
		printf ("1. List Pesan\n");
		printf ("2. Baca Pesan\n");
		printf ("3. Hapus Pesan\n");
		printf ("7. Statistik\n");
		printf ("8. Ubah Modus Penggunaan\n");
		printf ("9. Keluar\n");
		printf ("Input pilihan : ");
		scanf ("%d", &pilihan);
		if (pilihan == 1) {
			printf ("List pesan : \n");
			TampilListPesan();
		} else if (pilihan == 2) {
			printf ("Masukkan id pesan : ");
			scanf ("%d", &id);
			BacaPesan(id);
		} else if (pilihan == 3) {
			printf ("Masukkan id pesan : ");
			scanf ("%d", &id);
			HapusPesan(id);
		} else if (pilihan == 4) {
			StatistikPesan();
		}
	}
	return 0;
}