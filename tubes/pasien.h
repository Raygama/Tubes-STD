#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

// DLL
struct infotype_pasien {
    string nama;
    int id, umur;
    bool status;
};

typedef struct elmlist_pasien *address_pasien;

struct elmlist_pasien{
    infotype_pasien info;
    address_pasien next;
    address_pasien prev;
};

struct List_pasien{
    address_pasien first;
    address_pasien last;
};

void createList(List_pasien &L);
void insertFirst(List_pasien &L, address_pasien P);
void insertLast(List_pasien &L, address_pasien P);
void insertAfter(address_pasien Prec, address_pasien P);
void deleteElm(List_pasien &L, address_pasien prec, address_pasien &p);

address_pasien alokasi(infotype_pasien x);
void dealokasi(address_pasien &P);
address_pasien findElm(List_pasien L, int id);
void printInfo(List_pasien L);


#endif // PASIEN_H_INCLUDED
