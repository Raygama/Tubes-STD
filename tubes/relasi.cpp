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

bool cekAvailabilityDokter(List_relasi LR, address_dokter D, int jam, int durasi) {
    address_relasi R = first(LR);
    if (jam < info(D).jam_awal || jam > info(D).jam_akhir) {
        return false;
    }
    while (R != NULL) {
        if (dokter(R) == D) {
            if ((jam + durasi > info(R).jamAwal && jam + durasi < info(R).jamAkhir) || (jam < info(R).jamAwal && jam+durasi > info(R).jamAkhir)) {
                return false;
            }
        }
        R = next(R);
    }
    return true;
}

void cariDokter(List_dokter LD, List_pasien LP, List_relasi LR) {
    address_dokter D;
    string kode;
    cout << "Masukan kode dokter yang ingin dicari: ";
    cin >> kode;
    D = findElm(LD, kode);
    cout << "Data Dokter: " << endl;
    cout << info(D).kode << " " << info(D).nama << " " << info(D).spesialis << endl;

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

void showAllKunjungan(List_relasi L) {
    address_relasi P = first(L);
    string input;
    printf("-------------------------------------------------\n");
    printf("| DOKTER\t| PASIEN\t| JAM KUNJUNGAN\t|\n");
    printf("-------------------------------------------------\n");
    while(P !=NULL) {
        cout << "| " << info(dokter(P)).nama << "\t\t| " << info(pasien(P)).nama << "\t\t| " << info(P).jamAwal << " sd " << info(P).jamAkhir << "\t| " << endl;
        P = next(P);
    }
    printf("-------------------------------------------------\n");
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

void deleteDokter(List_dokter &LD, List_relasi &LR) {
    string kode = "", opsi = "";
    address_dokter D, temp;
    address_relasi R;
    int n = 0;

    cout << "Masukan kode dokter yang ingin dihapus: ";
    cin >> kode;
    D = findElm(LD, kode);
    if (D != NULL) {
        R = first(LR);
        while (R != NULL) {
            if (dokter(R) == D) {
                if (n == 0) {
                    cout << "Peringatan! Kunjungan dengan pasien berikut akan dibatalkan!" << endl;
                    cout << info(pasien(R)).nama << endl;
                    n++;
                } else {
                    cout << info(pasien(R)).nama << endl;
                    n++;
                }
            }
            R = next(R);
        }
        if (n == 0) {
            deleteElm(LD, D, temp);
            cout << "Delete dokter selesai" << endl;
        } else {
            cout << "Kunjungan dokter dengan " << n << " pasien akan terbatalkan" << endl;
            cout << "Lanjut? (y/n) ";
            cin >> opsi;
            if (opsi == "y") {
                deleteElm(LD, D, temp);
            }
        }
    } else {
        cout << "Data dokter tidak ditemukan" << endl;
        cout << "Ingin cari lagi (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            deleteDokter(LD, LR);
        }
    }
}

void jadwalKunjungan(List_relasi &LR, List_pasien &LP, List_dokter LD) {
    infotype_pasien xP;
    string kode;
    address_pasien p;
    address_dokter D;
    string opsi;
    bool availability;

    cout << "Masukan nama pasien: " << endl;
    cin >> xP.nama;
    p = findElm(LP, xP.nama);
    if (p == NULL) {
        cout << "Pasien belum terdaftar, silahkan daftar" << endl;
        cout << "Masukan umur: ";
        cin >> xP.umur;
        p = alokasi(xP);
        insertLast(LP, p);
        cout << "Pendaftaran berhasil" << endl;
    }

    cout << "Masukan kode dokter yang ingin dikunjungi: ";
    cin >> kode;
    D = findElm(LD, kode);
    while (D == NULL) {
        cout << "Tidak ada dokter dengan kode tersebut" << endl;
        cout << "Masukan kode dokter yang ingin dikunjungi: ";
        cin >> kode;
        D = findElm(LD, kode);
    }

    int jam;
    int durasi;
    time_t t = time(0);
    tm* now = localtime(&t);
    cout << "Kunjungan untuk jam " << now->tm_hour << " ganti? (y/n)" << endl;
    cin >> opsi;
    if (opsi == "y") {
        cout << "Masukan jam kunjungan: ";
        cin >> jam;
    }

    cout << "Masukan durasi jam kunjungan: ";
    cin >> durasi;

    availability = cekAvailabilityDokter(LR, D, jam, durasi);
    while (!availability) {
        cout << "Dokter tidak tersedia pada jam dan durasi tersebut, mohon input lagi" << endl;
        cout << "Kunjungan untuk jam " << now->tm_hour << " ganti? (y/n)" << endl;
        cin >> opsi;
        if (opsi == "y") {
            cout << "Masukan jam kunjungan: ";
            cin >> jam;
        }

        cout << "Masukan durasi jam kunjungan: ";
        cin >> durasi;

        availability = cekAvailabilityDokter(LR, D, jam, durasi);
    }

    address_relasi R = alokasi(D, p);
    info(R).jamAwal = jam;
    info(R).jamAkhir = jam + durasi;

    insertLast(LR, R);
}

void showKunjunganPasien(List_relasi LR, List_pasien LP) {
    string nama;
    bool found = false;
    address_pasien P;
    address_relasi R = first(LR);

    cout << "Masukan nama pasien: ";
    cin >> nama;
    P = findElm(LP, nama);

    if (P == NULL) {
        cout << "Nama pasien tidak ada" << endl;
    } else {
        while ( R != NULL && !found) {
            if (pasien(R) == P) {
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada kunjungan untuk pasien ini" << endl;
        } else {
            printf("=================LIST KUNJUNGAN PASIEN===================\n");
            printf("---------------------------------------------------------\n");
            printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
            printf("---------------------------------------------------------\n");
            R = first(LR);
            while ( R != NULL) {
                if (pasien(R) == P) {
                    cout << "| " << info(dokter(R)).kode << "\t| " <<  info(dokter(R)).nama << "\t\t| " <<  info(dokter(R)).spesialis << "\t\t|  " <<  info(dokter(R)).jam_awal << " s/d " <<  info(dokter(R)).jam_akhir << "\t| " << endl;
                }
                R = next(R);
            }
            printf("---------------------------------------------------------\n");
        }
    }
}

void showKunjunganDokter(List_relasi LR, List_dokter LD) {
    string kode;
    bool found = false;
    address_dokter D;
    address_relasi R = first(LR);

    cout << "Masukan kode dokter: ";
    cin >> kode;
    D = findElm(LD, kode);

    if (D == NULL) {
        cout << "Kode dokter tidak ada" << endl;
    } else {
        while (R != NULL && !found) {
            if (dokter(R) == D) {
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada kunjungan untuk dokter ini" << endl;
        } else {
            printf("======LIST KUNJUNGAN DOKTER======\n");
            printf("---------------------------------\n");
            printf("| ID\t| NAMA\t\t| UMUR\t|\n");
            printf("---------------------------------\n");
            R = first(LR);
            while ( R != NULL) {
                if (dokter(R) == D) {
                    cout << "| " << info(pasien(R)).id << "\t| " << info(pasien(R)).nama << "\t\t| " << info(pasien(R)).umur << "\t| " << endl;
                }
                R = next(R);
            }
            printf("---------------------------------\n");
        }
    }
}

void selesaiKunjungan(List_relasi LR, List_pasien &LP) {
    string nama;
    address_pasien P;

    cout << "Masukan nama pasien yang kunjungannya sudah selesai: ";
    cin >> nama;
    //P = findElm(LP, P);

}
