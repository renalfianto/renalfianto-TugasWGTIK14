#include "SLL.h"

void createList(List &L){
    first(L) = NULL;
}

pointer newNode(infotype x){
    pointer ptr = new Node;
    info(ptr) = x;
    next(ptr) = NULL;
    return ptr;
}

void addFirst(List &L, pointer ptr){
    if(first(L) == NULL){
        first(L) = ptr;
    } else {
        next(ptr) = first(L);
        first(L) = ptr;
    }
}

void addLast(List &L, pointer ptr){
    if(first(L) == NULL){
        first(L) = ptr;
    } else {
        pointer current = first(L);
        while(next(current) != NULL){
            current = next(current);
        }
        next(current) = ptr;
    }
}

void addAfter(List &L, pointer ptr, pointer newPtr){
    pointer current = first(L);
    while(current != ptr){
        current = next(current);
    }
    next(newPtr) = next(current);
    next(current) = newPtr;
}

void addBefore(List &L, pointer ptr, pointer newPtr){
    pointer current = first(L);
    if(ptr == current){
        addFirst(L, newPtr);
    } else {
        while(next(current) != ptr){
            current = next(current);
        }
        next(newPtr) = next(current);
        next(current) = newPtr;
    }
}

void printList(List L){
    if(first(L) != NULL){
        pointer ptr = first(L);
        while(ptr != NULL){
            cout << info(ptr) << " ";
            ptr = next(ptr);
        }
    }
    cout << endl;
}

pointer removeFirst(List &L){
    pointer current = first(L);
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else if(next(current) == NULL){
        first(L) = NULL;
    } else {
        first(L) = next(current);
        next(current) = NULL;
    }
}

pointer removeLast(List &L){
    pointer current = first(L);
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else if (next(current) == NULL){
        first(L) = NULL;
    } else {
        while(next(next(current)) != NULL){
            current = next(current);
        }
        next(current) = NULL;
    }
    return current;
}

pointer removeNode(List &L, pointer ptr){
    pointer temp = first(L);
    pointer current = first(L);
    if(ptr == current && next(current) != NULL){
        first(L) = next(current);
        return temp;
    } else if(ptr == current && next(current) == NULL){
        removeLast(L);
        return temp;
    }
    while(next(current) != ptr){
        current = next(current);
    }
    temp = next(current);
    if(next(temp) == NULL){
        removeLast(L);
    } else {
        next(current) = next(next(current));
    }
    return temp;
}
