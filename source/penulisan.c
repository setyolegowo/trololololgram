#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "interface.h"
#include "boolean.h"
#include "endecode.h"
#include "mesinKata_v1.h"
#include "list.h"
#include "modusKonfigurasi.h"
#include "konfigurasi.h"
#include "penulisan.h"

extern Kata CKata;
extern boolean EndKata;
extern List tDaftarPelanggan;
extern List statistik_outboks;
extern char * Pita_karakter;
extern FILE * FILEBACA; 
extern FILE * FILETULIS;
unsigned int tDaftarHarga[5];
struct {
	int SPanjang;
	int SPendek;
	int TandaBaca;
	int KarKhusus;
} SumKatKata;	//struktur untuk menyimpan jumlah kata dan tanda baca
extern struct {
	unsigned int kode;
	Kata nama;
} tDaftarKar[32];

boolean identitas (Kata snd)
//memeriksa apakah nama pengirim dan penerima telah terdaftar pada sistem sebagai pelanggan
//snd:sender:pengirim
//rcv:receiver:penerima
{
	return (Search (tDaftarPelanggan, snd, 1) != Nil);
}

boolean teschar (Kata psn)
//mengecek apakah seluruh tanda baca dan karakter khusus telah terdefinisi di kamus
{
	//Kamus
	int i;
	boolean found;
	
	//Algoritma
	found = true;
	i = 1;
	while ((i <= psn.Length) && found)
	{
		if ((!isalnum(psn.TabKata[i])) && (!isblank(psn.TabKata[i]))) {
			if (SearchKar(psn.TabKata[i]) == -1) 
				return found = false;
		}
		i++;
	}
	return found;
}

void readJustKata(Kata *k)
//Mengembalikan dalam bentuk kata yang terdiri dari karakter-karakter alphabet saja
{
	/* KAMUS LOKAL */
	int i;
	char CTemporary;
	
	/*ALGORITMA*/
	i = 0;
	scanf("%c", &CTemporary);
	for(;;)
	{
		if(isalpha(CTemporary)) {	//Memeriksa apakah karakter adalah huruf
			i++;
			(*k).TabKata[i] = toupper(CTemporary);	//Mengubah ke huruf besar
			scanf("%c", &CTemporary);
		} else {					//Karakter bukan huruf
			i++;
			(*k).TabKata[i] = toupper(CTemporary);
			break;
		}
	}
	(*k).Length = i-1;
	while(CTemporary != '\n')		//Membaca sampai pengguna memasukkan enter
	{
		scanf("%c", &CTemporary);
	}
}

void read (Kata *k) 
//Lebih mirip kalimat
//membaca nama pengirim, penerima, dan pesan
{
	/* KAMUS LOKAL */
	int i;
	
	/*ALGORITMA*/
	i = 0;
	while ((*k).TabKata[i] != '\n')
	{
		i++;
		scanf("%c", &(*k).TabKata[i]);
		(*k).TabKata[i] = toupper((*k).TabKata[i]);
	}
	(*k).Length = i-1;
}

void MakeNameFile(Kata Nama,TipeNamaFile * NamaFile)
{
	char buffer[256];
	time_t curtime;
	struct tm *loctime;
	int i;
	
	/* Get the current time. */
	curtime = time (NULL);
	
	/* Convert it to local time representation. */
	loctime = localtime (&curtime);
	
	(*NamaFile).TabKata[0] = 'O'; (*NamaFile).TabKata[1] = 'u'; 
	(*NamaFile).TabKata[2] = 't'; (*NamaFile).TabKata[3] = 'b';		//Mengarahkan file terbentuk di folder outbox
	(*NamaFile).TabKata[4] = 'o'; (*NamaFile).TabKata[5] = 'x';
	(*NamaFile).TabKata[6] = '/';
	strftime (buffer, 256, "%y%m%d%H%M%S", loctime);		//mencetak tanggal pada nama file
	for(i=0; i < 12; i++)
		(*NamaFile).TabKata[i+7] = buffer[i];
	(*NamaFile).TabKata[19] = '-';
	i = 1;
	while(i <= Nama.Length) {
		(*NamaFile).TabKata[i+19] = Nama.TabKata[i];		//mencetak nama pengirim pada nama file
		i++;
	}
	(*NamaFile).TabKata[i+19] = '.'; (*NamaFile).TabKata[i+20] = 't'; 
	(*NamaFile).TabKata[i+21] = 'x'; (*NamaFile).TabKata[i+22] = 't';
	(*NamaFile).TabKata[i+23] = '\0';
	(*NamaFile).TabKata[i+24] = '\0';
	(*NamaFile).Length = i+23;						//Hasil akhirnya adalah "Outbox/YYMMDDHHMMSS-[Pengirim].txt"
}

