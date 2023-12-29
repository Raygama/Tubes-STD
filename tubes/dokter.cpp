#include "dokter.h"
#include "pasien.h"

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
    infotype_dokter xD;
    address_dokter D;

    xD.kode = "RAY";
    xD.nama = "Daffa";
    xD.spesialis = "Kulit";
    xD.jam_awal = 8;
    xD.jam_akhir = 12;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "MLN";
    xD.nama = "Melin";
    xD.spesialis = "Mata";
    xD.jam_awal = 10;
    xD.jam_akhir = 14;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "ABY";
    xD.nama = "Abiyu";
    xD.spesialis = "THT";
    xD.jam_awal = 12;
    xD.jam_akhir = 16;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "HTS";
    xD.nama = "Haris";
    xD.spesialis = "Dalam";
    xD.jam_awal = 18;
    xD.jam_akhir = 22;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "ADK";
    xD.nama = "Dika";
    xD.spesialis = "Anak";
    xD.jam_awal = 14;
    xD.jam_akhir = 18;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "ANA";
    xD.nama = "Ana";
    xD.spesialis = "Dalam";
    xD.jam_awal = 8;
    xD.jam_akhir = 12;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "BAY";
    xD.nama = "Bayu";
    xD.spesialis = "Anak";
    xD.jam_awal = 10;
    xD.jam_akhir = 14;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "CIN";
    xD.nama = "Cinta";
    xD.spesialis = "Mata";
    xD.jam_awal = 12;
    xD.jam_akhir = 16;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "DAN";
    xD.nama = "Dana";
    xD.spesialis = "Kulit";
    xD.jam_awal = 14;
    xD.jam_akhir = 18;
    D = alokasi(xD);
    insertLast(L, D);

    xD.kode = "RAT";
    xD.nama = "Ratna";
    xD.spesialis = "THT";
    xD.jam_awal = 16;
    xD.jam_akhir = 20;
    D = alokasi(xD);
    insertLast(L, D);
}


void printInfo(List_dokter L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    string input;
    address_dokter P = first(L);
    printf("---------------------------------------------------------\n");
    printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
    printf("---------------------------------------------------------\n");
    if(first(L)!=NULL) {
        do {
            cout << "| " << info(P).kode << "\t| " << info(P).nama << "\t\t| " << info(P).spesialis << "\t\t|  " << info(P).jam_awal << " s/d " << info(P).jam_akhir << "\t| " << endl;
            P = next(P);
        } while((P)!=NULL);
    }
    printf("---------------------------------------------------------\n");
    cout << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    cin >> input;
}

void cariDataDokter(List_dokter L) {
    int x;

    cout << "Mencari data apa? " << endl;
    cout << "1. Kode" << endl;
    cout << "2. Spesialis" << endl;
    cout << "3. Jam kerja" << endl;
    //cout << "4. Jam temu" << endl;

    cout << endl;
    cout << "Pilihan : ";
    cin >> x;

    if (x == 1) {
        cariKodeDokter(L);
    } else if (x == 2) {
        cariSpesialisDokter(L);
    } else if (x == 3) {
        cariJamDokter(L);
    } else {
        //jam temu
    }
}

void cariSpesialisDokter(List_dokter L) {
    string opsi, cariSP;
    address_dokter P, Q;

    cout << "Masukan Spesialis dokter: ";
    cin >> cariSP;

    Q = findElmS(L, cariSP);
    if (Q == NULL) {
        cout << "Spesialis Dokter tidak ditemukan" << endl;
        cout << "Cari lagi? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            cariDataDokter(L);
        }
    } else {
        printf("---------------------------------------------------------\n");
        printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
        printf("---------------------------------------------------------\n");
        P = first(L);

        while (P != NULL) {
            if (info(P).spesialis == cariSP){
                cout << "| " << info(P).kode << "\t| " << info(P).nama << "\t\t| " << info(P).spesialis << "\t\t|  " << info(P).jam_awal << " s/d " << info(P).jam_akhir << "\t| " << endl;
                printf("---------------------------------------------------------\n");
            }
            P = next(P);
        }
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> opsi;
    }

}

void cariJamDokter(List_dokter L) {
    string opsi;
    int awal, akhir;
    address_dokter P, Q;

    cout << "Masukan Jam Kerja dokter: " << endl;
    cout << "Jam awal" << " | " << "Jam akhir" << endl;
    cin >> awal >> akhir;

    Q = findElmJ(L, awal, akhir);
    if (Q == NULL) {
        cout << "Spesialis Dokter tidak ditemukan" << endl;
        cout << "Cari lagi? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            cariDataDokter(L);
        }
    } else {
        printf("---------------------------------------------------------\n");
        printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
        printf("---------------------------------------------------------\n");

        P = first(L);

        while (P != NULL) {
            if (awal <= info(P).jam_awal  && info(P).jam_akhir <= akhir){
                cout << "| " << info(P).kode << "\t| " << info(P).nama << "\t\t| " << info(P).spesialis << "\t\t|  " << info(P).jam_awal << " s/d " << info(P).jam_akhir << "\t| " << endl;
                printf("---------------------------------------------------------\n");
            }
            P = next(P);
        }
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> opsi;
    }
}


