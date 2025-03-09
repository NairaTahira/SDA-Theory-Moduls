#include <stdio.h>
#include <stdlib.h>


typedef int infotype;
typedef struct tNode *address;
typedef struct tNode{
    infotype info;
    address next;
} Node;

void Create_Node(address *p);
void Isi_Node(infotype Nilai, address *p);
void Tampil_List(address p);
void Add_Awal(address *p, int nilai);
void Add_Akhir(address *p, int nilai);
void Add_Tengah(address *p, int nilai, int posisi);
void cari_Node(address p, infotype nilai);
void hapus_Nodeawal(address *p);
void hapus_NodeAkhir(address *p);
void hapus_Node(address *p, int posisi);
int jumtot_Node(address p);
int node_Max(address p);
float rata2_Node(address p);
void tukar_Node(address *p);


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


int main() {
    address head = NULL;
    int nilai, posisi, pilihan;
    do {
        printf("1. Tambah Node di awal\n");
        printf("2. Tambah Node di akhir\n");
        printf("3. Tambah Node di tengah\n");
        printf("4. Cari Node\n");
        printf("5. Hapus Node di awal\n");
        printf("6. Hapus Node di akhir\n");
        printf("7. Hapus Node di tengah\n");
        printf("8. Jumlah total Node\n");
        printf("9. Nilai maksimal Node\n");
        printf("10. Rata-rata Node\n");
        printf("11. Tukar Node\n");
        printf("12. Tampilkan Node\n");
        printf("13. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                Add_Awal(&head, nilai);
                break;
            case 2:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                Add_Akhir(&head, nilai);
                break;
            case 3:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                Add_Tengah(&head, nilai, posisi);
                break;
            case 4:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &nilai);
                cari_Node(head, nilai);
                break;
            case 5:
                hapus_Nodeawal(&head);
                break;
            case 6:
                hapus_NodeAkhir(&head);
                break;
            case 7:
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                hapus_Node(&head, posisi);
                break;
            case 8:
                printf("Jumlah total Node: %d\n", jumtot_Node(head));
                break;
            case 9:
                printf("Nilai maksimal Node: %d\n", node_Max(head));
                break;
            case 10:
                printf("Rata-rata Node: %.2f\n", rata2_Node(head));
                break;
            case 11:
                tukar_Node(&head);
                break;
            case 12:
                Tampil_List(head);
                break;
            case 13:
                printf("Keluar\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    } while (pilihan != 13);

    return 0;
}