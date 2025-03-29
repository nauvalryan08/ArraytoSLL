// File   : Main.c
// Author : Nauval Khairiyan - 241524021
// Desc   : File body untuk operasi edit, insert, delete

#include "Linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membuat node baru dalam linked list nama
NamaNode* createNamaNode(char nama[]) {
    NamaNode* newNode = (NamaNode*)malloc(sizeof(NamaNode)); // Alokasi memori untuk node baru
    if (newNode) { // Pastikan alokasi memori berhasil
        strcpy(newNode->nm, nama); // Salin nama ke dalam node
        newNode->q = NULL; // Inisialisasi pointer ke NULL
    }
    return newNode; // Kembalikan node baru yang telah dibuat
}

// Fungsi untuk menambahkan nama ke linked list di akhir
void insertNama(NamaNode** head, char nama[]) {
    NamaNode* newNode = createNamaNode(nama); // Buat node baru
    if (!newNode) return; // Jika gagal alokasi, keluar dari fungsi
    
    if (*head == NULL) { // Jika linked list masih kosong
        *head = newNode; // Node baru menjadi head
        return;
    }
    
    NamaNode* temp = *head; // Pointer untuk traversing
    while (temp->q) { // Iterasi sampai elemen terakhir
        temp = temp->q;
    }
    temp->q = newNode; // Tambahkan node baru di akhir linked list
}

// Fungsi untuk menyisipkan nama di antara dua nama dalam linked list
void insertNamaBetweenLinked(NamaNode** head, char namaSebelum[], char namaBaru[]) {
    NamaNode* temp = *head; // Pointer untuk iterasi
    while (temp) { // Iterasi melalui linked list
        if (strcmp(temp->nm, namaSebelum) == 0) { // Jika nama sebelumnya ditemukan
            NamaNode* newNode = createNamaNode(namaBaru); // Buat node baru
            if (!newNode) return; // Jika gagal alokasi, keluar dari fungsi
            newNode->q = temp->q; // Hubungkan node baru ke node setelahnya
            temp->q = newNode; // Hubungkan node sebelumnya ke node baru
            return;
        }
        temp = temp->q; // Pindah ke node berikutnya
    }
}

// Fungsi untuk menghapus nama dari linked list
void deleteNama(NamaNode** head, char nama[]) {
    if (*head == NULL) return; // Jika linked list kosong, keluar dari fungsi
    
    NamaNode* temp = *head;
    NamaNode* prev = NULL;
    
    while (temp) { // Iterasi melalui linked list
        if (strcmp(temp->nm, nama) == 0) { // Jika nama ditemukan
            if (prev == NULL) { // Jika elemen pertama yang harus dihapus
                *head = temp->q; // Ubah head ke elemen berikutnya
            } else {
                prev->q = temp->q; // Hubungkan node sebelumnya ke node setelahnya
            }
            free(temp); // Bebaskan memori node yang dihapus
            return;
        }
        prev = temp; // Simpan pointer sebelumnya
        temp = temp->q; // Lanjut ke node berikutnya
    }
}

// Fungsi untuk menampilkan semua nama dalam linked list
void displayNama(NamaNode* head) {
    NamaNode* temp = head; // Pointer untuk iterasi
    while (temp) { // Iterasi melalui linked list
        printf("%s\n", temp->nm); // Cetak nama
        temp = temp->q; // Pindah ke node berikutnya
    }
}

// Fungsi untuk mencari nama dalam linked list
NamaNode* searchNama(NamaNode* head, char nama[]) {
    NamaNode* temp = head; // Pointer untuk iterasi
    while (temp) { // Iterasi melalui linked list
        if (strcmp(temp->nm, nama) == 0) { // Jika nama ditemukan
            return temp; // Kembalikan pointer ke node yang ditemukan
        }
        temp = temp->q; // Pindah ke node berikutnya
    }
    return NULL; // Jika tidak ditemukan, kembalikan NULL
}

void editNamaLinked(NamaNode* head, char namaLama[], char namaBaru[]) {
    NamaNode* temp = searchNama(head, namaLama);
    if (temp) {
        strcpy(temp->nm, namaBaru);
    }
}





