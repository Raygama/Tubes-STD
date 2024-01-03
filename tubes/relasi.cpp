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
    if ((jam < info(D).jam_awal || jam > info(D).jam_akhir) || (jam < info(D).jam_akhir && jam + durasi > info(D).jam_akhir)) {
        return false;
    }
    while (R != NULL) {
        if (dokter(R) == D) {
            /*if ((jam + durasi > info(R).jamAwal && jam + durasi < info(R).jamAkhir) || (jam > info(R).jamAwal && jam < info(R).jamAkhir)) {
                return false;
            }*/
            if ((info(R).jamAwal <= jam && jam < info(R).jamAkhir) || (info(R).jamAwal < jam + durasi && jam + durasi <= info(R).jamAkhir)) {
                return false;
            }
        }
        R = next(R);
    }
    return true;
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

void isiKunjungan(List_relasi &LR, List_dokter LD, List_pasien LP){
    address_dokter D;
    address_pasien P;
    address_relasi R;
    string kode, nama;
    int jamAwal, jamAkhir;

    D = findElm(LD, "RAY");
    P = findElm(LP, "Melin");
    R = alokasi(D, P);
    info(R).jamAwal = 9;
    info(R).jamAkhir = 10;
    insertLast(LR, R);

    D = findElm(LD, "ABY");
    P = findElm(LP, "Ray");
    R = alokasi(D, P);
    info(R).jamAwal = 13;
    info(R).jamAkhir = 15;
    insertLast(LR, R);

    D = findElm(LD, "HTS");
    P = findElm(LP, "Zah");
    R = alokasi(D, P);
    info(R).jamAwal = 13;
    info(R).jamAkhir = 15;
    insertLast(LR, R);

}

void showAllKunjungan(List_relasi L) {
    address_relasi P = first(L);
    int sum = 0;
    string input;
    printf("-------------------------------------------------\n");
    printf("| DOKTER\t| PASIEN\t| JAM KUNJUNGAN\t|\n");
    printf("-------------------------------------------------\n");
    while(P !=NULL) {
        sum++;
        cout << "| " << info(dokter(P)).nama << "\t\t| " << info(pasien(P)).nama << "\t\t| " << info(P).jamAwal << " sd " << info(P).jamAkhir << "\t| " << endl;
        P = next(P);
    }
    printf("-------------------------------------------------\n");
    cout << "Terdapat total " << sum << " kunjungan" << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    cin >> input;
}

void showKesibukanDokter(List_relasi LR, address_dokter D) {
    address_relasi R = first(LR);
    bool found = false;

    while (R != NULL && !found) {
        if (dokter(R) == D) {
            found = true;
        }
        R = next(R);
    }

    cout << endl;
    if (found) {
        printf("===============KESIBUKAN DOKTER==================\n");
        cout << "------------ JAM OPERASI: " << info(dokter(R)).jam_awal << " sd " << info(dokter(R)).jam_akhir << " --------------" << endl;
        printf("-------------------------------------------------\n");
        printf("| DOKTER\t| PASIEN\t| JAM KUNJUNGAN\t|\n");
        printf("-------------------------------------------------\n");
        R = first(LR);
        while (R != NULL) {
            if (dokter(R) == D) {
                cout << "| " << info(dokter(R)).nama << "\t\t| " << info(pasien(R)).nama << "\t\t| " << info(R).jamAwal << " sd " << info(R).jamAkhir << "\t| " << endl;
            }
            R = next(R);
        }
        printf("-------------------------------------------------\n");
    } else {
        printf("===============KESIBUKAN DOKTER==================\n");
        printf("==============TIDAK ADA KESIBUKAN================\n");
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


void deleteElm(List_relasi &L, address_relasi prec, address_relasi &p) {
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
                    cout << endl;
                    cout << "Peringatan! Kunjungan dengan pasien berikut akan dibatalkan!" << endl;
                    printf("=============LIST KUNJUNGAN DOKTER==============\n");
                    printf("------------------------------------------------\n");
                    printf("| ID\t| NAMA\t\t| UMUR\t| JAM KUNJUNGAN\t|\n");
                    printf("------------------------------------------------\n");
                    cout << "| " << info(pasien(R)).id << "\t| " << info(pasien(R)).nama << "\t\t| " << info(pasien(R)).umur << "\t| " << info(R).jamAwal << " sd " << info(R).jamAkhir << "\t| " << endl;
                    n++;
                } else {
                    cout << "| " << info(pasien(R)).id << "\t| " << info(pasien(R)).nama << "\t\t| " << info(pasien(R)).umur << "\t| " << info(R).jamAwal << " sd " << info(R).jamAkhir << "\t| " << endl;
                    printf("------------------------------------------------\n");
                    n++;
                }
            }
            R = next(R);
        }
        if (n == 0) {
            deleteElm(LD, D, temp);
            cout << "Delete dokter selesai" << endl;
        } else {
            cout << endl;
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
    bool availability = false;

    cout << "Masukan nama pasien: ";
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

    showKesibukanDokter(LR, D);
    cout << endl;

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

    cout << "Kunjungan berhasil dijadwalkan, tekan apapun untuk kembali" << endl;
    cin >> opsi;

    address_relasi R = alokasi(D, p);
    info(R).jamAwal = jam;
    info(R).jamAkhir = jam + durasi;

    insertLast(LR, R);
}

