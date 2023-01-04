#include "Tree.h"

adrNode newNode_1301213304(infotype x){
    adrNode p = new Node;
    info(p) = x;
    left(p) = NULL;
    right(p) = NULL;
    return p;
}

adrNode findNode_1301213304(adrNode root, infotype x){
    if (root == NULL || info(root) == x){
        return root;
    }
    if (x < info(root)){
        return findNode_1301213304(left(root), x);
    }
    return findNode_1301213304(right(root), x);
}

void insertNode_1301213304(adrNode &root, adrNode p){
    if(root == NULL){
        root = p;
    } else{
        if (info(p) < info(root)){
           if(left(root) == NULL){
                left(root) = p;
            } else{
                insertNode_1301213304(left(root), p);
            }
       }else{
            if(right(root) == NULL){
                right(root) = p;
            } else{
                insertNode_1301213304(right(root), p);
            }
       }
    }
}

void printPreOrder_1301213304(adrNode root){
   if (root != NULL) {
       cout << info(root) << " ";
       printPreOrder_1301213304(left(root));
       printPreOrder_1301213304(right(root));
   }
}

void printDescendant_1301213304(adrNode root, infotype x){
    adrNode n = findNode_1301213304(root, x);
    if(n){
        printPreOrder_1301213304(left(n));
        printPreOrder_1301213304(right(n));
    }
}

int sumNode_1301213304(adrNode root){
    if(root != NULL){
        return info(root) + sumNode_1301213304(left(root)) + sumNode_1301213304(right(root));
    }
    return 0;
}

int countLeaves_1301213304(adrNode root){
    if(root == NULL){
        return 0;
    } else if(left(root) == NULL && right(root) == NULL){
        return 1;
    }
    return countLeaves_1301213304(left(root)) + countLeaves_1301213304(right(root));
}

int heightTree_1301213304(adrNode root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = heightTree_1301213304(left(root));
    int rightHeight = heightTree_1301213304(right(root));
    return max(leftHeight, rightHeight) + 1;
}
