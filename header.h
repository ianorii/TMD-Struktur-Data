#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

/* Saya Muhammad Rian Anugrah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
dispesifikasikan. Aamiin. */

// --------------------------------BAGIAN LIST SPASI--------------------------------
typedef struct elm* almt;
typedef struct elm {
    int space;
    almt prev;
    almt next;
} elemen_space;

typedef struct {
    elemen_space* first;
    elemen_space* tail;
} list_space;

void createSpace(list_space *L);
void addSpace(int temp, list_space *L);
void delSpace(list_space *L);


// --------------------------------BAGIAN LIST GANDA--------------------------------
typedef struct {
    char konsekuensi[81];
} data_list;

typedef struct elmnt* alamat;
typedef struct elmnt {
    data_list kontainer;
    alamat prev;
    alamat next;
} elemen_list;

typedef struct {
    elemen_list* first;
    elemen_list* tail;
} list;

// PROSEDUR CREATE LIST
void createList(list *L);

// FUNGSI MENGHITUNG ELEMEN DI DALAM LIST
int countList(list L);

// PROSEDUR ADD ELEMEN
void addFirst(data_list temp, list *L);
void addAfter(elemen_list* before, data_list temp, list *L);
void addLast(data_list temp, list *L);

// PROSEDUR DELETE ELEMEN
void delFirst(list *L);
void delAfter(elemen_list* before, list *L);
void delLast(list *L);
void delAllList(list *L);

// PROSEDUR PRINT ELEMEN
void printElemen(list L, int num);

// --------------------------------BAGIAN TREE--------------------------------
typedef struct {
    char root_name[81];
    int value;
    list list_tree;
} data_tree;

typedef struct smp* alamatsimpul;
typedef struct smp {
    data_tree kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct {
    simpul* root;
} tree;

// PROSEDUR INISIALISASI TREE
void makeTree(data_tree temp, tree *T);

// PROSEDUR MENAMBAHKAN ANAK PADA NODE TREE
void addChild(data_tree temp, simpul* root);

// -------------------PROSEDUR DELETE NODE-------------------
void delALLTree(simpul* root);              // DELTE SEMUA NODE PADA TREE
void delChild(char temp[], simpul* root);   // DELTE NODE CHILD BERDASARKAN NAMA NODE

// -------------------PROSEDUR PRINT TREE-------------------
void printTreePreOrder(simpul* root, elemen_space* point);
void printTreePostOrder(simpul* root);  // PRINT TREE SECARA POSTORFER
void printTreeList(simpul* root);       // PRINT ELEMEN LIST PADA TREE SECARA PREORDER

// FUNGSI MENCARI SIMPUL PADA TREE
simpul* findSimpul(char temp[], simpul* root);

// FUNGSI CEK POHON SAMA ATAU TIDAK
int isEqual(simpul* root1, simpul* root2);


// --------------------- BUATAN-----------------------------
// PROSEDUR MENGHAPUS CHILD YANG TIDAK TERPILIH
void pruning(simpul* root, char option[]);

// FUNGSI MENGHITUNG JUMLAH VALUE PADA TREE
int sumValue(simpul* root);

void BFS(list_space *L, simpul* root);

// --------------------------------BAGIAN QUEUE--------------------------------
typedef struct element* almtque;
typedef struct element {
    simpul* node;
    almtque next;
} elemen_queue;

typedef struct {
    elemen_queue* first;
    elemen_queue* last;
} queue;

void createQueue(queue *Q);
void addQueue(simpul* node, queue *Q);
void delQueue(queue *Q);
int queueSize(queue Q);