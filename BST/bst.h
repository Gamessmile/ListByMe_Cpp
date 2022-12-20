#include "vertice.h"
#include <iostream>

using namespace std;

template<class T>
class BST{
    private:
        BSTVer<T>* radice;

    public:
        BST(){
            this->radice=nullptr;
        }

        bool isEmpty(){
            return this->radice==nullptr;
        }

        void insert(T val){
            if(isEmpty()){
                this->radice = new BSTVer<T>(val);
                return;
            }
            else{
                insert(this->radice, val);
            }
        }

        void insert(BSTVer<T>* ptr, T val){
            if(ptr->left == nullptr && val <= ptr->val){
                ptr->left = new BSTVer<T>(val);
                ptr->left->gen = ptr;
                return;
            }
            else if(ptr->right == nullptr && val > ptr->val){
                ptr->right = new BSTVer<T>(val);
                ptr->right->gen = ptr;
                return;
            }
            //Abbiamo appena verificato che il puntatore in input abbia già figli
            //Dobbiamo adesso passare ai figli sottostanti in base al valore in
            //Input, lo facciamo tramite la ricorsione, rieseguiamo la funzione
            //Ma con ptr in input il figlio di quello vecchio che soddisfi le
            //Condizioni

            else if(val<= ptr->val){
                return insert(ptr->left, val);
            }
            else if(val> ptr->val){
                return insert(ptr->right, val);
            }
        }

        /*
        SPIEGAZIONE ALLA "AMMUZZO" DI MERDA HEYHEY
            Abbiamo tre tipi di visita, preorder, postorder, inorder:
                PreOrder, si prende: radice->si scorre fino a foglia sinistra(albero sinistro), poi presi "fratelli"
                    e rispettivi "figli" di essi sempre con logica "prima quello sinistro", poi albero destro 
                PostOrder, si prende: partendo dalla foglia più a sinistra dell'albero sinistro,
                    si prende il "fratello" e poi il genitore, per poi pian piano spostarsi nelle foglie
                    "destre" dell'albero sinistro, si applica la stessa logica nell'albero destro,
                    e in fine la radice.
                InOrder, visita ordinata, parte dall'elemento più piccolo a sinistra e si scorre fino al più
                    grande a destra.
        */

       void visit(){
            cout << "\nradice:" << *radice;
       }

        void visit(BSTVer<T>* ptr){
            cout << *ptr;
        }

        void PreOrder(){
            cout<<"Stampa del bst seguendo la visita 'PreOrder'" << endl;
            PreOrder(radice);
        }

        void PreOrder(BSTVer<T>* ptr){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            if(!ptr){
                return;
            }
            visit(ptr);    
            PreOrder(ptr->left);
            PreOrder(ptr->right);       
        }
};