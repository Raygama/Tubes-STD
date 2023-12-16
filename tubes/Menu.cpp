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
    cout << "|| 1. Menambah data Dokter/Pasien          ||" << endl;
    cout << "|| 2. Menghapus data Dokter/Pasien         ||" << endl;
    cout << "|| 3. Menyelesaikan Kunjungan Dokter       ||" << endl;
    cout << "|| 4. Mencari data Dokter/Pasien           ||" << endl;
    cout << "|| 5. Menjadwalkan Kunjungan Dokter        ||" << endl;
    cout << "|| 6. Menghitung jumlah data Dokter/Pasien ||" << endl;
    cout << "|| 7. Menampilkan data Dokter/Pasien       ||" << endl;
    cout << "|| 8. Quit                                 ||" << endl;
    cout << "=============================================" << endl;
}

void pilihMenu(List_dokter &LD, List_pasien &LP, List_relasi &LR){
    int x, xData, xTambah, opsi;
    infotype_dokter xKodeD;
    infotype_dokter xD;
    infotype_pasien xP;

    do {
        menuAwal();
        cout << "Pilihan : ";
        cin >> x;
        if ( x == 1) {
            cout << "Opsi 1" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 2) {
            cout << "Opsi 2" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 3) {
            cout << "Opsi 3" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 4) {
            cout << "Opsi 4" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 5) {
            cout << "Opsi 5" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 6) {
            cout << "Opsi 6" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else if (x == 7) {
            cout << "Opsi 7" << endl;
            cout << "1. [WIP]" << endl;
            cout << "2. Back" << endl;
            cin >> opsi;
            if (opsi == 1) {
                // WIP
            } else {
                continue;
            }
        } else {
            break;
        }
    } while (x != 8);
}