void showKunjunganPasien(List_relasi LR, List_pasien LP) {
    string nama, temp;
    int sum = 0;
    bool found = false;
    address_pasien P;
    address_relasi R = first(LR);

    cout << "Masukan nama pasien: ";
    cin >> nama;
    P = findElm(LP, nama);

    if (P == NULL) {
        cout << "Nama pasien tidak terdaftar" << endl;
        cout << "Tekan tombol apapun untuk kembali" << endl;
        cin >> temp;
    } else {
        while ( R != NULL && !found) {
            if (pasien(R) == P) {
                found = true;
            }
            R = next(R);
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
                    sum++;
                    cout << "| " << info(dokter(R)).kode << "\t| " <<  info(dokter(R)).nama << "\t\t| " <<  info(dokter(R)).spesialis << "\t\t|  " <<  info(dokter(R)).jam_awal << " s/d " <<  info(dokter(R)).jam_akhir << "\t| " << endl;
                }
                R = next(R);
            }
            printf("---------------------------------------------------------\n");
            cout << "Terdapat total " << sum << " kunjungan" << endl;
            cout << "Tekan tombol apapun untuk kembali" << endl;
            cin >> temp;
        }
    }
}

void showKunjunganDokter(List_relasi LR, List_dokter LD) {
    string kode;
    int sum = 0;
    bool found = false;
    address_dokter D;
    address_relasi R = first(LR);

    cout << "Masukan kode dokter: ";
    cin >> kode;
    D = findElm(LD, kode);

    if (D == NULL) {
        cout << "Kode dokter tidak ada" << endl;
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> kode;
    } else {
        while (R != NULL && !found) {
            if (dokter(R) == D) {
                found = true;
            }
            R = next(R);
        }
        if (!found) {
            cout << "Tidak ada kunjungan untuk dokter ini" << endl;
        } else {
            printf("=============LIST KUNJUNGAN DOKTER==============\n");
            printf("------------------------------------------------\n");
            printf("| ID\t| NAMA\t\t| UMUR\t| JAM KUNJUNGAN\t|\n");
            printf("------------------------------------------------\n");
            R = first(LR);
            while ( R != NULL) {
                if (dokter(R) == D) {
                    sum++;
                    cout << "| " << info(pasien(R)).id << "\t| " << info(pasien(R)).nama << "\t\t| " << info(pasien(R)).umur << "\t| " << info(R).jamAwal << " sd " << info(R).jamAkhir << "\t| " << endl;
                }
                R = next(R);
            }
            printf("-----------------------------------------------\n");
            cout << "Terdapat total " << sum << " kunjungan" << endl;
            cout << "Tekan apapun untuk kembali" << endl;
            cin >> kode;
        }
    }
}

