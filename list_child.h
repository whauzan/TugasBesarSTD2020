#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>
#define next(P) P->next
#define info(P) P->info
#define last(L) L.last
#define first(L) L.first

using namespace std;

typedef string infotype;
typedef struct elmList *address;


struct elmList {
    infotype info;
    address next;
};

struct List{
    address first;
    address last;
};

void newElement_child(infotype x);
void create_List_child();
void insertFirst_child(List &L, address P);
void insertAfter_child(List &L, address Prec, address P);
void insertLast_child(List &L, address P);
void deleteFirst_child(List &L, address P);
void deleteAfter_child(List &L, address Prec, address P);
void deleteLast_child(List &L, address P);
void printList_child(List L);
address findbyID_child(List L, string x);

#endif // LIST_CHILD_H_INCLUDED
