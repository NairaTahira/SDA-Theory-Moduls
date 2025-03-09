#include <stdio.h>
#include <stdlib.h>
#include "Modul.h"

int main () {
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