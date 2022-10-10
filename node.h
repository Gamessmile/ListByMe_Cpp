#include <iostream>

using namespace std;

template<class T>
class Node{
    private:
        Node<T> *next; //Puntatore al successore di ogni elemento della lista
        T val; //Valore contenuto da ogni elemento della lista

        template<class U>
        friend class ClassicList;
    public:
        Node(T val){
            this->val = val; //Assegnazione del valore in input
            this->next = nullptr; //Porso uguale a nullptr, ovvero a nulla
        }
        Node<T> *getNext(){
            return this->next; //Ritorno di un parametro privato
        }
        
        friend ostream& operator <<(ostream& os, const Node<T>& obj){
            os << "Valore: "<< obj.val;
            return os;
        }
        
};
