#include <iostream>

using namespace std;
#include "dokter.h"
#include "pasien.h"
#include "relasi.h"
#include "Menu.h"

int main()
{
    List_dokter LD;
    List_pasien LP;
    List_relasi LR;

    infotype_dokter xD;
    infotype_pasien xP;

    createList(LD);
    createList(LP);
    createList(LR);

    isiDokter(LD);
    isiPasien(LP);
    isiKunjungan(LR, LD, LP);
    start(LD, LP, LR);

}
