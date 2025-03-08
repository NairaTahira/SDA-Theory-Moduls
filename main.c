#include <stdio.h>
#include "modul.h"

int main() {
    address list = NULL;
    Add_Awal(&list, 10);
    Add_Akhir(&list, 20);
    Add_Tengah(&list, 15, 1);
    Tampil_List(list);
    cari_Node(list, 15);
    cari_Node(list, 25);
    return 0;
}
