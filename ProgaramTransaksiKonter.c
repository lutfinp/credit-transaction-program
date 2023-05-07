#include <stdio.h>
#include <string.h>

char ulang = 'X';
char nomor[13];

int Menu();
int Pulsa();
int Paket();
int Harian();
int Mingguan();
int Bulanan();
int main()
{
	while (ulang == 'X')
	{
		Menu();
		printf("\n 	------------------------------------\n");
		printf("	| Ketik 'X' untuk kembali ke menu! |\n");
		printf(" 	------------------------------------\n");
		printf("\n	Masukan pilihan : ");
		scanf("%s", &ulang);
	} 
	printf("\n --------------------------------------------------------------------\n");
	printf("| Terima kasih telah berkunjung pada program transaksi konter kami! |\n");
	printf(" --------------------------------------------------------------------\n");
	return 0;
}

int Menu()
{
	int pilih_menu;
	
	struct
	{
		char judul1[50]; 
		char judul2[50];
	}welcome;
	
	strcpy(welcome.judul1 ,"     Selamat Datang di Program Transaksi Konter");
	strcpy(welcome.judul2 ,"     Silakan pilih menu yang diinginkan!");

	printf(" ---------------------------------------------------------------\n");
	printf("|	%s 	|\n", welcome.judul1);
	printf(" ---------------------------------------------------------------\n");
	printf("\n%s\n\n", welcome.judul2);
	
	typedef struct 
	{
		char Menu[30];
	}Milih;
	
	Milih menu1 = {"Isi Pulsa"};
	Milih menu2 = {"Paket Internet"};
	Milih *a;	a = &menu1;
	Milih *b;	b = &menu2;

	printf("	==========================\n");
	printf("	|    Pilihan Menu :      |\n");
	printf("	|     1. %s       |\n", a->Menu);
	printf("	|     2. %s  |\n", b->Menu);
	printf("	==========================\n");
	printf("\n     Masukan pilihan menu yang diinginkan : ");
	scanf("%d", &pilih_menu);
	switch(pilih_menu)
	{
		case 1 : Pulsa(); break;
		case 2 : Paket(); break;
	}

	return 0;
}

int Pulsa()
{
	int paket, konfir, i;
	float nominal[]={0,10, 20, 25, 50, 100, 200};
	float harga[]={0, 12, 22, 27, 52, 102, 202};
	printf("\n  ------------------------------------------------------\n");
	printf(" | 		Selamat datang di menu ISI PULSA	|\n");
	printf("  ------------------------------------------------------\n");
	
	printf("\n     Masukkan Nomor Handphone : ");
	scanf("%s", &nomor);
	printf("\n");
	if (strlen(nomor)==11 || strlen(nomor)==12 || strlen(nomor)==13)
	{
		printf("\n     Silakan pilih nominal pengisian yang diinginkan!\n\n");
		printf("		=========================\n");
		printf("		|			|\n");
		printf("		|     Pilihan Pulsa :   |\n");
		printf("		|     1. 10.000         |\n");
		printf("		|     2. 20.000         |\n");
		printf("		|     3. 25.000         |\n");
		printf("		|     4. 50.000         |\n");
		printf("		|     5. 100.000	|\n");
		printf("		|     6. 200.000   	|\n");
		printf("		|			|\n");
		printf("		=========================\n");
		
		printf("     Masukan pilihan nominal pengisian yang diinginkan : ");
		scanf("%d", &paket);
		if (paket<1 || paket>6)
		{
			printf("     Paket yang Anda Pilih Tidak Tersedia");
			Pulsa();
		}
		else
		{
			for (i=1; i<=6; i++)
			{
				if( i == paket)
				{
					printf("\n	 ------------ \n");
					printf("	| Konfirmasi |\n");
					printf(" 	 ------------ \n");
					printf(" 	Nomor anda %s dengan pilihan nominal %.3f\n", nomor, nominal[i]); 
					printf(" 	Dengan Harga : %.3f", harga[i]);
					printf(" \n 	Jika Benar ketik 1, Jika Tidak ketik 0\n\t");
					scanf("%d", &konfir);
					if(konfir == 1)
					{
						printf("\n	---------------------------\n");
						printf("	|         PEMBAYARAN	    |\n");
						printf(" 	---------------------------\n");
						printf("\n");
						printf("	Total yang harus kamu bayar untuk membeli pulsa %.3f adalah sebesar : \n", nominal[i]);
						printf(" 	---------------\n");
						printf("	| Rp. %.3f  |\n", harga[i]);
						printf(" 	---------------\n");
						printf("	Terima kasih telah melakukan pembelian pulsa!\n");
					}
			 		else
					{
						Pulsa();
					}
				}
			}
		}
	}
	else
	{
		printf("Nomor yang anda masukkan tidak valid\n");
		Pulsa();
	}
	return 0;
}

