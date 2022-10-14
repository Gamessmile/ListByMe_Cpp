#include <iostream>
#include "node.h"

using namespace std;

template<class T>
class listdl{
    private:
        Node<T> *head;
        Node<T> *tail;
        int dim;
        
    public:
        listdl(){
            this->head = nullptr;
            this->tail = nullptr;
            this->dim = 0;
        }


        void insert(T val, string s){
            if(this->head == nullptr){
                this->head = new Node<T> (val);
                this->tail = this->head;
                dim++;
            }
            else{
                while(s!="cima" &&  s!="fondo" && s!="mezzo"){
                    cerr << "Specificare dove inserire l'input dato\nAgenda:\n"<<
                    "cima = Inserisce l'elemento come nuova head(testa)\n"<<
                    "fondo = Inserisce l'elemento come nuova tail(coda)\n"<<
                    "mezzo = Inserisce l'elemento in mezzo alla lista";
                    exit(0);
                }
                if(s == "cima"){
                    dim++;
                    Node<T> *ptr = new Node<T> (val);
                    ptr->next = this->head;
                    this->head = ptr;
                }
                if(s == "fondo"){
                    dim++;
                    Node<T> *ptr = new Node<T>(val);
                    this->tail->next = ptr;
                    ptr->pre = this->tail;
                    this->tail = ptr;
                }
                if(s=="mezzo"){
                    Node<T> *ctr = this->head;
                    for(int i=0; i<(int)dim/2-1; i++){
                        ctr = ctr->getNext();
                    }
                    Node<T> *ptr = new Node<T>(val);
                    ptr->next = ctr->getNext();
                    ptr->pre = ctr;
                    ptr->next->pre = ptr;
                    ctr->next = ptr;
                    dim++;

                }
            }
        }

        friend ostream& operator <<(ostream& os, listdl<T>& obj){
            Node<T> *ptr = obj.head;
            for(int i=0; ptr; i++){
                os << i+1 << ") " << *ptr <<endl;
                ptr = ptr->getNext();
            }
            return os;
        }


};