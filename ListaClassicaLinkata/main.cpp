#include "ListaClassica\list.h"

using namespace std;

int main(){

    ClassicList<int> lista;

    lista.insert(4);
    // head = 4, next = nullptr
    lista.insert(5);
    // head = 5, next = 4, next = nullptr
    lista.insert(14);
    // head = 14, next = 5, next = 4, next = nullptr
    lista.insert(52);
    // head = 52, next = 14, next = 5, next = 4, next = nullptr

    cout << lista;


    cout << *lista(3); // Stampa elemento numerato 3
    cout << *lista(9); // Errore


}