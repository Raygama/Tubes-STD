#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "relasi.h"
#include "pasien.h"
#include "dokter.h"
#include <ctime>

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define last(L) L.last
#define first(L) L.first
#define pasien(P) P->pasien
#define dokter(P) P->dokter
#define info(P) P->info

typedef struct elmlist_relasi *address_relasi;
struct infotype_relasi {
    int jamAwal, jamAkhir;
};
// Double Linked List
struct elmlist_relasi{
    address_relasi next;
    address_relasi prev;
    address_pasien pasien;
    address_dokter dokter;
    infotype_relasi info;
};

struct List_relasi{
    address_relasi first, last;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);
bool cekAvailabilityDokter(List_relasi LR, address_dokter D, int jam, int durasi);
void deleteDokter(List_dokter &LD, List_relasi &LR);
void jadwalKunjungan(List_relasi &LR, List_pasien &LP, List_dokter LD);
void showKunjunganDokter(List_relasi LR, List_dokter LD);
void showKunjunganPasien(List_relasi LR, List_pasien LP);
void showKunjunganDokter(List_relasi LR, List_dokter LD);
void showAllKunjungan(List_relasi L);
void selesaiKunjungan(List_relasi &LR, List_pasien &LP, List_dokter LD);
void batalKunjungan(List_relasi &LR, List_pasien LP, List_dokter LD);
void editKunjungan(List_relasi &LR, List_pasien LP, List_dokter LD);
void showKesibukanDokter(List_relasi LR, address_dokter D);

address_relasi alokasi( address_dokter P, address_pasien C);
address_relasi findElm(List_relasi L, address_dokter P, address_pasien C);
void showAllKunjungan(List_relasi L);
void showKunjunganDokter(List_relasi LR, List_dokter LD);
void showKunjunganPasien(List_relasi LR, List_pasien LP);
void isiKunjungan(List_relasi &LR, List_dokter LD, List_pasien LP);


#endif // RELASI_H_INCLUDED
