#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <iostream>
#include <ctime>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define prev(P) P->prev
#define next(P) P->next
#define info(P) P->info

// DLL
struct infotype_dokter {
    string kode, nama, spesialis;
    int jam_awal, jam_akhir;
};

typedef struct elmlist_dokter *address_dokter;

struct elmlist_dokter {
    infotype_dokter info;
    address_dokter next;
    address_dokter prev;
};

struct List_dokter {
    address_dokter first, last;
};

void createList(List_dokter &L);
void insertFirst(List_dokter &L, address_dokter P);
void insertAfter(List_dokter &L, address_dokter Prec, address_dokter P);
void insertLast(List_dokter &L, address_dokter P);
void deleteElm(List_dokter &L, address_dokter prec, address_dokter &p);
void showSpecialist(List_dokter L, string spesialis);
void isiDokter(List_dokter &L);
void tambahDokter(List_dokter &L);
void cariDataDokter(List_dokter L);
void cariKodeDokter(List_dokter L);
void cariJamDokter(List_dokter L);
void cariSpesialisDokter(List_dokter L);
void cariDataDokter(List_dokter L);
void sortDokter(List_dokter &L);

int getCurrentJam();
address_dokter alokasi(infotype_dokter x);
void dealokasi(address_dokter &P);
address_dokter findElm(List_dokter L, string kode);
address_dokter findElmS(List_dokter L, string SP);
address_dokter findElmJ(List_dokter L, int jam);
void printInfo(List_dokter L);
int countDokter(List_dokter L, string &x);
void countDataDokter(List_dokter L);

#endif // DOKTER_H_INCLUDED
