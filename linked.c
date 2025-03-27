/* File        : linked.c */
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
		
 } ElmtList;

int isEmpty(address p){
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
	if (p == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void Create_Node (address *p){
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
	*p = (address)malloc(sizeof(ElmtList));
}

void Isi_Node (address *p , infotype nilai){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
	if(*p != NULL){
		(*p)->info = nilai;
		(*p)->next = NULL;
	} else {
		printf ("Node tidak dapat di isi\n");
	}
}

void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
	if(p == NULL){	
		printf("Linked list kosong\n");
		return;
	}

	while(p!= NULL){
		printf("%d -> ",(p)->info);
		p = (p)->next;
	}

	printf("NULL\n");
}

void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
//             PNew (input)
if (PNew == NULL){
	printf("PNew is NULL\n");
	return;
	}

	(PNew)->next = *p;
	*p = PNew;
}

void Ins_Akhir (address *p, address PNew){
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
	if (*p == NULL){
		*p = PNew;
	}

	address Last = *p;
	while ((Last)->next != NULL){
		Last = (Last)->next;
	}

	(Last)->next = PNew;
}

address Search(address p, infotype nilai, int *position){
    // Mencari apakah ada elemen list dengan Info(P) = nilai
    // Jika ada, mengembalikan address elemen tsb.
    // Jika tidak ada, mengembalikan Nil
    // Menggunakan variabel bertipe boolean

    address curr = p;
    *position = 0;

    while(curr != NULL){
        if(curr->info == nilai){
            return curr;
        }
        curr = curr->next;
        (*position)++;
    }
    return NULL; // Nil
}


void InsertAfter (address * pBef, address PNew){
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
	if (PNew != NULL && *pBef != NULL) {
		(PNew)->next = (*pBef)->next;
		(*pBef)->next = PNew;
	} else {
		printf ("Node Invalid\n");
	}
}

void Del_Awal(address *p, infotype *X){
    /* IS : P TIDAK Kosong */
    /* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
    /* dan alamat elemen pertama di dealokasi */

    if(*p == NULL){
        printf("Tidak ada yang dapat dihapus\n");
        return;
    }

    address temp = *p;         // Simpan node yang mau dihapus
    *X = temp->info;           // Ambil info-nya
    *p = temp->next;        // Pindahkan head ke node berikutnya
    free(temp);                // Dealokasi node lama
}


void Del_Akhir (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
	if (*p == NULL){
		printf("Tidak ada node untuk dihapus\n");
		return;
	}

	address prev = NULL;
	address Last = *p;
	
	if(Last->next == NULL){
		*X = Last->info;
		free(Last);
		*p = NULL;
	}
	
	while ((Last)->next != NULL){
		prev = Last;
		Last = (Last)->next;
	}
	*X = Last->info;
	free(Last);
	prev->next=NULL;
	
}

void Del_After (address * pBef, infotype * X){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */
	if (*pBef != NULL && (*pBef)->next != NULL){
		address temp = (*pBef)->next;
		*X = temp->info;
		(*pBef)->next = temp->next;
		free(temp);
	} else {
		printf ("Node Invalid\n");
	}

}

void DeAlokasi (address * p){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
	if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}
	
	free(*p);
	*p = NULL;
}

int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
	int Jumlah = 0;
	address curr = p;

	if (p == NULL){
		return 0;
	}

	while (curr != NULL){
		Jumlah++;
		curr = (curr)->next;
	}
	
	return Jumlah;
}

infotype Min (address p){
/* Mengirimkan nilai Info(P) yang minimum */
	if (p == NULL){
		printf("Node tidak ada\n");
		return 0;
	}
	
	int Min = (p)->info;
	address curr = (p)->next;

	while(curr != NULL){
		if ((curr)->info < Min){
			Min = (curr)->info;
		}
		curr = (curr)->next;
	}

	return Min;
}

infotype Rerata (address p){
/* Mengirimkan nilai rata-rata Info(P) */
	if(p == NULL){
		printf("Node tidak ada, rerata = 0.0\n");
		return 0;
	}
	
	address curr = p;
	int Total = 0;
	int JumlahNode = 0;
	float Rerata;

	while (curr != NULL){
		Total += (curr)->info;
		JumlahNode++;
		curr = (curr)->next;
	}

	Rerata = Total / JumlahNode;
	return Rerata;
}


/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
address BalikList(address p) {
    address prev = NULL;    
    address current = p;   
    address next = NULL;

    while (current != NULL) {
        next = (current)->next; 
        (current)->next = prev; 
        prev = current;       
        current = next;       
    }

    return prev;
}

void Destroy_All(address *p){

	if(*p == NULL){
		printf ("P sudah NULL\n");
		return;
	}

	address temp = *p;

	while(*p != NULL){
	
		temp = *p;
		*p = (*p)->next;
		free(temp);
	}

}

void Modify_First(address *p, infotype *X){
	if(*p == NULL){
		printf("Node tidak terdeteksi\n");
		return;
	}
	
	(*p)->info = *X;
}



void Modify_Between(address *p, infotype *X, int position){
	if(*p != NULL){
		address curr = *p;
		int i = 0;
		while(curr != NULL && i <= position){
			curr = curr->next;
			i++;
		}
		curr->info = *X;
	}
	
	printf("Node tidak terdeteksi\n");
	return;
}
void Modify_Last(address *p, infotype *X){
	if(*p != NULL){
		address curr = *p;
		while(curr != NULL){
			curr = curr->next;
		}
		curr->info = *X;
	}
	
	printf("Node tidak terdeteksi\n");
	return;
}

#endif

