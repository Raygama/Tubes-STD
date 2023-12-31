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

void showCurrentTime() {
    time_t t = time(0);
    tm* now = localtime(&t);
    cout << (now->tm_hour) << ":" << (now->tm_min);
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
    cout << "|| 1. Mendaftarkan Dokter                  ||" << endl;
    cout << "|| 2. Mendaftarkan Pasien                  ||" << endl;
    cout << "|| 3. Menghapus data Dokter                ||" << endl;
    cout << "|| 4. Mencari data Dokter                  ||" << endl;
    cout << "|| 5. Mencari data Pasien                  ||" << endl;
    cout << "|| 6. Menyelesaikan Kunjungan Dokter       ||" << endl;
    cout << "|| 7. Menjadwalkan Kunjungan Dokter        ||" << endl;
    cout << "|| 8. Mengubah Kunjungan Dokter            ||" << endl;
    cout << "|| 9. Membatalkan Kunjungan Dokter         ||" << endl;
    cout << "|| 10. Menghitung jumlah data Dokter       ||" << endl;
    cout << "|| 11. Menghitung jumlah data Pasien       ||" << endl;
    cout << "|| 12. Menampilkan data Dokter             ||" << endl;
    cout << "|| 13. Menampilkan data Pasien             ||" << endl;
    cout << "|| 14. Menampilkan data Kunjungan          ||" << endl;
    cout << "|| 15. Sorting Data                        ||" << endl;
    cout << "|| 16. Quit                                ||" << endl;
    cout << "=============================================" << endl;
    cout << "========== CURRENT TIME: ";
    showCurrentTime();
    cout << " ==============" << endl;
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
            do {
                tambahDokter(LD);
                cout << "Ingin tambah dokter lagi?" << endl;
                cout << "1. iya" << endl;
                cout << "2. tidak" << endl;
                cin >> opsi;
            } while (opsi != 2);
        } else if (x == 2) {
            //menambah pasien
            do {
                tambahPasien(LP);
                printf("Ingin tambah lagi? \n");
                cout << "1. iya" << endl;
                cout << "2. tidak" << endl;
                cin >> opsi;
            } while (opsi != 2);
        } else if (x == 3) {
            do {
                deleteDokter(LD, LR);
                cout << "Ingin delete dokter lagi?" << endl;
                cout << "1. iya" << endl;
                cout << "2. tidak" << endl;
                cin >> opsi;
            } while (opsi != 2);
        } else if (x == 4) {
            cariDataDokter(LD);
        } else if (x == 5) {
            cariDataPasien(LP);
        } else if (x == 6) {
            selesaiKunjungan(LR, LP, LD);
        } else if (x == 7) {
            do {
                jadwalKunjungan(LR, LP, LD);
                cout << "Ingin menjadwalkan lagi? " << endl;
                cout << "1. iya" << endl;
                cout << "2. tidak" << endl;
                cin >> opsi;
            } while (opsi != 2);
        } else if (x == 8) {
            editKunjungan(LR, LP, LD);
        } else if (x == 9) {
            batalKunjungan(LR, LP, LD);
        } else if (x == 10) {
            cout << "Ingin menampilkan jumlah dokter?" << endl;
            cout << "1. iya" << endl;
            cout << "2. tidak" << endl;
            cin >> opsi;
            if (opsi == 1) {
                countDataDokter(LD);
            } else {
                continue;
            }
        } else if (x == 11) {
            cout << "Ingin menampilkan jumlah pasien?" << endl;
            cout << "1. iya" << endl;
            cout << "2. tidak" << endl;
            cin >> opsi;
            if (opsi == 1) {
                cout << "Jumlah Pasien : " << countPasien(LP) << endl;
            } else {
                continue;
            }
        } else if (x == 12) {
            printInfo(LD);
        } else if (x == 13) {
            printInfo(LP);
        } else if (x == 14){
            cout << "Ingin melihat kunjungan siapa? " << endl;
            cout << "1. Pasien" << endl;
            cout << "2. Dokter" << endl;
            cout << "3. Semua" << endl;
            cin >> opsi;
            if (opsi == 1) {
                showKunjunganPasien(LR, LP);
            } else if (opsi == 2) {
                showKunjunganDokter(LR, LD);
            } else {
                showAllKunjungan(LR);
            }
        } else if (x == 15) {
            cout << "Pilih data yang ingin di sort" << endl;
            cout << "1. Dokter" << endl;
            cout << "2. Pasien" << endl;
            cout << "3. Kunjungan" << endl;
            cout << "Pilihan :" ;
            cin >> opsi;
            if (opsi == 1) {
                sortDokter(LD);
            } else if (opsi == 2) {
                sortPasien(LP);
            } else if (opsi == 3) {
                sortKunjungan(LR);
            }
        }
    } while (x != 16);
}