int Paket()
{
	int paket;
	printf("\n  ------------------------------------------------------\n");
	printf(" | 	Selamat datang di menu PAKET INTERNET		|\n");
	printf("  ------------------------------------------------------\n");
	
	printf("\n     Masukkan Nomor Handphone : ");
	scanf("%s", &nomor);
	printf("\n");
	if (strlen(nomor)==11 || strlen(nomor)==12 || strlen(nomor)==13)
	{
		printf("\n     Silakan pilih paket internet yang diinginkan!\n\n");
		printf("	=========================\n");
		printf("	|			|\n");
		printf("	|   Pilihan Paket :	|\n");
		printf("	|    1. Paket Harian	|\n");
		printf("	|    2. Paket Mingguan	|\n");
		printf("	|    3. Paket Bulanan	|\n");
		printf("	|			|\n");
		printf("	=========================\n");
		printf("\n");
		
		printf("     Masukan pilihan paket internet yang diinginkan : ");
		scanf("%d", &paket);
		switch(paket)
		{
			case 1 : Harian(); break;
			case 2 : Mingguan(); break;
			case 3 : Bulanan(); break;
		}
	}
	else
	{
		printf("     Nomor yang anda masukkan tidak valid\n");
		Paket();
	}
	return 0;
}

int Harian()
{
	int paket, i, konfir;
	float harga[]={0,5, 7, 15, 25}; //harga paket internetnya
	int Kuota[]={0,300,500,1,2};
	char size[]={'b','M','M','G','G'};
	printf("\n	 ------------------------------------------------\n");
	printf("	| Selamat datang di menu paket Internet HARIAN ! |\n");
	printf(" 	------------------------------------------------\n");
	printf("\n     Silakan pilih paket internet yang diinginkan!\n\n");	
	printf("	=================================\n");
	printf("	|				|\n");
	printf("	|   Pilihan Paket Harian:	|\n");
	printf("	|    1. Kuota 300 MB /hari	|\n");
	printf("	|    2. Kuota 500 MB /hari	|\n");
	printf("	|    3. Kuota 1 GB /hari	|\n");
	printf("	|    4. Kuota 2 GB /hari	|\n");
	printf("	|				|\n");
	printf("	=================================\n");
	printf("\n");
	printf("     Masukan pilihan paket internet harian yang diinginkan : ");
	scanf("%d", &paket);
	if (paket<1 || paket>4)
	{
		printf("     Paket yang Anda Pilih Tidak Tersedia");
		Harian();
	}	
	else
	{
		for (i=1; i<=4; i++)
		{	
			if( i == paket)
			{
				printf("\n	 ------------ \n");
				printf("	| Konfirmasi |\n");
				printf(" 	 ------------ \n");
				printf(" 	Nomor anda %s dengan pilihan paket Internet Harian %d %cB\n", nomor, Kuota[i], size[i]); 
				printf(" 	Dengan Harga : %.3f", harga[i]);
				printf(" \n 	Jika Benar ketik 1, Jika Tidak ketik 0\n\t");
				scanf("%d", &konfir);
				
				if(konfir == 1)
				{
					printf("\n 	----------------------------\n");
					printf("	|         PEMBAYARAN	    |\n");
					printf("	-----------------------------\n");
					printf("\n");
					printf("     Total yang harus kamu bayar untuk membeli paket harian ini adalah sebesar : \n");
					printf(" 	---------------\n");
					printf("	| Rp. %.3f  |\n", harga[i]);
					printf(" 	---------------\n");
					printf("     Terima kasih telah melakukan pembelian paket internet!\n");
				} 
				else
				{
					Harian();
				}
			}
		}
	}
	
	return 0;
}

