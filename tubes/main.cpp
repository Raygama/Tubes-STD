#include <iostream>

using namespace std;
#include "dokter.h"
#include "pasien.h"
#include "relasi.h"
#include "Menu.h"

int main()
{


    string opsi = "";
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

    pilihMenu(LD, LP, LR);

    /*
    isiDokter(LD);

    isiPasien(LP);

    string kode;
    int ID;
    cout << "Masukan kode dokter dan ID pasien yang ingin di sambung" << endl;
    for (i = 1; i<= 6; i++) {
        cout << "Kode Dokter: ";
        cin >> kode;
        cout << "ID pasien: ";
        cin >> ID;
        D = findElm(LD, kode);
        P = findElm(LP, ID);
        if (!cekAvailabilityDokter(D)) {
            cout << "Dokter sedang sibuk, ingin mengantri? (y/n)";
            cin >> opsi;
        }
        if ((opsi == "y" && !cekAvailabilityDokter(D)) || cekAvailabilityDokter(D)) {
            if (D != NULL && P != NULL) {
                info(D).status = true;
                info(P).status = true;
                R = alokasi(D, P);
                insertLast(LR, R);
            } else {
                cout << "ID atau Kode tidak ada" << endl;
            }
        } else if (opsi == "y" && cekAvailabilityDokter(D)) {
            if (D != NULL && P != NULL) {
                info(P).status = true;
                R = alokasi(D, P);
                insertLast(LR, R);
            } else {
                cout << "ID atau Kode tidak ada" << endl;
            }
        }
    }

    cout << "List Dokter: " << endl;
    printInfo(LD);

    cout << "List Pasien: " << endl;
    printInfo(LP);

    cout << "List Relasi: " << endl;
    printInfo(LR);
    cout << endl;

    cariDokter(LD, LP, LR);
    */
}
