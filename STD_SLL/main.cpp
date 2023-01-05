#include "SLL.h"
#include <iostream>

using namespace std;

int main()
{
    List L;
    cout << L.first << endl;
    createList(L);
    cout << L.first << endl;

    pointer ptr;
    ptr = newNode(43);
    cout << info(ptr) << endl;
    cout << next(ptr) << endl;

    addFirst(L, ptr);
    cout << info(L.first) << endl;
    ptr = newNode(34);
    addFirst(L, ptr);
    ptr = newNode(30);
    addFirst(L, ptr);
    ptr = newNode(20);
    addLast(L, ptr);
    printList(L);

    removeLast(L);
    printList(L);

    return 0;
}
