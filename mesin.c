#include "header.h"

/* Saya Muhammad Rian Anugrah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
dispesifikasikan. Aamiin. */

// --------------------------------BAGIAN LIST SPASI--------------------------------
// PROSEDUR INISIALISASI LIST
void createSpace(list_space *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

// PROSEDUR MEMASUKAN NILAI SPASI
void addSpace(int temp, list_space *L) {
    // deklarasi elemen 
    elemen_space* baru = (elemen_space*) malloc(sizeof(elemen_space));

    baru->space = temp; // memasukan nilai
    baru->next = NULL;

    if((*L).first == NULL) {
        // jika list kosong
        baru->prev = NULL;
        (*L).first = baru;
    } else {
        // jika list tidak kosong
        baru->prev = (*L).tail;
        (*L).tail->next = baru;
    }
    (*L).tail = baru;   // inisialiasi tail
    baru = NULL;
}

// PROSEDUR MENGHAPUS ELEMEN PADA LIST
void delSpace(list_space *L) {
    if((*L).first != NULL) {
        // jika list tidak kosong
        if((*L).tail == (*L).first) {
            // jika hanya ada satu elemen
            (*L).first = NULL;
            (*L).tail = NULL;
        } else {
            // jika ada banyak elemen
            elemen_space* hapus = (*L).tail;
            elemen_space* before = hapus->prev;

            // menghapus elemen terakhir dan memindahkan tail
            before->next = NULL;
            hapus->prev = NULL;
            (*L).tail = before;
            free(hapus);
        }
    }
}

// --------------------------------BAGIAN LIST GANDA--------------------------------
// PROSEDUR CREATE LIST
void createList(list *L) {
    // inisialisasi
    (*L).first = NULL;
    (*L).tail = NULL;
}

// FUNGSI MENGHITUNG ELEMEN
int countList(list L) {
    int hasil = 0;
    if(L.first != NULL) {
        // jika list tidak kosong
        elemen_list* bantu;
        bantu = L.first;

        // loop menghitung elemen_list
        while(bantu != NULL) {
            hasil++;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

// PROSEDUR ADD FIRST
void addFirst(data_list temp, list *L) {
    // deklarasi dan inisialisai elemen_list baru
    elemen_list* baru;
    baru = (elemen_list*) malloc(sizeof(elemen_list));

    baru -> kontainer = temp;

    if((*L).first == NULL) {
        // jika list kosong
        baru -> next = NULL;
        baru -> prev = NULL;
        (*L).tail = baru;
    } else {
        // jikal list tidak kosong
        baru -> next = (*L).first;
        (*L).first -> prev = baru;
        baru -> prev = NULL;
    }
    (*L).first = baru;
    baru = NULL;
}

// PROSEDUR ADD AFTER
void addAfter(elemen_list* before, data_list temp, list *L) {
    // deklarasi dan inisialisai elemen_list baru
    elemen_list* baru;
    baru = (elemen_list*) malloc(sizeof(elemen_list));

    baru -> kontainer = temp;

    if(before -> next == NULL) {
        // jika letak elemen_list baru di akhir
        baru -> next = NULL;
        (*L).tail = baru;
    } else {
        // jika letak elemen_list baru tidak di akhir
        baru -> next = before -> next;
        before -> next -> prev = baru;
    }
    before -> next = baru;
    baru -> prev = before;
    baru = NULL;
}

// PROSEDUR ADD LAST
void addLast(data_list temp, list *L) {
    if((*L).first == NULL) {
        // jika list kosong
        addFirst(temp, L);
    } else {
        // jika list tidak kosong
        addAfter((*L).tail, temp, L);
    }
}

// PROSEDUR DELETE ELEMEN PERTAMA
void delFirst(list *L) {
    if((*L).first != NULL) {
        // jika list tidak kosong
        // deklarasi dan inisialisasi elemen_list hapus
        elemen_list* hapus;
        hapus = (*L).first;
        if((*L).first -> next == NULL) {
            // jika hanya ada satu elemen_list di dalam list
            (*L).first = NULL;
            (*L).tail = NULL;
        } else {
            // jika lebih dari satu elemen_list
            (*L).first = (*L).first -> next;
            (*L).first -> prev = NULL;
            hapus -> next = NULL;
        }
        free(hapus);
    }
}

// PROSEDUR DELETE ELEMEN TENGAH
void delAfter(elemen_list* before, list *L) {
    if(before != NULL) {
        // jika before bukan tidak NULL
        // deklarasi dan inisialisasi elemen_list hapus
        elemen_list* hapus = before ->next;
        if(hapus -> next == NULL) {
            // jika hapus adalah elemen_list terakhir
            (*L).tail = before;
            before -> next = NULL;
        } else {
            // jika hapus bukan elemen_list terakhir
            before -> next = hapus -> next;
            hapus -> next -> prev = before;
            hapus -> next = NULL;
        }
        hapus -> prev = NULL;
        free(hapus);
    }
}

// PROSEDUR DELETE ELEMEN TERAKHIR
void delLast(list *L) {
    if((*L).first != NULL) {
        // jika list tidak kosong
        if((*L).first == (*L).tail) {
            // jika hanya ada satu elemen_list di dalam list
            delFirst(L);
        } else {
            // jika banyak elemen_list lebih dari satu
            delAfter((*L).tail->prev, L);
        }
    }
}

// PROSEDUR DELETE SEMUA ELEMEN TERAKHIR
void delAllList(list *L) {
    if(countList(*L) != 0) {
        // jika list tidak kosong
        // loop menghapus elemen_list menggunakan delLast
        for(int i = countList(*L); i >= 1; i--) {
            delLast(L);
        }
    }
}

// PROSEDUR PRINT ELEMEN
void printElemen(list L, int num) {
    if(L.first != NULL) {
        // jika list tidak kosong
        elemen_list* bantu = L.tail;
        while(bantu != NULL) {
            for(int i = 0; i < num; i++) printf(" ");
            // PRINT DISINI
            printf("[%s]\n", bantu->kontainer.konsekuensi);

            // iterasi
            bantu = bantu->prev;
        }
    }
}

// --------------------------------BAGIAN TREE--------------------------------
// PROSEDUR INISIALISASI TREE
void makeTree(data_tree temp, tree *T) {
    // alokasi memori untuk root tree
    simpul* node = (simpul*) malloc(sizeof(simpul));

    node->kontainer = temp;  // memasukan data_tree struct
    
    // inisialisasi sibling dan child
    node->sibling = NULL;
    node->child = NULL;

    (*T).root = node;   // inisialisasi root
}

// PROSEDUR MENAMBAHKAN ANAK PADA NODE TREE
void addChild(data_tree temp, simpul* root) {
    if(root != NULL) {
        // jika simpul root tidak kosong
        // deklarasi dan inisialisasi node baru
        simpul* baru = (simpul*) malloc(sizeof(simpul));

        baru->kontainer = temp;
        baru->child = NULL;

        if(root->child == NULL) {
            // jika simpul root belum memiliki simpul anak
            baru->sibling = NULL;
            root->child = baru;
        } else {
            // jika simpul root sudah memiliki simpul anak
            if(root->child->sibling == NULL) {
                // jika simpul root memiliki simpul anak yang belum memiliki saudara / hanya memiliki satu simpul anak
                baru->sibling = root->child;
                root->child->sibling = baru;
            } else {
                // jika sudah punya banyak anak
                simpul* last = root->child;

                // mencari simpul anak terakhir untuk menghubungkan node
                while(last->sibling != root->child) {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

// PROSEDUR DELETE SEMUA NODE PADA TREE
void delALLTree(simpul* root) {
    if(root != NULL) {
        // jika simpul root tidak kosong
        simpul* point = root->child;
        if(point != NULL) {
            // jika root memiliki simpul anak

            // menghapus list yang ada dalam simpul terlebih dahulu sebelum menghapus simpulnya
            // loop menghapus jika memiliki banyak anak
            while(point->sibling != NULL && point->sibling != root->child) {
                simpul* del = point;
                point = point->sibling;
                delAllList(&del->kontainer.list_tree);  // hapus list
                delALLTree(del);                        // hapus simpul
            }
            // menghapus anak terakhir / pertama jika hanya punya satu anak
            delAllList(&point->kontainer.list_tree);    // hapus list
            delALLTree(point);                          // hapus simpul
        }
        delAllList(&root->kontainer.list_tree); // hapus root setelah seluruh anaknya terhapus
        free(root);
    }
}

// PROSEDUR MENGHAPUS SIMPUL ANAK PADA ROOT BERDASARKAN TEMP
void delChild(char temp[], simpul* root) {
    if(root != NULL) {
        // jika simpul root tidak kosong
        simpul* hapus = root->child;
        if(hapus != NULL) {
            // jika simpul root memiliki anak
            if(hapus->sibling == NULL) {
                // jika hanya mempunyai satu anak
                if(strcmp(root->child->kontainer.root_name, temp) == 0) {
                    // jika simpul anak sama dengan simpul temp
                    delALLTree(root->child);
                    root->child = NULL;
                } else {
                    printf("tidak ada simpul anak yang sesuai dengan masukan\n");
                }
            } else {
                // jika memiliki lebih dari satu simpul anak
                simpul* prev = NULL;
                int ketemu = 0;
                
                // loop untuk mencari simpul anak yang sesuai
                while(hapus->sibling != root->child && ketemu == 0) {
                    if(strcmp(hapus->kontainer.root_name, temp) == 0) {
                        // jika simpul yang dicari sudah ditemukan
                        ketemu = 1;
                    } else {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                
                if(ketemu == 0 && strcmp(hapus->kontainer.root_name, temp) == 0) {
                    // jika simpul anak terakhir sesuai dengan temp
                    ketemu = 1;
                }
                
                if(ketemu == 1) {
                    // jika simpul yang dicari ada dalam tree
                    simpul* last = root->child;
                    // mencari simpul anak terakhir untuk membantu proses jika 
                    // jika yang dihapus adalah anak terakhir
                    
                    // loop untuk mencari anak terakhir
                    while(last->sibling != root->child) {
                        last = last->sibling;
                    }
                    
                    if(prev == NULL) {
                        // jika simpul yang dihapus adalah simpul anak pertama
                        if(hapus->sibling == last && last->sibling == root->child) {
                            // jika hanya ada dua anak
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                            // jika memiliki simpul anak lebih dari dua simpul
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if(prev == root->child && hapus->sibling == root->child) {
                            // jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua
                            root->child->sibling = NULL;
                        } else {
                            /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki 
                            simpul anak lebih dari dua simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAllList(&hapus->kontainer.list_tree);    // hapus seluruh elemen list pada simpul hapus
                    delALLTree(hapus);                          // menghapu simpul hapus
                } else {
                    printf("tidak ada simpul anak yang sesuai dengan masukan\n");
                }
            }
        }
    }
}

// FUNGSI MENCARI SIMPUL PADA TREE
simpul* findSimpul(char temp[], simpul* root) {
    simpul* hasil = NULL;
    if(root != NULL) {
        // jika simpul root tidak koosng
        if(strcmp(root->kontainer.root_name, temp) == 0) {
            // jika root sesuai dengan data_tree yang dicari
            hasil = root;
        } else {
            simpul* bantu = root->child;
            if(bantu != NULL) {
                // jika simpul root memiliki simpul anak
                if(bantu->sibling == NULL) {
                    // jika memiliki satu simpul anak
                    if(strcmp(bantu->kontainer.root_name, temp) == 0) {
                        // jika simpul bantu sesuai dengan data_tree yang dicari
                        hasil = bantu;
                    } else {
                        hasil = findSimpul(temp, bantu);
                    }
                } else {
                    // jika memiliki banyak simpul anak
                    int ketemu = 0;

                    // loop mencari node yang sesuai
                    while(bantu->sibling != root->child && ketemu == 0) {
                        if(strcmp(bantu->kontainer.root_name, temp) == 0) {
                            // jika simpul bantu sesuai dengan data_tree yang dicari
                            hasil = bantu;
                            ketemu = 1;
                        } else {
                            hasil = findSimpul(temp, bantu);
                            if(hasil != NULL) return hasil;
                            bantu = bantu->sibling;
                        }
                    }

                    // memproses simpul anak terakhir karean belum terproses dalam perngulangan
                    if(ketemu == 0) {
                        if(strcmp(bantu->kontainer.root_name, temp) == 0) {
                            hasil = bantu;
                        } else {
                            hasil = findSimpul(temp, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

// PROSEDUR PRINT TREE SECARA PREORDER
void printTreePreOrder(simpul* root, elemen_space* point) {
    if(root != NULL) {
        for(int i = 0; i < point->space; i++) printf(" ");
        printf("%s - %d\n", root->kontainer.root_name, root->kontainer.value);
        printElemen(root->kontainer.list_tree, point->space);
        printf("\n");

        // jika simpul root tidak kosog
        simpul* bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki simpul anak
            if(bantu->sibling == NULL) {
                // jika hanya memiliki satu simpul anak
                printTreePreOrder(bantu, point->next);
            } else {
                // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while(bantu->sibling != root->child) {
                    printTreePreOrder(bantu, point->next);
                    bantu = bantu->sibling;
                }
                // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                printTreePreOrder(bantu, point->next);
            }
        }
    }
}

// PROSEDUR PRINT TREE SECARA POSTORDER
void printTreePostOrder(simpul* root) {
    if(root != NULL) {
        // jika simpul root tidak kosog
        simpul* bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki simpul anak
            if(bantu->sibling == NULL) {
                // jika hanya memiliki satu simpul anak
                printTreePostOrder(bantu);
            } else {
                // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while(bantu->sibling != root->child) {
                    printTreePostOrder(bantu);
                    bantu = bantu->sibling;
                }
                // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                printTreePostOrder(bantu);
            }
        }
        // print elemen_list
    }
}

// FUNGSI CEK POHON SAMA ATAU TIDAK
int isEqual(simpul* root1, simpul* root2) {
    int hasil = 1;
    if((root1 != NULL) && (root2 != NULL)) {
        // jika kedua root tidak kosong
        if(strcmp(root1->kontainer.root_name, root2->kontainer.root_name) != 0) {
            // jika isi dari kedua root tidak sama
            hasil = 0;
        } else {
            if((root1->child != NULL) && (root2->child != NULL)) {
                // jika kedua root memiliki simpul anak
                if(root1->child->sibling == NULL) {
                    // jika root1 memiliki satu simpul anak
                    hasil = isEqual(root1->child, root2->child);
                } else {
                    // jika memiliki banyak simpul anak
                    simpul* bantu1 = root1->child;
                    simpul* bantu2 = root2->child;

                    while(bantu1->sibling != root1->child) {
                        if(bantu1 != NULL && bantu2 != NULL) {
                            // jika sesuai
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        } else {
                            // jika tidak sesuai
                            hasil = 0;
                            break;
                        }
                    }
                    // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    } else {
        if(root1 != NULL || root2 != NULL) {
            // jika ada yang tidak sesuai
            hasil = 0;
        }
    }
    return hasil;
}

// PROSEDUR MENGHAPUS CHILD YANG TIDAK TERPILIH
void pruning(simpul* root, char option[]) {
    if(root != NULL) {
        // jika root tidak kosong
        if(root->child != NULL) {
            // jiak root memiliki simpul anak
            simpul* bantu = root->child;
            if(bantu->sibling == NULL) {
                // jika root hanya memiliki satu anak
                pruning(bantu, option);
            } else {
                // jika memiliki banyak anak
                simpul* last = root->child; // pointer untuk anak terakhir
                while(last->sibling != root->child) {
                    // loop mencari anak terakhir
                    last = last->sibling;
                }

                // loop mengecek simpul yang terpilih
                while(1) {
                    simpul* cari = findSimpul(option, root->child); // pointer checker
                    if(cari == NULL) {
                        // jika pada simpul saat ini tidak ditemukan target yang dicari

                        // proses menghapus simpul saat ini dan seluruh simpul anaknya
                        simpul* hapus = root->child;    // simpul hapus menampung anak pertama
                        root->child = hapus->sibling;   // memindahkan status anak pertama ke anak selanjutnya
                        if(root->child == last) {
                            // jika hanya tersisa satu anak
                            last->sibling = NULL;
                        } else {
                            // jika masih ada lebih dari satu anak
                            last->sibling = hapus->sibling;
                        }
                        delALLTree(hapus);  // menghapus simpul
                    } else {
                        // jika ditemukan pada simpul ini maka hentikan loop
                        break;
                    }
                }

                if(root->child->sibling != NULL) {
                    // jika masih ada simpul anak lain
                    simpul* hapus;
                    // loop menghapus simpul sisa yang tidak dilewati
                    while(root->child->sibling != last) {
                        hapus = root->child->sibling;
                        root->child->sibling = hapus->sibling;
                        delALLTree(hapus);
                    }
                    delALLTree(root->child->sibling);
                }
                root->child->sibling = NULL;    // reset sibling karena hanya memiliki satu anak
                pruning(root->child, option);   // lanjutkan pruning
            }
        }
    }
}

// FUNGSI MENGHITUNG JUMLAH VALUE PADA TREE SETELAH PRUNING
int sumValue(simpul* root) {
    if(root == NULL) {
        // jika simpul root kosong
        return 0;
    }

    // jika simpul root tidak kosong
    return root->kontainer.value + sumValue(root->child);
}

// PROSEDUR PRINT ELEMEN LIST PADA TREE
void printTreeList(simpul* root) {
    if(root != NULL) {
        // jika simpul root tidak kosong
        
        // print elemen_list
        printElemen(root->kontainer.list_tree, 0);

        simpul* bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki simpul anak
            if(bantu->sibling == NULL) {
                // jika memiliki satu simpul anak
                printTreeList(bantu);
            } else {
                // jika memiliki banyak simpul anak
                // mencetak simpul anak
                while(bantu->sibling != root->child) {
                    printTreeList(bantu);
                    bantu = bantu->sibling;
                }
                // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                printTreeList(bantu);
            }
        }
    }
}

// PROSEDUR MENCARI SPASI TERPANJANG PADA SETIAP LEVEL (BFS)
void BFS(list_space *L, simpul* root) {
    if(root != NULL) {
        // jika tree tidak kosong
        addSpace(0, L); // set 0 spasi pada root atau level pertama
        
        // deklarasi dan inisialisasi queue untuk membantu proses iterasi
        queue Q;
        createQueue(&Q);
        addQueue(root, &Q);
        
        int level = queueSize(Q);   // variabel untuk menyimpan jumlah simpul pada level saat ini

        // loop selama queue tidak kosong
        while(Q.first != NULL) {
            int i = 0;      // variabel iterasi
            int spasi = 0;  // variabel untuk sum spasi

            // loop mengecek simpul pada level yang sama
            while(i < level) {
                simpul* bantu = Q.first->node->child;   //  pointer untuk menyimpan simpul
                if(bantu != NULL) {
                    // jika simpul memiliki simpul anak
                    // loop menmasukan seluruh anak ke dalam queue
                    while(bantu->sibling != NULL && bantu->sibling != Q.first->node->child) {
                        addQueue(bantu, &Q);
                        bantu = bantu->sibling;
                    }
                    addQueue(bantu, &Q);    // memasukan anak terakhir / pertama jika hanya memiliki satu anak
                }

                // menghitung banyak seluruh karakter pada bagian nama simpul dan karakter tambahannya
                int count_root_name = strlen(Q.first->node->kontainer.root_name) + log10(Q.first->node->kontainer.value) + 4;
                if(spasi < count_root_name) {
                    // jika spasi kurang dari nilau count_root_name
                    spasi = count_root_name;
                }

                elemen_list* tunjuk = Q.first->node->kontainer.list_tree.first; // pointer untuk list pada simpul bantu
                // loop mengecek isi list
                while(tunjuk != NULL) {
                    if(spasi < strlen(tunjuk->kontainer.konsekuensi)+2) {
                        // jika spasi kurang dari panjang karakter pada list
                        spasi = strlen(tunjuk->kontainer.konsekuensi)+2;
                    }
                    tunjuk = tunjuk->next;
                }
                delQueue(&Q);   // delete elemen queue sebagai iterasi
                i++;    // iterasi loop
            }
            addSpace(spasi+(*L).tail->space, L);    // menambahkan nilai spasi pada masing masing level ke dalam list spasi
            level = queueSize(Q);                   // reset banyak simpul pada level
        }
        delSpace(L);    // menghapus spasi level terakhir karena tidak digunakan
    }
}

// --------------------------------BAGIAN QUEUE--------------------------------
// PROSEDUR INISIALISASI QUEUE
void createQueue(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// PROSEDUR ADD ELEMEN QUEUE
void addQueue(simpul* node, queue *Q) {
    // deklarasi elemen
    elemen_queue* baru = (elemen_queue*) malloc(sizeof(elemen_queue));

    baru->node = node;  // memasukan node ke dalam queue
    baru->next = NULL;

    if((*Q).first == NULL) {
        // jika queue kosong
        (*Q).first = baru;
    } else {
        // jika queue tidak kosong
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

// PROSEDUR DELETE ELEMEN QUEUE
void delQueue(queue *Q) {
    elemen_queue* hapus = (*Q).first;
    if((*Q).first == (*Q).last) {
        // jika hanya ada satu elemen dalma queue
        (*Q).first = NULL;
        (*Q).last = NULL;
    } else {
        // jika ada banyak elemen dalam queue
        (*Q).first = (*Q).first->next;
    }
    free(hapus);
}

// FUNGSI MENGHITUNG BANYAK ELEMEN PADA QUEUE
int queueSize(queue Q) {
    int ans = 0;    // variabel untuk penghitung
    if(Q.first == NULL) {
        // jika queue kosong
        return ans;
    }

    // loop menghitung banyak elemen
    elemen_queue* bantu = Q.first;
    while(bantu != NULL) {
        // proses
        bantu = bantu->next;
        ans++;
    }
    return ans;
}