#include "pasien.h"

void createList(List_pasien &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_pasien alokasi(infotype_pasien x) {
    address_pasien P = new elmlist_pasien;
    x.id = 0;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}


void tambahPasien(List_pasien &L) {
    int n, i;
    infotype_pasien xP;
    address_pasien P, Q;
    cout << "Jumlah data pasien yang ditambahkan: ";
    cin >> n;
    cout << "Masukan data pasien: Nama dan Umur" << endl;
    for (i = 1; i <= n; i++) {
        cin >> xP.nama >> xP.umur;
        Q = findElm(L, xP.nama);
        if (Q == NULL) {
            P = alokasi(xP);
            insertLast(L, P);
        } else {
            while (Q != NULL) {
                cout << "Terdapat pasien dengan nama yang sama persis, mohon input ulang nama dan umur" << endl;
                cin >> xP.nama >> xP.umur;
                Q = findElm(L, xP.nama);
            }
            P = alokasi(xP);
            insertLast(L, P);
        }
    }
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
        info(P).id = 1;
        last(L) = P;
        first(L) = P;
    } else {
        info(P).id = info(last(L)).id + 1;
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void isiPasien(List_pasien &L) {
    infotype_pasien xP;
    address_pasien P;

    xP.id = 1;
    xP.nama = "Melin";
    xP.umur = 14;
    P = alokasi(xP);
    insertLast(L, P);

    xP.id = 2;
    xP.nama = "Ray";
    xP.umur = 16;
    P = alokasi(xP);
    insertLast(L, P);

    xP.id = 3;
    xP.nama = "Abi";
    xP.umur = 15;
    P = alokasi(xP);
    insertLast(L, P);

    xP.id = 4;
    xP.nama = "Zah";
    xP.umur = 17;
    P = alokasi(xP);
    insertLast(L, P);
}

void printInfo(List_pasien L) {
    string input;
    address_pasien P = first(L);
    printf("---------------------------------\n");
    printf("| ID\t| NAMA\t\t| UMUR\t|\n");
    printf("---------------------------------\n");
    if(first(L)!=NULL) {
        do {
            cout << "| " << info(P).id << "\t| " << info(P).nama << "\t\t| " << info(P).umur << "\t| " << endl;
            P = next(P);
        } while((P)!=NULL);
    }
    printf("---------------------------------\n");
    cout << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    cin >> input;
}


address_pasien findElm(List_pasien L, string nama) {
    address_pasien P = first(L);
    while(P != NULL) {
        if(info(P).nama == nama) {
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

void deleteElm(List_pasien &L, address_pasien prec, address_pasien &p) {
    if (first(L) == last(L)) {
        p = prec;
        first(L) = NULL;
        last(L) = NULL;
    }else if (prec == first(L)) {
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
        address_pasien Q;
        p = prec;
        Q = prev(prec);
        next(Q) = next(p);
        prev(next(Q)) = Q;
        next(p) = NULL;
        prev(p) = NULL;
    }
}

int countPasien(List_pasien L) {
    address_pasien p;

    int i = 0;

    p = first(L);
    while (p != NULL) {
        i++;
        p = next(p);
    }

    return i;
}

void cariDataPasien(List_pasien L) {
    string nama, opsi;
    address_pasien P;
    bool found;
    cout << "Masukan nama pasien: ";
    cin >> nama;

    P = findElm(L, nama);
    if (P == NULL) {
        cout << "Nama pasien tidak ditemukan" << endl;
        cout << "Cari lagi? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            cariDataPasien(L);
        }
    } else {
        printf("---------------------------------\n");
        printf("| ID\t| NAMA\t\t| UMUR\t|\n");
        printf("---------------------------------\n");
        cout << "| " << info(P).id << "\t| " << info(P).nama << "\t\t| " << info(P).umur << "\t| " << endl;
        printf("---------------------------------\n");
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> opsi;
    }
}

void sortPasien(List_pasien &L) {
    int pilih;
    address_pasien P, Q;
    string opsi;
    infotype_pasien temp;


    cout << "Silahkan masukan kategori sorting: " << endl;
    cout << "1. Nama" << endl;
    cout << "2. Umur" << endl;
    cout << "Pilihan: ";
    cin >> pilih;
    if (pilih == 1) {
        P = first(L);
        while (P != NULL) {
            Q = P;
            while (Q != NULL) {
                if (info(Q).nama < info(P).nama) {
                    temp = info(P);
                    info(P) = info(Q);
                    info(Q) = temp;
                }
                Q = next(Q);
            }
            P = next(P);
        }
        cout << "Sorting selesai" << endl;
        cout << "Tekan tombol apapun untuk kembali" << endl;
        cin >> opsi;
    } else if (pilih == 2) {
        P = first(L);
        while (P != NULL) {
            Q = P;
            while (Q != NULL) {
                if (info(Q).umur < info(P).umur) {
                    temp = info(P);
                    info(P) = info(Q);
                    info(Q) = temp;
                }
                Q = next(Q);
            }
            P = next(P);
        }
        cout << "Sorting selesai" << endl;
        cout << "Tekan tombol apapun untuk kembali" << endl;
        cin >> opsi;
    }
}
