#include "bst.h"

#include <cstdlib>

using namespace std;

int main(){
    BST<int> bst1;

    bst1.insert(25);
    bst1.insert(15);
    bst1.insert(10);
    bst1.insert(4);
    bst1.insert(12);
    bst1.insert(22);
    bst1.insert(18);
    bst1.insert(24);
    bst1.insert(50);
    bst1.insert(35);
    bst1.insert(31);
    bst1.insert(44);
    bst1.insert(70);
    bst1.insert(66);
    bst1.insert(90);
    


    bst1.visit();
    bst1.PreOrder();
    cout << endl << endl;
    bst1.PostOrder();
    cout << endl << endl;
    bst1.InOrder();
    cout << endl << endl;
    bst1.min();
    cout << endl << endl;
    bst1.max();

    bst1.remove(50);
    cout << "\nELEMENTO DA RIMUOVERE = 50\n";
    bst1.PreOrder();

}