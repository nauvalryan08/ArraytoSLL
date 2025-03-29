// File   : Metrolinked.h
// Author : Nauval Khairiyan - 241524021
// Desc   : File header untuk operasi kota dan orang

#ifndef METROLINKED_H
#define METROLINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked.h"

// Fungsi operasi kota dan nama orang
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