void editKunjungan(List_relasi &LR, List_pasien LP, List_dokter LD) {
    string pasien, dokter, temp;
    bool found = false;
    address_pasien P;
    address_dokter D;
    address_relasi R, tempR;
    int jam, durasi, opsi, pilih;

    cout << "Masukan nama pasien yang kunjungannya ingin diganti: ";
    cin >> pasien;
    cout << endl;

    P = findElm(LP, pasien);
    while (P == NULL) {
        cout << "Tidak ada pasien dengan nama tersebut" << endl;
        cout << "Mohon masukan nama pasien lagi: ";
        cin >> pasien;
        cout << endl;
        P = findElm(LP, pasien);
    }

    R = first(LR);
    while (R != NULL && !found) {
        if (pasien(R) == P) {
            found = true;
        }
        R = next(R);
    }

     if (found) {
        cout << "Masukan kode dokter dari pasien: ";
        cin >> dokter;
        D = findElm(LD, dokter);
        while (D == NULL) {
            cout << "Tidak ada dokter dengan kode tersebut, mohon input lagi: ";
            cin >> dokter;
            cout << endl;
            D = findElm(LD, dokter);
        }

        R = findElm(LR, D, P);
        if (R == NULL) {
            cout << "Tidak terdapat kunjungan pasien " << info(P).nama << " dengan dokter " << info(D).nama << endl;
            cout << "1. Cari Lagi" << endl;
            cout << "2. Cancel" << endl;
            cout << "Pilihan: ";
            cin >> pilih;
            cout << endl;
            if (pilih == 1) {
                editKunjungan(LR, LP, LD);
            }
        } else {
            do {
                cout << "Silahkan pilih opsi perubahan kunjungan" << endl;
                cout << "1. Ubah dokter" << endl;
                cout << "2. Ubah jam kunjungan" << endl;
                cout << "3. Confirm" << endl;
                cout << "Pilihan: ";
                cin >> opsi;
                if (opsi == 1) {
                    deleteElm(LR, R, tempR);

                    cout << "Masukan dokter baru: ";
                    cin >> dokter;
                    D = findElm(LD, dokter);
                    while (D == NULL) {
                        cout << "Tidak ada dokter dengan kode tersebut, mohon input lagi: ";
                        cin >> dokter;
                        cout << endl;
                        D = findElm(LD, dokter);
                    }

                    showKesibukanDokter(LR, D);
                    cout << endl;

                    dokter(tempR) = D;
                    cout << "Masukan jam kunjungan baru: ";
                    cin >> jam;
                    cout << endl;

                    cout << "Masukan durasi kunjungan baru: ";
                    cin >> durasi;
                    cout << endl;

                    if (!cekAvailabilityDokter(LR, D, jam, durasi)) {
                        cout << "Terdapat konflik dengan jadwal kunjungan lain pada jam dan durasi tersebut" << endl;
                        cout << "1. Ulangi" << endl;
                        cout << "2. Cancel" << endl;
                        cout << "Pilihan: ";
                        cin >> pilih;
                        cout << endl;
                        if (pilih == 2) {
                            insertLast(LR, tempR);
                            cout << "Penggantian kunjungan dibatalkan" << endl;
                            cout << "Tekan tombol apapun untuk kembali" << endl;
                            cin >> temp;
                        } else if (pilih == 1) {
                            editKunjungan(LR, LP, LD);
                        }
                    } else {
                        info(tempR).jamAwal = jam;
                        info(tempR).jamAkhir = jam + durasi;
                        insertLast(LR, tempR);
                        cout << "Kunjungan berhasil diganti" << endl;
                        cout << "Tekan tombol apapun untuk kembali" << endl;
                        cin >> temp;
                    }
                } else if (opsi == 2) {
                    deleteElm(LR, R, tempR);
                    cout << "Masukan jam kunjungan baru: ";
                    cin >> jam;
                    cout << endl;

                    cout << "Masukan durasi kunjungan baru: ";
                    cin >> durasi;
                    cout << endl;

                    if (!cekAvailabilityDokter(LR, D, jam, durasi)) {
                        cout << "Terdapat konflik dengan jadwal kunjungan lain pada jam dan durasi tersebut" << endl;
                        cout << "1. Ulangi" << endl;
                        cout << "2. Cancel" << endl;
                        cout << "Pilihan: ";
                        cin >> pilih;
                        cout << endl;
                        if (pilih == 2) {
                            insertLast(LR, tempR);
                            cout << "Penggantian kunjungan dibatalkan" << endl;
                            cout << "Tekan tombol apapun untuk kembali" << endl;
                            cin >> temp;
                        } else if (pilih == 1) {
                            editKunjungan(LR, LP, LD);
                        }
                    } else {
                        info(tempR).jamAwal = jam;
                        info(tempR).jamAkhir = jam + durasi;
                        insertLast(LR, tempR);
                        cout << "Kunjungan berhasil diganti" << endl;
                        cout << "Tekan tombol apapun untuk kembali" << endl;
                        cin >> temp;
                    }
                }
            } while (1 <= opsi && opsi <= 2);
        }
    } else {
        cout << "Tidak ada kunjungan dengan dokter yang terjadwal" << endl;
        cout << "Tekan tombol apapun untuk kembali" << endl;
        cin >> temp;
    }

}

