#include "dokter.h"

void createList(List_dokter &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_dokter alokasi(infotype_dokter x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    x.status = false;
    address_dokter P;
    P = new elmlist_dokter;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_dokter &L, address_dokter P) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_dokter L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_dokter &L, address_dokter P) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List_dokter L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void isiDokter(List_dokter &L) {
    int n, i;
    infotype_dokter xD;
    address_dokter D;
    cout << "Jumlah data yang ditambahkan: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> xD.kode >> xD.nama >> xD.spesialis;
        D = alokasi(xD);
        insertLast(L, D);
    }
}


void printInfo(List_dokter L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_dokter P = first(L);
    if(first(L)!=NULL) {
        do {
            cout << info(P).kode << " " << info(P).nama << " " << info(P).spesialis << " " << info(P).status << endl;
            P = next(P);
        } while((P)!=NULL);
    }
}

void showSpecialist(List_dokter L, string spesialis) {
    address_dokter P = first(L);
    if(first(L)!=NULL) {
        do {
            if (info(P).spesialis == spesialis) {
                cout << info(P).kode << " " << info(P).nama << " " << info(P).spesialis << " " << info(P).status << endl;
            }
            P = next(P);
        } while((P)!=NULL);
    }
}

address_dokter findElm(List_dokter L, string kode) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_dokter P = first(L);
    do {
        if(info(P).kode == kode) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void deleteElm(List_dokter &L, address_dokter prec, address_dokter &p) {
    if (prec == first(L)) {
        p = prec;
        first(L) = next(p);
        prev(first(L)) = NULL;
        next(p) = NULL;
    } else if (prec == last(L)) {
        p = prec;
        last(L) = prev(p);
        next(last(L)) = NULL;
        prev(p) = NULL;
    } else {
        address_dokter Q;
        p = prec;
        Q = prev(prec);
        next(Q) = next(p);
        prev(next(Q)) = Q;
        next(p) = NULL;
        prev(p) = NULL;
    }
}
