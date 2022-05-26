//
// Created by Ariq Heritsa on 20/05/22.
//

#ifndef STD_MOD6_DS4501_1305213031_APB_DLL_FIRST_LAST_H
#define STD_MOD6_DS4501_1305213031_APB_DLL_FIRST_LAST_H

#include <iostream>

using namespace std;

#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

typedef int infotype;
typedef struct elmList *address;

struct elmList {
  infotype info;
  address next, prev;
};

struct List {
  address first, last;
};

//Procedure createList (input/ouput L : List)
void createList(List &L);

//Function createElemen (dataBaru: infotype) → address
address createElement(infotype dataBaru);

//Procedure insertFirst (input/ouput L : List, input P : address)
void insertFirst(List &L, address P);

//Procedure insertLast (input/ouput L : List, input P : address)
void insertLast(List &L, address P);

//Procedure InsertAfter (input Prec : address, P : address);
void insertAfter(address Prec, address P);

//Procedure insertAscending (input/ouput L : List, input dataBaru : infotype)
void insertAscending(List &L, infotype dataBaru);

//Procedure deleteFirst (input/ouput L : List, output P : address)
void deleteFirst(List &L, address &P);

//Procedure deleteLast (input/ouput L : List, output P : address)
void deleteLast(List &L, address &P);

//Procedure deleteAfter (input Prec: address, output P : address)
void deleteAfter(address Prec, address &P);

//Procedure deleteElm (input/ouput L : List, input dataHapus : infotype)
void deleteElm(List &L, infotype dataHapus);

//Procedure printList (input L : List);
void printList(List L);

//Function findElemen (L: List, dataDicari: infotype) → integer
int findElement(List &L, infotype dataDicari);

//Function frequencyofElm (L: List, dataDicari: infotype) → integer
int frequencyofElm(List L, infotype dataDicari);

#endif //STD_MOD6_DS4501_1305213031_APB_DLL_FIRST_LAST_H
