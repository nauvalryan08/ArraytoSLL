// File   : Main.c
// Author : Nauval Khairiyan - 241524021
// Desc   : File main tempat program berjalan

#include "Metrolinked.h"

int main () {
	KotaNode daftarKota[MAX_KOTA];
	int jumlahKota = 0;
	int pilihan;
	char namaKota[STR_MAX], namaOrang[STR_MAX], namaBaru[STR_MAX];
	char kotaSebelum[STR_MAX], namaSebelum[STR_MAX];
	
	do {
		system("cls");
		tampilkanMenu();
		scanf("%d", &pilihan);
		getchar();
		
		switch (pilihan) {
			case 1:
				system("cls");
				printf("Masukkan Nama Kota: ");
                gets(namaKota);
                tambahKota(daftarKota, &jumlahKota, namaKota);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 2:
            	system("cls");
            	printf("Masukkan Nama Kota: ");
                gets(namaKota);
                printf("Masukkan Nama Orang: ");
                gets(namaOrang);
                tambahOrang(daftarKota, jumlahKota, namaKota, namaOrang);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 3:
            	system("cls");
            	printf("Masukkan Nama Kota yang Akan Dihapus: ");
                gets(namaKota);
                hapusKota(daftarKota, &jumlahKota, namaKota);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 4:
            	system("cls");
            	printf("Masukkan Nama Kota: ");
                gets(namaKota);
                printf("Masukkan Nama Orang yang Akan Dihapus: ");
                gets(namaOrang);
                hapusOrang(daftarKota, jumlahKota, namaKota, namaOrang);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 5:
            	system("cls");
            	printf("Masukkan nama kota sebelum kota baru ini: ");
                gets(kotaSebelum);
                printf("Masukkan nama kota baru: ");
                gets(namaKota);
                insertKotaBetween(daftarKota, &jumlahKota, kotaSebelum, namaKota);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 6:
            	system("cls");
            	printf("Masukkan nama kota: ");
                gets(namaKota);
                printf("Masukkan nama orang sebelum nama baru ini: ");
                gets(namaSebelum);
                printf("Masukkan nama orang baru: ");
                gets(namaOrang);
                insertNamaBetween(daftarKota, jumlahKota, namaKota, namaSebelum, namaOrang);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 7:
            	system("cls");
            	printf("Masukkan Nama yang Dicari: ");
			    gets(namaOrang);
			    cariNama(daftarKota, jumlahKota, namaOrang);
			    printf("\n(Press ENTER untuk melanjutkan)");
			    getchar();
			    system("cls");
			    break;
            case 8:
            	system("cls");
            	printf("Masukkan Nama Kota Lama: ");
                gets(namaKota);
                printf("Masukkan Nama Kota Baru: ");
                gets(namaBaru);
                editKota(daftarKota, jumlahKota, namaKota, namaBaru);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 9:
            	system("cls");
            	printf("Masukkan Nama Kota: ");
                gets(namaKota);
                printf("Masukkan Nama Lama: ");
                gets(namaOrang);
                printf("Masukkan Nama Baru: ");
                gets(namaBaru);
                editNama(daftarKota, jumlahKota, namaKota, namaOrang, namaBaru);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 10:
            	system("cls");
            	printf("Masukkan Nama Kota yang Akan Ditampilkan: ");
                gets(namaKota);
                tampilkanSatuKota(daftarKota, jumlahKota, namaKota);
                printf("\n(Press ENTER untuk melanjutkan)");
                getchar();
                system("cls");
                break;
            case 11:
            	system("cls");
            	tampilkanSemua(daftarKota, jumlahKota);
            	printf("\n(Press ENTER untuk melanjutkan)");
            	getchar();
            	system("cls");
                break;
            case 0:
            	printf("Program Selesai. Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
		}
	} while (pilihan != 0);
	
	return 0;
}
