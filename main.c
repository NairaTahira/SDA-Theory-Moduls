#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

int main() {
    address list = NULL;
    
    // Menambahkan node ke dalam linked list
    Add_Awal(&list, 10);
    Add_Akhir(&list, 20);
    Add_Tengah(&list, 15, 1);
    
    // Menampilkan linked list
    printf("Linked List saat ini: \n");
    Tampil_List(list);
    
    // Mencari node tertentu
    cari_Node(list, 15);
    cari_Node(list, 25);
    
    // Menghapus node dari linked list
    printf("Menghapus node di awal:\n");
    hapus_Nodeawal(&list);
    Tampil_List(list);
    
    printf("Menghapus node di akhir:\n");
    hapus_NodeAkhir(&list);
    Tampil_List(list);
    
    printf("Menghapus node di posisi ke-1:\n");
    hapus_Node(&list, 1);
    Tampil_List(list);
    
    printf("Jumlah total node: %d\n", jumtot_Node(list));
    
    printf("Nilai maksimum dalam linked list: %d\n", node_Max(list));
    
    printf("Rata-rata nilai dalam linked list: %.2f\n", rata2_Node(list));
    
    printf("Menukar node dalam linked list:\n");
    tukar_Node(&list);
    Tampil_List(list);
    
    return 0;
}