void cariKodeDokter(List_dokter L) {
    string kode, opsi;
    address_dokter P;
    cout << "Masukan kode dokter: ";
    cin >> kode;

    P = findElm(L, kode);
    if (P == NULL) {
        cout << "Kode dokter tidak ditemukan" << endl;
        cout << "Cari lagi? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            cariDataDokter(L);
        }
    } else {
        printf("---------------------------------------------------------\n");
        printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
        printf("---------------------------------------------------------\n");
        cout << "| " << info(P).kode << "\t| " << info(P).nama << "\t\t| " << info(P).spesialis << "\t\t|  " << info(P).jam_awal << " s/d " << info(P).jam_akhir << "\t| " << endl;
        printf("---------------------------------------------------------\n");
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> opsi;
    }
}

void showSpecialist(List_dokter L, string spesialis) {
    address_dokter P = first(L);
    string input;
    printf("---------------------------------------------------------\n");
    printf("| KODE\t| NAMA\t\t| SPESIALIS\t| JAM OPERASI\t|\n");
    printf("---------------------------------------------------------\n");
    if(first(L)!=NULL) {
        do {
            cout << "| " << info(P).kode << "\t| " << info(P).nama << "\t\t| " << info(P).spesialis << "\t\t|  " << info(P).jam_awal << " s/d " << info(P).jam_akhir << "\t| " << endl;
            P = next(P);
        } while((P)!=NULL);
    }
    printf("---------------------------------------------------------\n");
    cout << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    cin >> input;
}

void tambahDokter(List_dokter &L) {
    infotype_dokter x;
    address_dokter Q;
    cout << "Mohon masukan kode dokter: ";
    cin >> x.kode;
    cout << "Mohon masukan nama dokter: ";
    cin >> x.nama;
    cout << "Mohon masukan spesialisasi dokter: ";
    cin >> x.spesialis;
    cout << "Mohon masukan jam awal operasi dokter: ";
    cin >> x.jam_awal;
    cout << "Mohon masukan jam akhir operasi dokter: ";
    cin >> x.jam_akhir;

    Q = findElm(L, x.kode);
    while (Q != NULL) {
        cout << "Terdapat dokter dengan kode yang sama, mohon input kode lagi" << endl;
        cin >> x.kode;
        Q = findElm(L, x.kode);
    }
    address_dokter p = alokasi(x);
    insertLast(L, p);

    cout << "Data berhasil ditambahkan" << endl;

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
    } while(P != NULL);
    return NULL;
}

address_dokter findElmS(List_dokter L, string SP) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_dokter P = first(L);
    do {
        if(info(P).spesialis== SP) {
            return P;
        }
        P = next(P);
    } while(P != NULL);
    return NULL;
}

address_dokter findElmJ(List_dokter L, int awal, int akhir) {
    /**
    * IS : List_dokter L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_dokter P = first(L);
    do {
        if(awal >= info(P).jam_awal || akhir <= info(P).jam_akhir) {
            return P;
        }
        P = next(P);
    } while(P != NULL);
    return NULL;
}


void deleteElm(List_dokter &L, address_dokter prec, address_dokter &p) {
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
        address_dokter Q;
        p = prec;
        Q = prev(prec);
        next(Q) = next(p);
        prev(next(Q)) = Q;
        next(p) = NULL;
        prev(p) = NULL;
    }
}


void countDataDokter(List_dokter L) {
  address_dokter p, Q, R, S;
  int i = 0;
  int l = 0;
  p = first(L);

  // Menghitung jumlah seluruh dokter
  while (p != NULL) {
    i++;
    p = next(p);
  }
  cout << "Jumlah Dokter adalah : " << i << endl;
  cout << "Keterangan :" << endl;

  Q = first(L);
  R = first(L);

  // Menampilkan setiap spesialis yang ada
  cout << "---------------------------------" << endl;
  cout << "| No\t| " << "Spesialis" << "\t|" << "Jumlah" << "\t|" << endl;
  while (Q != NULL) {
    bool isDuplicate = false;
    string spesialis = info(Q).spesialis;

    // Cek apakah spesialis sudah pernah ditampilkan sebelumnya
    address_dokter temp = first(L);
    while(temp != Q) {
      if(info(temp).spesialis == spesialis) {
        isDuplicate = true;
        break;
      }
      temp = next(temp);
    }

    // Cetak spesialis jika belum pernah ditampilkan sebelumnya
    if(!isDuplicate) {
      address_dokter D = first(L);
      int sum = 0;
      while(D != NULL){
        if(info(D).spesialis == spesialis) {
            sum++;
        }
        D = next(D);
      }
      l++;
      cout << "| " << l << "\t| " << spesialis << "\t\t|";
      cout << sum << "\t|" << endl;
    }

    Q = next(Q);
    R = Q;
  }
  cout << "---------------------------------" << endl;
  cout << endl;
}
