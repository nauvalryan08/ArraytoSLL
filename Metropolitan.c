// File   : Metropolitan.c
// Author : Nauval Khairiyan - 241524021
// Desc   : File body untuk diimplementasikan di main.c

#include "Metropolitan.h"

void tambahKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota telah mencapai maksimum.\n");
        return;
    }
    strcpy(daftarKota[*jumlahKota].kt, namaKota);
    daftarKota[*jumlahKota].p = NULL;  // Kota baru, belum ada orang
    (*jumlahKota)++;
}

void tambahOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]) { 
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            NamaNode* baru = (NamaNode*)malloc(sizeof(NamaNode));
            strcpy(baru->nm, namaOrang);
            baru->q = daftarKota[i].p;  // Tambah di awal
            daftarKota[i].p = baru;
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

void hapusKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]) {
    int i = 0;
    while (i < *jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            // Hapus semua nama dalam linked list kota yang ditemukan
            NamaNode* temp = daftarKota[i].p;
            while (temp) {
                NamaNode* hapus = temp;
                temp = temp->q;
                free(hapus);
            }
            // Geser elemen array untuk mengisi slot yang dihapus
            int j = i;
            while (j < *jumlahKota - 1) {
                daftarKota[j] = daftarKota[j + 1];
                j++;
            }
            
            (*jumlahKota)--;
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

void hapusOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            NamaNode** ptr = &(daftarKota[i].p);
            while (*ptr) {
                if (strcmp((*ptr)->nm, namaOrang) == 0) {
                    NamaNode* hapus = *ptr;
                    *ptr = hapus->q;
                    free(hapus);
                    return;
                }
                ptr = &((*ptr)->q);
            }
        }
        i++;
    }
    printf("Orang tidak ditemukan di kota tersebut.\n");
}


void insertNamaBetween(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaSebelum[], char namaBaru[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            NamaNode* temp = daftarKota[i].p;

            while (temp) {
                if (strcmp(temp->nm, namaSebelum) == 0) {
                    NamaNode* baru = (NamaNode*)malloc(sizeof(NamaNode));
                    strcpy(baru->nm, namaBaru);
                    baru->q = temp->q;
                    temp->q = baru;
                    return;
                }
                temp = temp->q;
            }
        }
        i++;
    }
}

void insertKotaBetween(KotaNode daftarKota[], int* jumlahKota, char kotaSebelum[], char kotaBaru[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota telah mencapai maksimum.\n");
        return;
    }
    int i = 0;
    while (i < *jumlahKota) {
        if (strcmp(daftarKota[i].kt, kotaSebelum) == 0) {
            int j = *jumlahKota;
            while (j > i + 1) {
                daftarKota[j] = daftarKota[j - 1];
                j--;
            }
            strcpy(daftarKota[i + 1].kt, kotaBaru);
            daftarKota[i + 1].p = NULL;
            (*jumlahKota)++;
            return;
        }
        i++;
    }
}

void cariNama(KotaNode daftarKota[], int jumlahKota, char namaOrang[]) {
    int ditemukan = 0;  // Penanda jika nama ditemukan di satu atau lebih kota
    printf("Nama \"%s\" ditemukan di kota: ", namaOrang);

    int i = 0;
    while (i < jumlahKota) {
        NamaNode* temp = daftarKota[i].p;
        
        while (temp) {
            if (strcmp(temp->nm, namaOrang) == 0) {
                printf("%s, ", daftarKota[i].kt);  // Cetak kota tempat nama ditemukan
                ditemukan = 1;
            }
            temp = temp->q;
        }
        i++;
    }

    if (!ditemukan) {
        printf("Nama \"%s\" tidak ditemukan di daftar kota mana pun.\n", namaOrang);
    } else {
        printf("\b\b \n");  // Menghapus koma dan spasi terakhir untuk tampilan rapi
    }
}

void editKota(KotaNode daftarKota[], int jumlahKota, char namaLama[], char namaBaru[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaLama) == 0) {
            strcpy(daftarKota[i].kt, namaBaru);
            printf("Nama kota berhasil diubah menjadi %s\n", namaBaru);
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

void editNama(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaLama[], char namaBaru[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            NamaNode* temp = daftarKota[i].p;
            while (temp) {
                if (strcmp(temp->nm, namaLama) == 0) {
                    strcpy(temp->nm, namaBaru);
                    printf("Nama %s berhasil diubah menjadi %s\n", namaLama, namaBaru);
                    return;
                }
                temp = temp->q;
            }
            printf("Nama tidak ditemukan dalam kota tersebut.\n");
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

void tampilkanSatuKota(KotaNode daftarKota[], int jumlahKota, char namaKota[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            printf("Kota: %s\n", daftarKota[i].kt);
            NamaNode* temp = daftarKota[i].p;
            while (temp) {
                printf("  - %s\n", temp->nm);
                temp = temp->q;
            }
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

void tampilkanSemua(KotaNode daftarKota[], int jumlahKota) {
	if (jumlahKota == 0) {
        printf("Belum ada kota yang dimasukkan.\n");
        return;
    }

    int i = 0;
    while (i < jumlahKota) {
        tampilkanSatuKota(daftarKota, jumlahKota, daftarKota[i].kt);
        i++;
    }
}

void tampilkanMenu() {
    printf("\n========== MENU ==========\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Orang dalam Kota\n");
    printf("3. Hapus Kota\n");
    printf("4. Hapus Orang dalam Kota\n");
    printf("5. Tambah Kota Diantara Kota Lain\n");
    printf("6. Tambah Orang Diantara Nama lain\n");
    printf("7. Cari Kota Tempat Orang tersebut Berada\n");
    printf("8. Edit Nama Kota\n");
    printf("9. Edit Nama Orang dalam Kota\n");
    printf("10. Tampilkan Data Satu Kota\n");
    printf("11. Tampilkan Semua Data\n");
    printf("0. Keluar\n");
    printf("==========================\n");
    printf("Pilihan Anda: ");
}

