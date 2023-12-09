#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

// CSLL
struct infotype_dokter {
    string id, nama, spesialis;
};

typedef struct elmlist_dokter *address_dokter;

struct elmlist_dokter {
    infotype_dokter info;
    address_dokter next;
};

struct List_dokter {
    address_dokter first;
};

void createList(List_dokter &L);
void insertFirst(List_dokter &L, address_dokter P);
void insertAfter(List_dokter &L, address_dokter Prec, address_dokter P);
void insertLast(List_dokter &L, address_dokter P);
void deleteFirst(List_dokter &L, address_dokter &P);
void deleteLast(List_dokter &L, address_dokter &P);
void deleteAfter(List_dokter &L, address_dokter Prec, address_dokter &P);

address_dokter alokasi(infotype_dokter x);
void dealokasi(address_dokter &P);
address_dokter findElm(List_dokter L, string id);
void printInfo(List_dokter L);

#endif // DOKTER_H_INCLUDED