void translate(char Prio, Kata snd, Kata rcv, Kata psn)
//mengubah dan menyimpan pesan ke file di folder outbox
{
	//kamus
	TipeNamaFile File;
	int i, n, x, idxTitikDua;
	
	//Algoritma
	idxTitikDua = SearchKar(':');
	MakeNameFile(snd, &File);
	Pita_karakter = File.TabKata;
	SumKatKata.SPanjang = 1;
	SumKatKata.SPendek = 8;
	SumKatKata.TandaBaca = 4;
	SumKatKata.KarKhusus = 0;

	STARTW();
	WRITESENTENCE("PRIORITAS ");
	CetakKataToFile(tDaftarKar[idxTitikDua].nama);
	WRITE(' ');
	WRITE(Prio);
	WRITESENTENCE(" ENTER NAMA PENGIRIM ");
	CetakKataToFile(tDaftarKar[idxTitikDua].nama);
	WRITE(' ');
	CetakKataToFile(snd);
	WRITESENTENCE(" ENTER NAMA PENERIMA ");
	CetakKataToFile(tDaftarKar[idxTitikDua].nama);
	WRITE(' ');
	CetakKataToFile(rcv);
	WRITESENTENCE(" ENTER PESAN ");
	CetakKataToFile(tDaftarKar[idxTitikDua].nama);
	WRITE(' ');
	n = 0;
	ListItem(); //Membuka file berisi list karakter spesial
	for(i = 1; i <= psn.Length; i++)
	{
		if (isalnum(psn.TabKata[i]))	//Memeriksa apakah karakter alfanumerik
		{
			WRITE(psn.TabKata[i]);
			n++;	//untuk menghitung banyak huruf
		}
		else if (psn.TabKata[i] == ' ')
		{
			WRITE(psn.TabKata[i]);
			if (n<=11 && n>0) SumKatKata.SPendek++;		//Tambah jumlah kata pendek
			else SumKatKata.SPanjang++;					//Tambah jumlah kata panjang
			n = 0;		//nilai n dikembalikan ke 0 untuk pembacaan kata berikutnya
		}
		else if (SearchKar(psn.TabKata[i]) != -1)	//Untuk karakter selain alfanumerik
		{
			WRITE(' ');
			x = SearchKar(psn.TabKata[i]);	//Mencari nomor id karakter
			CetakKataToFile(tDaftarKar[x].nama); //Mengubah karakter ke kata
			if (IsTandaBaca(psn.TabKata[i]))	//Memeriksa apakah karakter adalah tanda baca
				SumKatKata.TandaBaca++;
			else	//karakter adalah karakter khusus
				SumKatKata.KarKhusus++;
			if(i != psn.Length) //Memeriksa apakah ini adalah karakter terakhir
			{	
				if(isalnum(psn.TabKata[i+1]))	//Bila karakter berikutnya adalah alfanumerik, 
					WRITE(' ');					//ditulis spasi untuk memisahkan dengan kata berikutnya
			}
		}
		ListItem(); //Mengecek kalau ada update karakter spesial
	}
	WRITE(MARK);
	CLOSETULIS();
}

