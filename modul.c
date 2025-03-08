#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(Node));
    if (*p != NULL) {
        (*p)->next = NULL;
    }
}

void Isi_Node(infotype Nilai, address *p) {
    if (*p != NULL) {
        (*p)->info = Nilai;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void Add_Awal(address *p, int nilai) {
    address newNode;
    Create_Node(&newNode);
    Isi_Node(nilai, &newNode);
    newNode->next = *p;
    *p = newNode;
}

void Add_Akhir(address *p, int nilai) {
    address newNode, temp;
    Create_Node(&newNode);
    Isi_Node(nilai, &newNode);
    if (*p == NULL) {
        *p = newNode;
    } else {
        temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Add_Tengah(address *p, int nilai, int posisi) {
    if (posisi == 0) {
        Add_Awal(p, nilai);
        return;
    }
    address newNode, temp = *p;
    Create_Node(&newNode);
    Isi_Node(nilai, &newNode);
    for (int i = 0; i < posisi - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void cari_Node(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            printf("Node with value %d found.\n", nilai);
            return;
        }
        p = p->next;
    }
    printf("Node with value %d not found.\n", nilai);
}