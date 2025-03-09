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
