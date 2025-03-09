#include <stdio.h>
#include <stdlib.h>
#include "Modul.h"

void Create_Node(address *p) {
    *p = (Node*)malloc(sizeof(Node));
    if (*p == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    (*p)->next = NULL;
}

void Isi_Node(infotype Nilai, address *p) {
    (*p)->info = Nilai;
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
    if (posisi == 1) {
        Add_Awal(p, nilai);
        return;
    }
    address newNode, temp = *p;
    Create_Node(&newNode);
    Isi_Node(nilai, &newNode);
    for (int i = 1; i < posisi - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void cari_Node(address p, infotype nilai) {
    int posisi = 1;
    while (p != NULL) {
        if (p->info == nilai) {
            printf("Nilai %d ditemukan pada posisi %d\n", nilai, posisi);
            return;
        }
        p = p->next;
        posisi++;
    }
    printf("Nilai %d tidak ditemukan\n", nilai);
}

void hapus_Nodeawal(address *p) {
    if (*p != NULL) {
        address temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}

void hapus_NodeAkhir(address *p) {
    if (*p == NULL) return;
    if ((*p)->next == NULL) {
        free(*p);
        *p = NULL;
        return;
    }
    address temp = *p;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void hapus_Node(address *p, int posisi) {
    if (*p == NULL) return;
    if (posisi == 1) {
        hapus_Nodeawal(p);
        return;
    }
    address temp = *p;
    for (int i = 1; i < posisi - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        address delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
    }
}

int jumtot_Node(address p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int node_Max(address p) {
    if (p == NULL) return -1; // Assuming values are non-negative
    int max = p->info;
    while (p != NULL) {
        if (p->info > max) {
            max = p->info;
        }
        p = p->next;
    }
    return max;
}

float rata2_Node(address p) {
    if (p == NULL) return 0.0;
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return (float)sum / count;
}

void tukar_Node(address *p) {
    if (*p == NULL || (*p)->next == NULL) return;
    address prev = NULL, curr = *p, next = NULL;
    *p = curr->next;  // New head
    while (curr != NULL && curr->next != NULL) {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;
        if (prev != NULL) prev->next = next;
        prev = curr;
        curr = curr->next;
    }
}