#include "bst.h"

#include <cstdlib>

using namespace std;

int main(){
    BST<int> bst1;

    bst1.insert(8);
    bst1.insert(3);
    bst1.insert(10);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(4);
    bst1.insert(7);
    bst1.insert(14);
    bst1.insert(13);



    bst1.PreOrder();
    bst1.visit();



}