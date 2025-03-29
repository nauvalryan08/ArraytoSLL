// File   : Metrolinked.c
// Author : Nauval Khairiyan - 241524021
// Desc   : File berisi function kota dan orang

#include "Metrolinked.h"
#include "Linked.h"

// Fungsi untuk menambahkan kota baru ke daftar kota
void tambahKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]) {
    // Cek apakah jumlah kota sudah mencapai batas maksimum
    if (*jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota telah mencapai maksimum.\n");
        return;
    }
    // Salin nama kota ke dalam array daftarKota
    strcpy(daftarKota[*jumlahKota].kt, namaKota);
    // Inisialisasi linked list orang di kota tersebut sebagai NULL
    daftarKota[*jumlahKota].p = NULL;
    // Tambah jumlah kota
    (*jumlahKota)++;
}

// Fungsi untuk menambahkan orang ke dalam suatu kota
void tambahOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]) {
    int i = 0;
    // Cari kota berdasarkan nama
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            // Tambahkan nama orang ke dalam linked list di kota tersebut
            insertNama(&daftarKota[i].p, namaOrang);
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk menghapus kota dari daftar kota
void hapusKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]) {
    int i = 0;
    // Cari kota berdasarkan nama
    while (i < *jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            // Hapus semua orang dalam kota terlebih dahulu
            NamaNode* temp = daftarKota[i].p;
            while (temp) {
                NamaNode* hapus = temp;
                temp = temp->q;
                free(hapus);
            }
            // Geser elemen-elemen berikutnya ke depan untuk menutupi elemen yang dihapus
            while (i < *jumlahKota - 1) {
                daftarKota[i] = daftarKota[i + 1];
                i++;
            }
            (*jumlahKota)--;
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk menghapus seseorang dari daftar orang di suatu kota
void hapusOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            deleteNama(&daftarKota[i].p, namaOrang);
            return;
        }
        i++;
    }
    printf("Orang tidak ditemukan di kota tersebut.\n");
}

// Fungsi untuk menambahkan nama di antara dua nama dalam linked list kota tertentu
void insertNamaBetween(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaSebelum[], char namaBaru[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            insertNamaBetweenLinked(&daftarKota[i].p, namaSebelum, namaBaru);
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk menyisipkan kota di antara dua kota dalam daftar kota
void insertKotaBetween(KotaNode daftarKota[], int* jumlahKota, char kotaSebelum[], char kotaBaru[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota telah mencapai maksimum.\n");
        return;
    }
    int i = 0;
    while (i < *jumlahKota) {
        if (strcmp(daftarKota[i].kt, kotaSebelum) == 0) {
            int j = *jumlahKota;
            // Geser elemen untuk memberi ruang bagi kota baru
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
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk mencari seseorang di dalam daftar kota
void cariNama(KotaNode daftarKota[], int jumlahKota, char namaOrang[]) {
    int i = 0, found = 0;
    printf("Nama \"%s\" ditemukan di kota: ", namaOrang);
    while (i < jumlahKota) {
        if (searchNama(daftarKota[i].p, namaOrang)) {
            printf("%s, ", daftarKota[i].kt);
            found = 1;
        }
        i++;
    }
    if (!found) {
        printf("Nama tidak ditemukan.\n");
    } else {
        printf("\b\b \n");
    }
}

// Fungsi untuk mengubah nama kota yang sudah ada
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

// Fungsi untuk mengubah nama seseorang dalam daftar kota tertentu
void editNama(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaLama[], char namaBaru[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            editNamaLinked(daftarKota[i].p, namaLama, namaBaru);
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk menampilkan satu kota beserta daftar orang di dalamnya
void tampilkanSatuKota(KotaNode daftarKota[], int jumlahKota, char namaKota[]) {
    int i = 0;
    while (i < jumlahKota) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            printf("Kota: %s\n", daftarKota[i].kt);
            displayNama(daftarKota[i].p);
            return;
        }
        i++;
    }
    printf("Kota tidak ditemukan.\n");
}

// Fungsi untuk menampilkan semua kota beserta daftar orang di dalamnya
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

