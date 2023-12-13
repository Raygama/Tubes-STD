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

bool cekAvailabilityDokter(address_dokter D) {
    return !info(D).status;
}

void cariDokter(List_dokter LD, List_pasien LP, List_relasi LR) {
    address_dokter D;
    string kode;
    cout << "Masukan kode dokter yang ingin dicari: ";
    cin >> kode;
    D = findElm(LD, kode);
    cout << "Data Dokter: " << endl;
    cout << info(D).kode << " " << info(D).nama << " " << info(D).spesialis << " " << info(D).status << endl;

    cout << endl;
    cout << "Data Pasien: " << endl;
    address_relasi P = first(LR);
    while(P !=NULL) {
        if (dokter(P) == D) {
            cout << info(pasien(P)).id << " " << info(pasien(P)).nama << " " << info(pasien(P)).umur << info(pasien(P)).status << endl;
        }
        P = next(P);
    }

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

void deleteElm(List_relasi &L, address_relasi prec, address_relasi &p) {
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
        address_relasi Q;
        p = prec;
        Q = prev(prec);
        next(Q) = next(p);
        prev(next(Q)) = Q;
        next(p) = NULL;
        prev(p) = NULL;
    }
}
