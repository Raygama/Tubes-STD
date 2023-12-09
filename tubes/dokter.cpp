#include "dokter.h"

void createList(List_dokter &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_dokter alokasi(infotype_dokter x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_dokter P;
    P = new elmlist_dokter;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_dokter &L, address_dokter P) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_dokter L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_dokter Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_dokter &L, address_dokter P) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List_dokter L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_dokter Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void printInfo(List_dokter L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_dokter P = first(L);
    if(first(L)!=NULL) {
        do {
            cout << info(P).id << " " << info(P).nama << " " << info(P).spesialis << endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_dokter findElm(List_dokter L, string id) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_dokter P = first(L);
    do {
        if(info(P).id == id) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
