#include "list.h"

int main(){

    listdl<int> lista;

    lista.insert(1,"cima");
    lista.insert(2,"fondo");
    lista.insert(3,"mezzo");
    lista.insert(4,"fondo");
    lista.insert(2,"cima");
    

    cout << lista <<endl << endl;
    lista.remove(2,"n");
    cout << lista <<endl << endl;
    lista.remove(1,"n");
    cout << lista <<endl << endl;
    lista.remove(3,"n");
    cout << lista <<endl << endl;
    lista.remove(3,"valore");
    cout << lista <<endl << endl;


    lista.insert(3,"cima");
    lista.insert(8,"cima");
    lista.insert(19,"cima");
    lista.insert(9,"cima");
    lista.bubble("Decrescente");
    cout << lista <<endl << endl;
    lista.bubble("Crescente"); //NON FUNZIONA
    cout << lista <<endl << endl;
}