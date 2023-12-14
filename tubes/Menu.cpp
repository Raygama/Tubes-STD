#include "dokter.h"
#include "pasien.h"
#include "relasi.h"
#include "Menu.h"

void pembuka(){
    int x;

    cout << "=============================================" << endl;
    cout << "||              SELAMAT DATANG             ||" << endl;
    cout << "||       DI APLIKASI DOKTER DAN PASIEN     ||" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "=============================================" << endl;
    cout << "||                 1. START                ||" << endl;
    cout << "||                 2. OUT                  ||" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "Pilihan : ";
    cin >> x;

    if (x == 1) {
        menuAwal();
    } else {
        cout << "=============================================" << endl;
        cout << "||             TERIMA KASIH                ||" << endl;
        cout << "||    TELAH MENGGUNAKAN APLIKASI INI       ||" << endl;
        cout << "=============================================" << endl;
    }
};

void menuAwal(){
    cout << "=============================================" << endl;
    cout << "||                PILIH MENU               ||" << endl;
    cout << "|| 1. Menambah data Dokter/Pasien          ||" << endl;
    cout << "|| 2. Menghapus data Dokter/Pasien         ||" << endl;
    cout << "|| 3. Mencari data Dokter/Pasien           ||" << endl;
    cout << "|| 4. Menghubungkan Data Dokter dan Pasien ||" << endl;
    cout << "|| 5. Menghitung jumlah data Dokter/Pasien ||" << endl;
    cout << "|| 6. Menampilkan data Dokter/Pasien       ||" << endl;
    cout << "=============================================" << endl;
}

void pilihMenu(){
    int x, xData, xTambah;
    infotype_dokter xKodeD;
    infotype_dokter xD;
    infotype_pasien xP;
    cout << "Pilihan Menu : ";
    cin >> x;
    if ( x == 1) {
        cout << "Menambah data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << "Data : ";
        cin >> xData;
        if (xData == 1) {
            /*cout << "Jumlah data yang ditambahkan : "
            cin >> xTambah;
            cout << "Masukan data dokter: ID, Nama, Spesialis" << endl;
            for (i = 1; i <= xTambah; i++) {
                cin >> xD.id >> xD.nama >> xD.spesialis;
                D = alokasi(xD);
                insertLast(LD, D);
            } */
        } else if (xData == 2) {
            /* cout << "Jumlah data yang ditambahkan : "
            cin >> xTambah;
            cout << "Masukan data pasien: Kode, Nama, Umur" << endl;
            for (i = 1; i <= xTambah; i++) {
                cin >> xP.kode >> xP.nama >> xP.umur;
                P = alokasi(xP);
                insertLast(LP, P);
            }
        } */
    } else if (x == 2) {
        cout << "Menghapus data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << "Data : ";
        cin >> xData;
        if (xData == 1) {
            /* cout << "Kode Dokter yang akan dihapus : ";
            cin >> xKodeD;
            // function baru cari dokter selama tdak di appoiment

            bool status = //fucntion
            if (status) {
                //delete
            } else {
                cout << " Dokter Sedang Melayani Pasien " << endl;
            } */
        } else if (xData == 2) {
            /* cout << "Kode Pasien yang akan dihapus : ";
            cin >> xKode */
            //
        }

    } else if (x == 3) {
        cout << "Mencari data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << "Data : ";
        cin >> xData;

        if(xData == 1) {
           /* */
        } else if (xData == 2) {
            /* cout << "Masukan kode dokter yang dicari : ";
            cin >> xKode;
            adr data = findElm(L, xKode);*/
        }

    } else if (x == 4) {
        cout << "Menghubungkan Data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << "Data : ";
        cin >> xData;

        if (xData == 1) {

        } else if (xData == 2) {

        }

    } else if (x == 5) {
        cout << "Menghitung Jumlah Data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << "Data : ";
        cin >> xData;

        if (xData == 1) {

        } else if (xData == 2) {

        }


    } else if (x == 6) {
        cout << "Menampilkan Data" << endl;
        cout << " 1. Dokter" << endl;
        cout << " 2. Pasien" << endl;
        cout << " 3. Dokter, Pasien beserta relasinya" << endl;
        cout << "Data : ";
        cin >> xData;

        if (xData == 1) {

        } else if (xData == 2) {

        } else if (xData == 3) {

        }
        }
    }
    menuAwal();
}
