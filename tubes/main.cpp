#include <iostream>

using namespace std;
#include "dokter.h"
#include "pasien.h"
#include "relasi.h"

int main()
{
    int i;
    List_dokter LD;
    List_pasien LP;
    List_relasi LR;

    address_dokter D;
    address_pasien P;
    address_relasi R;
    infotype_dokter xD;
    infotype_pasien xP;

    createList(LD);
    createList(LP);
    createList(LR);

    cout << "Masukan data dokter: ID, Nama, Spesialis" << endl;
    for (i = 1; i <= 5; i++) {
        cin >> xD.id >> xD.nama >> xD.spesialis;
        D = alokasi(xD);
        insertLast(LD, D);
    }

    cout << "Masukan data pasien: Kode, Nama, Umur" << endl;
    for (i = 1; i <= 5; i++) {
        cin >> xP.kode >> xP.nama >> xP.umur;
        P = alokasi(xP);
        insertLast(LP, P);
    }

    string ID, kode;
    cout << "Masukan ID dokter dan Kode pasien yang ingin di sambung" << endl;
    for (i = 1; i<= 6; i++) {
        cout << "ID Dokter: ";
        cin >> ID;
        cout << "Kode pasien: ";
        cin >> kode;
        D = findElm(LD, ID);
        P = findElm(LP, kode);
        if (D != NULL && P != NULL) {
            R = alokasi(D, P);
            insertLast(LR, R);
        } else {
            cout << "ID atau Kode tidak ada" << endl;
        }
    }

    cout << "List Dokter: " << endl;
    printInfo(LD);

    cout << "List Pasien: " << endl;
    printInfo(LP);

    cout << "List Relasi: " << endl;
    printInfo(LR);
}
