#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "relasi.h"
#include "pasien.h"
#include "dokter.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define pasien(P) P->pasien
#define dokter(P) P->dokter

typedef struct elmlist_relasi *address_relasi;
// Single Linked List
struct elmlist_relasi{
    address_relasi next;
    address_pasien pasien;
    address_dokter dokter;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);

address_relasi alokasi( address_dokter P, address_pasien C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_dokter P, address_pasien C);
void printInfo(List_relasi L);
#endif // RELASI_H_INCLUDED
