#include "header.h"

/* Saya Muhammad Rian Anugrah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
dispesifikasikan. Aamiin. */

int main() {
    setbuf(stdout, NULL); // matikan buffering
    // deklarasi dan input n untuk banyak root pada tree
    int n;
    scanf("%d", &n);

    tree T;             // deklarasi tree
    data_tree temp_tree;// deklarasi struct tree
    data_list temp_list;// deklarasi strcut list dalam tree

    // loop input data
    for(int i = 0; i < n; i++) {
        createList(&temp_tree.list_tree);   // deklarasi list untuk setiap simpul tree
        char key_parent[81];                // deklarasi string untuk nama parent
        int m;                              // m untuk banyak data list pada tree

        // input menggunakan regex
        scanf(" %[^#]#%[^#]#%d#%d", temp_tree.root_name, key_parent, &temp_tree.value, &m);

        // loop input data list
        for(int j = 0; j < m; j++) {
            scanf("%s", temp_list.konsekuensi);
            addFirst(temp_list, &temp_tree.list_tree);
        }

        if(i == 0) {
            // jika loop pertama maka inisialisasi root pada tree
            makeTree(temp_tree, &T);
        } else {
            // mencari simpul parent dengan nama yang sesuai dengan key
            simpul* parent = findSimpul(key_parent, T.root);
            addChild(temp_tree, parent);    // membuat simpul baru pada tree
        }
    }
    // deklarasi dan input string untuk data simpul yang akan dipilih
    char option[81];
    scanf("%s", option);

    // list spasi sebelum pruning
    list_space L1;      // deklarasi list jumlah spasi pada setiap level
    createSpace(&L1);   // inisialisasi list spasi
    BFS(&L1, T.root);   // menghitung banyak spasi pada setiap level
    
    printTreePreOrder(T.root, L1.first);    // print tree preorder

    pruning(T.root, option);    // pruning simpul tree yang tidak dipilih
    
    // list spasi sesudah pruning
    list_space L2;      // deklarasi list jumlah spasi pada setiap level
    createSpace(&L2);   // inisialisasi list spasi
    BFS(&L2, T.root);   // menghitung banyak spasi pada setiap level

    printTreePreOrder(T.root, L2.first);    // print tree preorder

    // print bagian akhir
    printf("peluang akhir yang diambil: %s\n", option);
    printf("total value: %d\n", sumValue(T.root));  // menghitung total value pada setiap simpul setelah di-pruning
    printf("semua peluang:\n");
    printTreeList(T.root);  // print list dengan pre-order berdasarkan simpul

    return 0;
}