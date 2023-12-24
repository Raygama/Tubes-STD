#include "dokter.h"
#include "pasien.h"
#include "relasi.h"
#include "Menu.h"

void pembuka() {
    cout << "=============================================" << endl;
    cout << "||              SELAMAT DATANG             ||" << endl;
    cout << "||       DI APLIKASI DOKTER DAN PASIEN     ||" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "=============================================" << endl;
    cout << "||                 1. START                ||" << endl;
    cout << "||                 2. OUT                  ||" << endl;
    cout << "=============================================" << endl;
}

void penutup() {
    cout << "=============================================" << endl;
    cout << "||             TERIMA KASIH                ||" << endl;
    cout << "||    TELAH MENGGUNAKAN APLIKASI INI       ||" << endl;
    cout << "=============================================" << endl;
}

void start(List_dokter &LD, List_pasien &LP, List_relasi &LR) {
    int x;

    do {
        pembuka();
        cout << "Opsi: ";
        cin >> x;
        if (x == 1) {
            pilihMenu(LD, LP, LR);
        }
    } while ( x != 2);
    penutup();
}

void menuAwal(){
    cout << "=============================================" << endl;
    cout << "||                PILIH MENU               ||" << endl;
    cout << "|| 1. Menambah data Dokter                 ||" << endl;
    cout << "|| 2. Menambah data Pasien                 ||" << endl;
    cout << "|| 3. Menghapus data Dokter                ||" << endl; //berserta relasinya atau tidak
    cout << "|| 4. Mencari data Dokter                  ||" << endl;
    cout << "|| 5. Mencari data Pasien                  ||" << endl;
    cout << "|| 6. Menyelesaikan Kunjungan Dokter       ||" << endl;
    cout << "|| 7. Menjadwalkan Kunjungan Dokter        ||" << endl;
    cout << "|| 8. Menghitung jumlah data Dokter        ||" << endl;
    cout << "|| 9. Menghitung jumlah data Pasien        ||" << endl;
    cout << "|| 10. Menampilkan data Dokter             ||" << endl;
    cout << "|| 11. Menampilkan data Pasien             ||" << endl;
    cout << "|| 12. Quit                                ||" << endl;
    cout << "=============================================" << endl;
}

void pilihMenu(List_dokter &LD, List_pasien &LP, List_relasi &LR){
    int x, opsi;
    infotype_dokter xKodeD;
    infotype_dokter xD;
    infotype_pasien xP;

    do {
        menuAwal();
        cout << "Pilihan : ";
        cin >> x;
        if ( x == 1) {
            //menambah dokter
            cout << "Opsi 1" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                isiDokter(LD);
            } else {
                continue;
            }
        } else if (x == 2) {
            //menambah pasien
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                isiPasien(LP);
            } else {
                continue;
            }
        } else if (x == 3) {
            cout << "Opsi 3" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 4) {
            cout << "Opsi 4" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 5) {
            cout << "Opsi 5" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 6) {
            cout << "Opsi 6" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 7) {
            cout << "Opsi 7" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 8) {
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 9) {
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 10) {
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else if (x == 11) {
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                //data(x);
            } else {
                continue;
            }
        } else {
            break;
        }
    } while (x != 12);
}
