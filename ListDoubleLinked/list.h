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


        void insert(T val, string s){ //Aggiunta di un elemento nella lista in base alla specifica sul main
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
                if(s == "cima"){ //Aggiunge il valore in cima
                    dim++;
                    Node<T> *ptr = new Node<T> (val);
                    ptr->next = this->head;
                    this->head->pre = ptr;
                    this->head = ptr;
                }
                
                if(s == "fondo"){ //Aggiunge il valore in fondo
                    dim++;
                    Node<T> *ptr = new Node<T>(val);
                    this->tail->next = ptr;
                    ptr->pre = this->tail;
                    this->tail = ptr;
                }
                
                if(s=="mezzo"){ //Aggiunge il valore in mezzo
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

        void remove(T val, string tipo){ //Rimozione dell'elemento nella lista in base alla specifica sul main
            while(tipo != "n" && tipo != "valore"){
                cerr << "Specificare in che modo rimuovere l'input dato.\nAgenda:\n"<<
                "n = rimuovere il valore posto nella ''val''esima posizione.\n"<<
                "valore == rimuovere il ''val'' dalla lista, ovunque esso sia.\n\n";
                exit(1);
            }
            if(tipo=="n"){  //Potrebbe ottimizzarsi, rimuove il valore nella posizione val   
                if(val>dim){
                    cerr << "Il valore inserito è superiore alla lunghezza della stessa lista";
                    exit(2);
                }

                if(val>1 && val<dim){              
                    Node<T> *ptr = this->head;
                    for(int i=0; i<val-1; i++){
                        ptr = ptr->getNext();
                    }
                    Node<T> *ctr = ptr->getPre();
                    Node<T> *k = ptr->getNext();
                    ctr->next = ptr->getNext();
                    k->pre = ctr;
                    ptr->next = nullptr;
                    ptr->pre = nullptr;
                    delete ptr;
                    dim--;
                }
                else if(val==1){
                    Node<T> *ptr = this->head;
                    this->head = ptr->next;
                    ptr->next->pre = nullptr;
                    ptr->next=nullptr;
                    ptr->pre=nullptr;
                    delete ptr;
                    dim--;
                }
                else if(val==dim){
                    Node<T> *ptr = this->tail;
                    this->tail = ptr->pre;
                    this->tail->next = nullptr;
                    ptr->next=nullptr;
                    ptr->pre=nullptr;
                    dim--;
                    delete ptr;
                }
            }
        
            if(tipo=="valore"){ //Potrebbe ottimizzarsi, rimuove il valore che contiene il valore val
                Node<T> *ptr = this->head;
                for(int i=0; i<dim && ptr->val != val; i++){
                    ptr = ptr->getNext();
                }
                if(ptr->val != val){
                    cerr << "Il valore da lei inserito non è presente all'interno della lista";
                    exit(3);
                }
                if(this->head != ptr && this->tail != ptr){
                    Node<T> *ctr = ptr->getPre();
                    Node<T> *k = ptr->getNext();
                    ctr->next = ptr->getNext();
                    k->pre = ctr;
                    ptr->next = nullptr;
                    ptr->pre = nullptr;
                    delete ptr;
                    dim--;
                }
                else if(this->head == ptr){
                    this->head = ptr->next;
                    ptr->next->pre = nullptr;
                    ptr->next=nullptr;
                    ptr->pre=nullptr;
                    delete ptr;
                    dim--;
                }
                else if(this->tail == ptr){
                    this->tail = ptr->pre;
                    this->tail->next = nullptr;
                    ptr->next=nullptr;
                    ptr->pre=nullptr;
                    dim--;
                    delete ptr;
                }

            }
        
        
        }

        friend ostream& operator <<(ostream& os, listdl<T>& obj){
            os << "*head= " << *obj.head << endl << "*tail= " <<*obj.tail<<"\n\n";
            Node<T> *ptr = obj.head;
            for(int i=0; ptr; i++){
                os << i+1 << ") " << *ptr <<endl;
                ptr = ptr->getNext();
            }
            return os;
        }


};