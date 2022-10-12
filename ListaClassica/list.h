#include <iostream>
#include "node.h"

using namespace std;

template<class T>
class ClassicList{
    private:
        Node<T> *head; //Testa della lista, ovvero il primo valore o valore più in cima
        int dim; //Dimensione, o numero di elementi, presenti in Lista,
    public:
        ClassicList(){
            this->head = nullptr; //Porre testa pari a nullptr ovvero a nulla (lista è vuota)
            this->dim = 0; //Porso uguale a 0 poichè la lista è ancora vuota
        }
        void insert(T val){ //Funzione di insert (in cima)
            if(this->dim == 0){ //Se la lista è vuota
                this->dim++; //Aumentare Dim (aggiungiamo elemento, quindi la dimensione non sarà più 0)
                this->head = new Node<T>(val); //Il nostro elemento sarà la nuova testa
                return;    
            }
            else{ //Altrimenti
                this->dim++; //Aumentiamo Dim di uno, poichè la dimensione aumenterà ad ogni input
                Node<T> *ptr = new Node<T>(val); //Creiamo un puntatore di appoggio con al suo interno il valore in input
                ptr->next=this->head; //Poniamo il successore al nostro ptr uguale alla testa, la testa sarà il successore del nostro nuovo dato
                this->head=ptr; //Il nostro nuovo elemento sarà la nuova testa
            }
        }

        friend ostream& operator <<(ostream& os, const ClassicList<T>& obj){
            Node<T> *ptr = obj.head;
            
            for(int i=1;ptr;i++){
                os << i << ") " << *ptr << endl;
                ptr = ptr->getNext();   
            }
            return os;
        }

        Node<T>* operator() (int i){
            if(i > this->dim){
                cerr << "\n\nLa dimensione della lista, e' inferiore a l'input da lei richiesto";
                exit(5);
            }
            else{
                Node<T> *ptr = this->head;
                for(int j=0; j<i-1;j++){
                    ptr = ptr->getNext();
                }
                cout << "\nIl valore nella posizione " << i <<" nella lista, e' il seguente:\n" << i << ") ";
                return ptr;
                
            }
        }
};
