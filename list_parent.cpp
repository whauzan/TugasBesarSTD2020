#include "list_parent.h"
#include <iostream>

using namespace std;

void createList_parent(List &L){
    first(L)=NULL;
}

void newElement_parent(address &P, int id_baru, string nama_mhs, string asal_sekolah, string major, int donasi){
    address P;
    P = new elmList;
    info_parent(P).ID = id_baru;
    info_parent(P).nama = nama_mhs;
    info_parent(P).sma = asal_sekolah;
    info_parent(P).jurusan_sma = major;
    info_parent(P).sumbangan = donasi;
    prev(P)=NULL;
    next_parent(P)=NULL;
}

void insertFirst_parent(List &L, address P){
    if (next_parent(first(L))!=prev(first(L))) {
        next_parent(P)=first(L);
        prev(P)=prev(first(L));
        next_parent(prev(first(L)))=P;
        prev(first(L))=P;
        first(L)=P
    } else {
        first(L)=P;
        prev(P)=P;
        next_parent(P)=P;
    }
}

void insertAfter_parent(address Prec, address P){
    prev(next_parent(Prec))=P;
    next_parent(P)=next_parent(Prec);
    next_parent(Prec)=P;
    prev(P)=Prec;
}

void insertLast_parent(List &L, address P){
    address Prec;
    Prec=first(L);
    if (first(L)==NULL){
        insertFirst_parent(L, P);
    } else {
        while(Prec(next_parent)!=prev(first(L))){
            Prec=next(Prec);
        }
        insertAfter_parent(Prec, P);
    }
}

void deleteFirst_parent(List &L, address P){
    P=first(L);
    if(next_parent(P)=prev(P)) {
        first(L)=P;
    } else {
        next_parent(prev(first(L)))=next_parent(P);
        first(L)=next_parent(P);
        next_parent(prev(first(L)))=first(L);
    }
}

void deleteAfter_parent(List &L, address Prec, address P){
    P=next_parent(Prec);
    next_parent(Prec)=next_parent(P);
    prev(next_parent(Prec))=Prec;

}

void deleteLast_parent(List &L, address P){
    P=first(L);
    if(next_parent(P)==P){
        deleteFirst_parent(L, P);
    } else{
        deleteAfter_parent((prev(prev(P))), Prec, P);
    }
}

void printList_parent(List &L){
    address P;
    P=first(L);
    while (next_parent(P)!=prev(P)){
        cout<<info_parent(P)<<endl;
        P=next_parent(P);
    }
}

address searchbyID_parent(List &L, int id_search){
    address P;
    P=first(L);
    while(next_parent(P)!=prev(P)){
        if(info_parent(P).ID==id_search){
            return P;
        }
        P=next_parent(P);
    }
}
