#include "relasi.h"
#include "pasien.h"
#include "dokter.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_dokter D, address_pasien P) {
    address_relasi Q = new elmlist_relasi;
    pasien(Q) = P;
    dokter(Q) = D;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_relasi &L, address_relasi P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(dokter(P)).nama<<"->"<<info(pasien(P)).nama<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_dokter D, address_pasien P) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(dokter(Q)==D && pasien(Q)== P) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}
