#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P -> data
#define next(P) P -> next
#define first(p) p.first

typedef int infotype;
typedef struct Node *pointer;

struct Node {
    infotype data;
    pointer next;
};

struct List {
    pointer first;
};

void createList(List &L);
pointer newNode(infotype x);
void addFirst(List &L, pointer ptr);
void addLast(List &L, pointer ptr);
void addAfter(List &L, pointer ptr, pointer newPtr);
void addBefore(List &L, pointer ptr, pointer newPtr);
void printList(List L);
pointer removeFirst(List &L);
pointer removeLast(List &L);
pointer removeNode(List &L, pointer ptr);


#endif // SLL_H_INCLUDED
