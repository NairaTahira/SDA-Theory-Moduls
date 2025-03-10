#include <stdio.h>
#include <stdlib.h>
#include "Modul.h"

int main() {
    address p = NULL;
    int nilai;

    // Adding nodes
    printf("Tugas Implementasi Kode berupa Single Linked List\n\n");
    printf("Made by:\n");
    printf("Nama: Naira Tahira (241511022)\n");
	printf("Nama: Nashwa Fathia(241511023)\n\n");
    
	
	printf("Initiating Program: \n\n");
	
    printf("Bagian: Nashwa Fathia (24151123): \n");
//    Create_Node(&p);
    Add_Awal(&p, 45);
    Add_Awal(&p, 12);
    Add_Awal(&p, 88);
    Add_Akhir(&p, 33);
    Add_Akhir(&p, 77);
    
    printf("List setelah beberapa penambahan:\n");
    Tampil_List(p);

    // Adding a node in the middle
    Add_Tengah(&p, 99, 4);
    printf("\nMenambahkan node di tengah:\n");
    Tampil_List(p);

    // Removing nodes
    hapus_Nodeawal(&p);
    printf("\nMenghapus node awal:\n");
    Tampil_List(p);

    hapus_NodeAkhir(&p);
    printf("\nMenghapus node akhir:\n");
    Tampil_List(p);
	
	
	printf("\n\nBagian: Naira Tahira (241511022):");
    // Deleting from a different position
    hapus_Node(&p, 3);
    printf("\nMenghapus node ke-3:\n");
    Tampil_List(p);

    // Searching for a node
    printf("\nMencari node 33:\n");
    cari_Node(p, 33);

    // Printing statistics
    printf("\nJumlah Node : %d\n", jumtot_Node(p));
    printf("Nilai Max : %d\n", node_Max(p));
    printf("Rata-rata Node : %.2f\n", rata2_Node(p));

    // Swapping nodes
    printf("\nMenukar node:\n");
    tukar_Node(&p);
    Tampil_List(p);

    return 0;
}
