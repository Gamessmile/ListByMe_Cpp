#include "list.h"

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

    cout << lista << endl;
    lista.removen(2);
    cout << lista <<endl;
    lista.remove(5);
    cout << lista << endl;
    lista.remove(52);
    cout << lista << endl;


    //cout << *lista(3); // Stampa elemento numerato 3
    //cout << *lista(9); // Errore


}