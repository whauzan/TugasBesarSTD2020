#include "list_child.h"
#define next(P) P->next
#define info(P) P->info
#define last(L) L.last
#define first(L) L.first
#include <iostream>

using namespace std;

void newElement_child(infotype x){
    address P;
    P=new elmList;
    info(P)=x;
    next(P)=NULL;
}
void create_List_child(List &L) {
    first(L)=NULL;
    last(L)=NULL;
}

void insertFirst_child(List &L, address P){
    P=new elmList;
    if (first(L)!=last(L)){
        next(P)=first(L);
        first(L)=P;
    }
}

void insertAfter_child(List &L, address Prec, address P){
    if (Prec!=NULL){
        if(Prec==NULL){
            next(P)=first(L);
            first(L)=P;
            last(L)=first(L);
        } else if(next(Prec)!=NULL){
            next(P)=next(Prec);
            next(Prec)=P;
        } else {
            next(last(L))=P;
            last(L)=P;
        }
    }
}

void insertLast_child(List &L, address P, address Prec){
    if (first(L)==NULL) {
        next(P)=first(L);
        first(L)=P;
        last(L)=P;
    } else {
        next(last(L))=P;
        last(L)=P;
    }
}

void deleteFirst_child(List &L, address P){
    P=first(L);
    if (P==last(L)) {
        first(L)=NULL;
        last(L)=NULL;
    } else {
        first(L)=next(P);
    }
}

void deleteAfter_child(List &L, address Prec, address P){
    P=next(Prec);
    if (next(P)!=NULL) {
        next(Prec)=next(P);
    } else {
        next(Prec)=NULL;
    }
}

void deleteLast_child(List &L, address P) {
    address Prec;
    P=last(L);
    if (first(L)==P){
        first(L)=NULL;
        last(L)=NULL;
    } else {
        Prec=first(L);
        while (next(Prec)!=last(L)) {
            Prec=next(Prec);
        }
        last(L)=Prec;
        next(Prec)=NULL;
    }
}

void printList_child(List L){
    address P;
    P=first(L);
    if (P!=last(L)){
        cout<<info(P);
        P=next(P);
    }
}

address findbyID_child(List L, string x){
    address P;
    P=first(L);
    while(P!=last(L)){
        if(info(P)!=x){
            P=next(P);
        }
    }
    return P;
}