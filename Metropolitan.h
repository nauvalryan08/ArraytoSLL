// File   : Metropolitan.h
// Author : Nauval Khairiyan - 241524021
// Desc   : File header sebagai library file Metropolitan.c

#ifndef METROPOLITAN_H
#define METROPOLITAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 10  // Maksimal jumlah kota
#define STR_MAX 50   // Maksimal panjang string

// Struktur untuk node nama dalam linked list
typedef struct NamaNode {
    char nm[STR_MAX];      // Nama seseorang
    struct NamaNode* q;    // Pointer ke nama berikutnya
} NamaNode;

// Struktur untuk node kota dalam array
typedef struct {
    char kt[STR_MAX];  // Nama kota
    NamaNode* p;       // Pointer ke linked list nama dalam kota
} KotaNode;

// Deklarasi fungsi
void tambahKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]);
void tambahOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]);
void hapusKota(KotaNode daftarKota[], int* jumlahKota, char namaKota[]);
void hapusOrang(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaOrang[]);
void insertNamaBetween(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaSebelum[], char namaBaru[]);
void insertKotaBetween(KotaNode daftarKota[], int* jumlahKota, char kotaSebelum[], char kotaBaru[]);
void cariNama(KotaNode daftarKota[], int jumlahKota, char namaOrang[]);
void editKota(KotaNode daftarKota[], int jumlahKota, char namaLama[], char namaBaru[]);
void editNama(KotaNode daftarKota[], int jumlahKota, char namaKota[], char namaLama[], char namaBaru[]);
void tampilkanSatuKota(KotaNode daftarKota[], int jumlahKota, char namaKota[]);
void tampilkanSemua(KotaNode daftarKota[], int jumlahKota);
void tampilkanMenu();

#endif
