#include "bst.h"

#include <cstdlib>

using namespace std;

int main(){
    BST<int> bst1;

    for(int i=0; i<10;i++){
        bst1.insert(rand()%100);
    }


    bst1.PreOrder();
    bst1.visit();



}