void Kirim()
// merekam data masukan dari prioritas hingga pesan dari user
{
    // Kamus Lokal
	// Variabel yang merekam masukan user dalam tipe Kata (lihat mesinKata_v1.h)
    Kata snd, rcv, psn;
    int n;
    const int BatasGagal = 3;
    char prio;
	int tPrio;
	
	//Algoritma
    printf("\n  Prioritas\n  1 = Kritikal, 2 = Penting, 3 = Segera, 4 = Biasa : ");
    scanf("%d",&tPrio);
	getchar();
    while((tPrio < 1) || (tPrio > 4))
    {
		printf("\n  Perhatian: Prioritas yang anda masukkan tidak dapat dikategorikan.\n");
		printf("\n  Prioritas\n  1 = Kritikal, 2 = Penting, 3 = Segera, 4 = Biasa : ");
		scanf("%d",&tPrio);
		getchar();
	}
	prio = (char) (tPrio + '0');
	printf("\n  Nama Pengirim : ");
	readJustKata(&snd);
	printf("\n  Nama Penerima : ");
	readJustKata(&rcv);
	printf("\n  Pesan : \n  ");
	read(&psn);
	n = 1;
	while ((!identitas(snd) || !identitas(rcv) || !teschar(psn) || (IsKataSama(snd,rcv))) && (n <= BatasGagal)) 
	{	//Memeriksa apakah nama pengirim&penerima ada di daftar pelanggan
		if (!identitas(snd))
		{
			printf("\n  Perhatian: Nama pelanggan pengirim tidak ditemukan.\n  Masukkan lagi Nama Pengirim : ");
			readJustKata(&snd);	//Mengulang membaca nama pengirim
		}
		if (!identitas(rcv))
		{
			printf("\n  Perhatian: Nama pelanggan penerima tidak ditemukan.\n  Masukkan lagi Nama Penerima : ");
			readJustKata(&rcv);	//Mengulang membaca nama penerima
		}
		if (!teschar(psn))
		{
			printf("\n  Perhatian: Terdapat karakter dalam pesan yang tidak terdaftar.\n  Masukkan lagi Pesan : ");
			read(&psn);	//Mengulang membaca pesan
		}
		if(IsKataSama(snd,rcv))
		{
			printf("\n  Perhatian: Nama pelanggan pengirim dan penerima sama.");
			n = BatasGagal;
		}
		n++;
	}
	if(n <= BatasGagal) {
		translate(prio,snd,rcv,psn);
		Header2();
		UpdateStatistik(snd);
		HitungHarga(snd,rcv);
	} else
		printf("\n  Perhatian: Pesan tidak dapat dikirim.\n");
} 

void HitungHarga(Kata snd, Kata rcv) 
//menghitung total harga telegram
{
    //kamus
	int x, y;
	
	//algoritma
	x = (3*tDaftarHarga[0])+(SumKatKata.SPendek*tDaftarHarga[1])+(SumKatKata.SPanjang*tDaftarHarga[2])+(SumKatKata.TandaBaca*tDaftarHarga[3])+(SumKatKata.KarKhusus*tDaftarHarga[4]);	//Menghitung total harga
	y = SumKatKata.SPendek + SumKatKata.SPanjang + SumKatKata.TandaBaca + SumKatKata.KarKhusus;	//Menghitung jumlah kata
	printf ("\n                    .:: Info harga dari pesan terakhir ::.");
	printf ("\n  ---------------------------------------------------------------------------\n");
	printf("  Nama Pengirim     : "); CetakKataToLayar(snd);
	printf("\n  Nama Penerima     : "); CetakKataToLayar(rcv);
	printf("\n\n  Harga             : %d\n\n", x);
	printf("  Jumlah Total Kata : %d kata\n", y);
	printf("  Kata Pendek       : %d\n", SumKatKata.SPendek);
	printf("  Kata Panjang      : %d\n", SumKatKata.SPanjang);
	printf("  Tanda Baca        : %d\n", SumKatKata.TandaBaca);
	printf("  Lain-lain         : %d\n", SumKatKata.KarKhusus);
	printf("  Enter             : 3\n\n");
}
void HitungHargaTerakhir(void)
//menghitung total harga telegram
{
    //kamus
	int x, y;
	
	//algoritma
	x = (3*tDaftarHarga[0])+(SumKatKata.SPendek*tDaftarHarga[1])+(SumKatKata.SPanjang*tDaftarHarga[2])+(SumKatKata.TandaBaca*tDaftarHarga[3])+(SumKatKata.KarKhusus*tDaftarHarga[4]);
	y = SumKatKata.SPendek + SumKatKata.SPanjang + SumKatKata.TandaBaca + SumKatKata.KarKhusus;
	printf("\n  Harga             : %d\n\n", x);
	printf("  Jumlah Total Kata : %d kata\n", y);
	printf("  Kata Pendek       : %d\n", SumKatKata.SPendek);
	printf("  Kata Panjang      : %d\n", SumKatKata.SPanjang);
	printf("  Tanda Baca        : %d\n", SumKatKata.TandaBaca);
	printf("  Lain-lain         : %d\n", SumKatKata.KarKhusus);
	if(x != 0)
		printf("  Enter             : 3\n\n");
	else
		printf("  Enter             : 0\n\n");
}

