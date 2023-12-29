#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
using namespace std;

void pembuka();

void penutup();

void menuAwal();

void start(List_dokter &LD, List_pasien &LP, List_relasi &LR);

void pilihMenu(List_dokter &LD, List_pasien &LP, List_relasi &LR);

void showCurrentTime();

#endif // MENU_H_INCLUDED
