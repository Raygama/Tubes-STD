#include "pasien.h"

void createList(List_pasien &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_pasien alokasi(infotype_pasien x) {
    address_pasien P = new elmlist_pasien;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_pasien &L, address_pasien P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_pasien &L, address_pasien P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void printInfo(List_pasien L) {
    address_pasien P = first(L);
    while(P !=NULL) {
        cout<<"->" << info(P).kode << " " << info(P).nama << " " << info(P).umur <<endl;
        P = next(P);
    }
}


address_pasien findElm(List_pasien L, string kode) {
    address_pasien P = first(L);
    while(P != NULL) {
        if(info(P).kode == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_pasien &Prec, address_pasien P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