void StatistikTulis(void)
// menghitung total jumlah pesan yang dikirim, total harganya, serta jumlah rata-rata kata per pesan
{
	/* KAMUS LOKAL */
	address P;
	int i, iS;
	
	/* ALGORITMA */
	BacaListFromFile(&statistik_outboks,"Pengaturan/statistik.pelanggan.txt");	//Membentuk list dari data di file
	printf("\n");
	if(!IsListEmpty(statistik_outboks)) {
		P = First(statistik_outboks);
		i = 1;
		while(P != Nil)
		{
			if((i % 15) == 0) {
				printf("\n  Klik ENTER atau RETURN menuju halaman selanjutnya > "); getchar();
				Header2();
				printf ("\n                      .:: STATISTIK PESAN PENGIRIMAN ::.");
                printf ("\n  ---------------------------------------------------------------------------\n");
			}
			printf("       %d. ",i);
			CetakKataToLayar(Info(P,1)); //Mencetak info P ke-1, yaitu nama pelanggan
			for(iS = 1; iS <= 17-Info(P,1).Length; iS++)
				printf(" ");	//Mengatur jarak ke data berikutnya
			printf(" %4d Pesan   ",KataToBil(Info(P,3)));	//Mencetak info P ke-3, yaitu jumlah total pesan
			printf(" %3.0f kata/pesan   ",(float) ((KataToBil(Info(P,2))) / (KataToBil(Info(P,3)))));	//Info P ke-2 adalah jumlah kata total
			printf(" Rp %7d \n",KataToBil(Info(P,4)));	//Mencetak info P ke-4, yaitu total harga
			P = Next(P);	//Ke pelanggan berikutnya
			i++;
		}
	} else
		printf("  Statistik pelanggan kosong.\n");
	printf("\n");
}
void UpdateStatistik(Kata NamaPengirim)
{
	//kamus
	int x, y;
	address PNama, PTemp;
	
	//algoritma
	x = (3*tDaftarHarga[0])+(SumKatKata.SPendek*tDaftarHarga[1])+(SumKatKata.SPanjang*tDaftarHarga[2])+(SumKatKata.TandaBaca*tDaftarHarga[3])+(SumKatKata.KarKhusus*tDaftarHarga[4]);
	y = SumKatKata.SPendek + SumKatKata.SPanjang + SumKatKata.TandaBaca + SumKatKata.KarKhusus;
	BacaListFromFile(&statistik_outboks,"Pengaturan/statistik.pelanggan.txt");
	PNama = Search(statistik_outboks,NamaPengirim,1);	//Memeriksa apakah nama pelanggan sudah terekam di statistik
	if(PNama != Nil) {
		Info(PNama,2) = BilToKata(y+KataToBil(Info(PNama,2)),6);	//Menambah jumlah kata
		Info(PNama,3) = BilToKata(1+KataToBil(Info(PNama,3)),3);	//Menambah jumlah pesan
		Info(PNama,4) = BilToKata(x+KataToBil(Info(PNama,4)),12);	//Menambah jumlah total harga
	} else {	//Nama pelanggan belum terekam di statistik
		PTemp = Alokasi(NamaPengirim,1);
		Info(PTemp,2) = BilToKata(y,6);
		Info(PTemp,3) = BilToKata(1,3);
		Info(PTemp,4) = BilToKata(x,12);
		InsertLast(&statistik_outboks, PTemp);	//Menambah data pelanggan ke akhir list
	}
	BacaListForFile(statistik_outboks,"Pengaturan/statistik.pelanggan.txt");	//Menuliskan isi list ke file
}
