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

    isiDokter(LD);
    start(LD, LP, LR);

}