void batalKunjungan(List_relasi &LR, List_pasien LP, List_dokter LD) {
    string pasien, dokter, opsi;
    int pilih;
    address_pasien P, tempP;
    address_dokter D;
    address_relasi R, tempR;
    bool found = false;

    cout << "Masukan nama pasien yang kunjungannya ingin dibatalkan: ";
    cin >> pasien;
    cout << endl;
    P = findElm(LP, pasien);
    while (P == NULL) {
        cout << "Tidak ada pasien dengan nama tersebut" << endl;
        cout << "Mohon masukan nama pasien lagi: ";
        cin >> pasien;
        P = findElm(LP, pasien);
    }

    R = first(LR);
    while (R != NULL && !found) {
        if (pasien(R) == P) {
            found = true;
        }
        R = next(R);
    }

    if (found) {
        cout << "Masukan kode dokter dari pasien: ";
        cin >> dokter;
        D = findElm(LD, dokter);
        while (D == NULL) {
            cout << "Tidak ada dokter dengan kode tersebut, mohon input lagi: ";
            cin >> dokter;
            cout << endl;
            D = findElm(LD, dokter);
        }
        R = findElm(LR, D, P);
        if (R == NULL) {
            cout << "Tidak terdapat kunjungan pasien " << info(P).nama << " dengan dokter " << info(D).nama << endl;
            cout << "1. Cari Lagi" << endl;
            cout << "2. Cancel" << endl;
            cout << "Pilihan: ";
            cin >> pilih;
            cout << endl;
            if (pilih == 1) {
                batalKunjungan(LR, LP, LD);
            }
        } else {
            deleteElm(LR, R, tempR);
            cout << "Kunjungan pasien " << info(P).nama << " dengan dokter " << info(D).nama << " telah dibatalkan." << endl;
            cout << "Tekan apapun untuk kembali" << endl;
            cin >> opsi;
        }
    } else {
        cout << "Tidak ada kunjungan dengan dokter yang terjadwal" << endl;
        cout << "Tekan tombol apapun untuk kembali" << endl;
        cin >> opsi;
    }
}

void selesaiKunjungan(List_relasi &LR, List_pasien &LP, List_dokter LD) {
    string pasien, dokter, opsi;
    int pilih;
    address_pasien P, tempP;
    address_dokter D;
    address_relasi R, tempR;
    bool found = false;

    cout << "Masukan nama pasien yang kunjungannya sudah selesai: ";
    cin >> pasien;
    cout << endl;

    P = findElm(LP, pasien);
    while (P == NULL) {
        cout << "Tidak ada pasien dengan nama tersebut" << endl;
        cout << "Mohon masukan nama pasien lagi: ";
        cin >> pasien;
        cout << endl;
        P = findElm(LP, pasien);
    }

    R = first(LR);
    while (R != NULL && !found) {
        if (pasien(R) == P) {
            found = true;
        }
        R = next(R);
    }

    if (found) {
        cout << "Masukan kode dokter dari pasien: ";
        cin >> dokter;
        D = findElm(LD, dokter);
        while (D == NULL) {
            cout << "Tidak ada dokter dengan kode tersebut, mohon input lagi: ";
            cin >> dokter;
            cout << endl;
            D = findElm(LD, dokter);
        }
        R = findElm(LR, D, P);
        if (R == NULL) {
            cout << "Tidak terdapat kunjungan pasien " << info(P).nama << " dengan dokter " << info(D).nama << endl;
            cout << "1. Cari Lagi" << endl;
            cout << "2. Cancel Delete" << endl;
            cout << "Pilihan: ";
            cin >> pilih;
            cout << endl;
            if (pilih == 1) {
                selesaiKunjungan(LR, LP, LD);
            }
        } else {
            deleteElm(LR, R, tempR);
            cout << "Kunjungan pasien " << info(P).nama << " dengan dokter " << info(D).nama << " telah selesai." << endl;
            cout << "Tekan apapun untuk kembali" << endl;
            cin >> opsi;
        }
    } else {
        cout << "Tidak ada kunjungan dengan dokter yang terjadwal" << endl;
        cout << "Ingin menyelesaikan kunjungan? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            deleteElm(LP, P, tempP);
            cout << "Terima kasih atas kunjungannya, " << info(tempP).nama << endl;
            cout << "Tekan tombol apapun untuk kembali" << endl;
            cin >> opsi;
        }
    }
}

void sortKunjungan(List_relasi &L) {
    int pilih;
    address_relasi P, Q;
    string opsi;
    infotype_relasi temp;


    cout << "Silahkan masukan kategori sorting: " << endl;
    cout << "1. Jam Awal Kunjungan" << endl;
    cout << "2. Jam Akhir Kunjungan" << endl;
    cout << "Pilihan: ";
    cin >> pilih;
    if (pilih == 1) {
        P = first(L);
        while (P != NULL) {
            Q = P;
            while (Q != NULL) {
                if (info(Q).jamAwal < info(P).jamAwal) {
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
                if (info(Q).jamAkhir < info(P).jamAkhir) {
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

