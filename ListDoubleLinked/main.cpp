#include "list.h"

int main(){

    listdl<int> lista;

    lista.insert(1,"cima");
    lista.insert(2,"fondo");
    lista.insert(3,"mezzo");
    lista.insert(4,"fondo");
    lista.insert(2,"cima");

    cout << lista;


}