#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#define info_parent(P) P->info_parent
#define next_parent(P) P->next_parent
#define prev(P) P->prev
#define first(L) L.first
#include <iostream>

using namespace std;

typedef infotype {
    int ID;
    string nama, sma;
    string jalur_masuk;
    string jurusan_sma;
    int sumbangan;

}
typedef struct *elmList address;
struct elmList{
    infotype info_parent;
    address next_parent;
    address prev;
};

struct List{
    address first;
};

void createList_parent(List &L);
void newElement_parent(address &P, int id_baru, string nama_mhs, string asal_sekolah, string major, int donasi);
void insertFirst_parent(List &L, address P);
void insertAfter_parent(address Prec, address P);
void insertLast_parent(List &L, address P);
void deleteFirst_parent(List &L, address P);
void deleteAfter_parent(List &L, address Prec, address P);
void deleteLast_parent(List &L, address P);
void printList_parent(List &L);
address searchbyID_parent(List &L, int id_search);

#endif // LIST_PARENT_H_INCLUDED
