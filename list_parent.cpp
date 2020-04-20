#include "list_parent.h"

void createList_parent(List_parent &LP){
    first_parent(L) = NULL;
}

address_parent newElement_parent(parent x){
    address_parent P = new elmList;
    info_parent(P) = x
    prev_parent(P) = NULL;
    next_parent(P) = NULL;
}

void deallocate_parent(address_parent &P){
    delete P;
}

void insertFirst_parent(List_parent &LP, address_parent P){
    if (next_parent(first_parent(LP)) != prev_parent(first_parent(LP))) { //kenapa kondisinya ribet amat si :3 cek yang di bawah coba
        next_parent(P) = first_parent(LP);
        prev_parent(P) = prev_parent(first_parent(LP));
        next_parent(prev_parent(first_parent(LP))) = P;
        prev_parent(first_parent(LP)) = P;
        first_parent(L) = P;
    } else {
        first_parent(LP) = P;
        prev_parent(P) = P;
        next_parent(P) = P;
    }
/*  if(first_parent(LP) == NULL){
    first_parent(LP) = P;
    next_parent(LP) = P;
    prev_parent(LP) = P;
  } else {
    next_parent(P) = first_parent(LP);
    prev_parent(P) = prev_parent(first_parent(LP));
    next_parent(prev_parent(first_parent(LP))) = P;
    prev_parent(first_parent(LP)) = P;
    first_parent(LP) = P;
  } */
}

void insertAfter_parent(List_parent &LP, address_parent Prec, address_parent P){
    prev_parent(next_parent(Prec)) = P;
    next_parent(P) = next_parent(Prec);
    next_parent(Prec) = P;
    prev_parent(P) = Prec;
}

void insertLast_parent(List_parent &LP, address P){ //cek kodingan di bawah coba
    address Prec;
    Prec = first_parent(LP);
    if (first_parent(LP) == NULL){
        insertFirst_parent(LP, P);
    } else {
        while(Prec != prev_parent(first_parent(LP))){
            Prec = next(Prec);
        }
        insertAfter_parent(LP, Prec, P);
    }
    /*if(first_parent(LP) == NULL){
        insertFirst_parent(LP, P);
    } else {
        next_parent(P) = first_parent(LP);
        prev_parent(P) = prev_parent(first_parent(LP));
        next_parent(prev_parent(first_parent(LP))) = P;
        prev_parent(first_parent(LP)) = P;
    }*/
}

void deleteFirst_parent(List_parent &LP, address_parent &P){
    P = first_parent(LP);
    if(next_parent(P) == first_parent(LP)) {
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
        first_parent(LP) = NULL;
    } else {
        first_parent(LP) = next_parent(P);
        prev_parent(first_parent(LP)) = prev_parent(P);
        next_parent(prev_parent(P)) = first_parent(LP);
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void deleteAfter_parent(List_parent &LP, address_parent Prec, address_parent &P){
    if(Prec != NULL){
        P = next_parent(Prec);
        next_parent(Prec) = next_parent(P);
        prev_parent(next_parent(Prec)) = Prec;
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void deleteLast_parent(List_parent &LP, address_parent &P){
    P = prev_parent(first_parent(LP));
    if(P == first_parent(LP)){
        deleteFirst_parent(LP, P);
    } else{
        prev_parent(first_parent(LP)) = prev_parent(P);
        next_parent(prev_parent(P)) = first_parent(LP);
        next_parent(P) = NULL;
        prev_parent(P) = NULL;
    }
}

void printList_parent(List_parent LP){
    address_parent P;
    if(first_parent(LP) == NULL){
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t Daftar Mahasiswa Baru"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t Belum ada Mahasiswa yang terdaftar \n"<<endl;
    } else {
        cout<<"============================================================================================================================================"<<endl;
        cout<<"\t\t\t\t\t\t\t\t Daftar Mahasiswa Baru"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        cout<<"ID \t| Nama \t\t\t| Asal SMA \t\t| Jurusan SMA \t| Jenis Kelamin \t| Jalur Masuk \t| Sumbangan"<<endl;
        cout<<"============================================================================================================================================"<<endl;
        P = first_parent(LP);
        do{
            cout<<info_parent(P).ID<<"\t| "<<info_parent(P).nama<<"\t| ";
            cout<<info_parent(P).sma<<"\t| "<<info_parent(P).jurusan_sma<<"\t\t| ";
            cout<<info_parent(P).jenis_kelamin<<"\t\t\t| "<<info_parent(P).jalur_masuk<<"\t\t| Rp"<<info_parent(P).sumbangan;
            cout<<endl;
            P = next_parent(P);
        }while(next_parent(P) != first_parent(P));
    }
}

address searchbyID_parent(List_parent LP, int id_search){
    address_parent P;
    bool found;
    if(first_parent(LP) != NULL){
        found = false;
        P = first_parent(LP);
        do{
            if(info_parent(P).ID == id_search){
                found = true;
            } else {
                P = next_parent(P);
            }
        }while(found != true &&next_parent(P) != first_parent(LP));
    }
    if(found != true){
        P = NULL;
    }
    return P;
}

address_parent searchbyName(List_parent LP, string nama_search){
    bool found;
    address_parent P;
    if(first_parent(LP) != NULL){
        found = false;
        P = first_parent(LP);
        do{
            if(info_parent(P).nama == nama_search){
                found = true;
            } else {
                P = next_parent(P);
            }
        }while(found != true && next_parent(P) != first_parent(LP));
    }
    if(found != true){
        P = NULL;
    }
    return P;
}
