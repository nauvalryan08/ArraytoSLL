// File   : Linked.h
// Author : Nauval Khairiyan - 241524021
// Desc   : File header untuk operasi insert, edit, delete
//          File header untuk mendefinisikan struct array dan SLL

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 20
#define STR_MAX 50

typedef struct NamaNode {
    char nm[STR_MAX];
    struct NamaNode* q;
} NamaNode;

typedef struct KotaNode {
    char kt[STR_MAX];
    NamaNode* p;
} KotaNode;

// Fungsi operasi linked list
NamaNode* createNamaNode(char nama[]);
void insertNama(NamaNode** head, char nama[]);
void insertNamaBetweenLinked(NamaNode** head, char namaSebelum[], char namaBaru[]);
void deleteNama(NamaNode** head, char nama[]);
void editNamaLinked(NamaNode* head, char namaLama[], char namaBaru[]);
void displayNama(NamaNode* head);
NamaNode* searchNama(NamaNode* head, char nama[]);

#endif
