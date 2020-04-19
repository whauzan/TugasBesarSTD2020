#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#define info_parent(P) P->info
#define next_parent(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#include <iostream>

using namespace std;

typedef infotype {
    int tahun_masuk;
    int ID;
    string nama, sma, kota;
    string jalur_masuk;
    string jurusan;
    int sumbangan;

}
typedef struct *elmList address;
struct elmList {
    infotype info_parent;
    address next_parent;
    address prev;
}

struct List{
    address first;
}

void createList_parent(List &L);
void newElement_parent(infotype x);
void insertFirst_parent(List &L, address P);
void insertAfter_parent(address Prec, address P);
void insertLast_parent(List &L, address P);
void deleteFirst_parent(List &L, address P);
void deleteAfter_parent(List &L, address Prec, address P);
void deleteLast_parent(List &L, address P);
void printList_parent(List &L);
address searchbyID_parent(List &L, int nim_siswa);

#endif // LIST_PARENT_H_INCLUDED