int Mingguan()
{
	int paket, i, konfir;
	float harga[]={0,14, 25, 35, 45}; //harga paket internetnya
	float Kuota[]={0, 1, 2.75, 3.75, 9};
	char size[]={'b','G','G','G','G'};	
	
	printf("\n	 ------------------------------------------------\n");
	printf("	| Selamat datang di menu paket Internet MINGGUAN ! |\n");
	printf(" 	------------------------------------------------\n");
	printf("\n     Silakan pilih paket internet yang diinginkan!\n\n");	
	printf("	=================================\n");
	printf("	|				|\n");
	printf("	|   Pilihan Paket Mingguan:	|\n");
	printf("	|    1. Kuota 1.00 GB / 7 hari	|\n");
	printf("	|    2. Kuota 2.75 GB / 7 hari	|\n");
	printf("	|    3. Kuota 3.75 GB / 7 hari	|\n");
	printf("	|    4. Kuota 9.00 GB / 10 hari	|\n");
	printf("	|				|\n");
	printf("	=================================\n");
		
	printf("\n     Masukan pilihan paket internet mingguan yang diinginkan : ");
	scanf("%d", &paket);
	if (paket<1 || paket>4)
	{
		printf("     Paket yang Anda Pilih Tidak Tersedia");
		Mingguan();
	}		
	else
	{
		for (i=1; i<=4; i++)
		{	
			if( i == paket)
			{
				printf("\n	 ------------ \n");
				printf("	| Konfirmasi |\n");
				printf(" 	 ------------ \n");
				printf(" 	Nomor anda %s dengan pilihan paket Internet Mingguan %.2f %cB\n", nomor, Kuota[i], size[i]); 
				printf(" 	Dengan Harga : %.3f", harga[i]);
				printf(" \n 	Jika Benar ketik 1, Jika Tidak ketik 0\n\t");
				scanf("%d", &konfir);
			
				if(konfir == 1)
				{
					printf("\n 	----------------------------\n");
					printf("	|         PEMBAYARAN	    |\n");
					printf("	-----------------------------\n");
					printf("\n");
					printf("     Total yang harus kamu bayar untuk membeli paket mingguan ini adalah sebesar : \n");
					printf(" 	---------------\n");
					printf("	| Rp. %.3f  |\n", harga[i]);
					printf(" 	---------------\n");
					printf("     Terima kasih telah melakukan pembelian paket internet!\n");
				} 
				else
				{
					Mingguan();
				}
			}
		}
	}
		
	return 0;
}

int Bulanan()
{
	int paket, i, konfir;
	float harga[]={0,50, 60, 70, 90}; //harga paket internetnya
	int Kuota[]={0,12,15,18,24};
	char size[]={'b','G','G','G','G'};
	
	printf("\n	 ------------------------------------------------\n");
	printf("	| Selamat datang di menu paket Internet BULANAN ! |\n");
	printf(" 	------------------------------------------------\n");
	printf("\n     Silakan pilih paket internet yang diinginkan!\n\n");	
	printf("	=================================\n");
	printf("	|				|\n");
	printf("	|   Pilihan Paket Bulanan:	|\n");
	printf("	|    1. Kuota 12 GB / 30 hari	|\n");
	printf("	|    2. Kuota 15 GB / 30 hari	|\n");
	printf("	|    3. Kuota 18 GB / 30 hari	|\n");
	printf("	|    4. Kuota 24 GB / 30 hari	|\n");
	printf("	|				|\n");
	printf("	=================================\n");
		
	printf("\n     Masukan pilihan paket internet bulanan yang diinginkan : ");
	scanf("%d", &paket);
	if (paket<1 || paket>4)
	{
		printf("     Paket yang Anda Pilih Tidak Tersedia");
		Bulanan();
	}	
	else
	{
		for (i=1; i<=4; i++)
		{
			if( i == paket)
			{
				printf("\n	 ------------ \n");
				printf("	| Konfirmasi |\n");
				printf(" 	 ------------ \n");
				printf(" 	Nomor anda %s dengan pilihan paket Internet Bulanan %d %cB\n", nomor, Kuota[i], size[i]); 
				printf(" 	Dengan Harga : %.3f", harga[i]);
				printf(" \n 	Jika Benar ketik 1, Jika Tidak ketik 0\n\t");
				scanf("%d", &konfir);
	
				if(konfir == 1)
				{
					printf("\n 	----------------------------\n");
					printf("	|         PEMBAYARAN	    |\n");
					printf("	-----------------------------\n");
					printf("\n");
					printf("     Total yang harus kamu bayar untuk membeli paket bulanan ini adalah sebesar : \n");
					printf(" 	---------------\n");
					printf("	| Rp. %.3f  |\n", harga[i]);
					printf(" 	---------------\n");
					printf("     Terima kasih telah melakukan pembelian paket internet!\n");
				} 
				else
				{
					Bulanan();
				}
			}
		}
	}
		
	return 0;
}
