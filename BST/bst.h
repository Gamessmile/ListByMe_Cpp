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

        void visit(){
            cout << "\nradice:" << *radice << endl;
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

        void PostOrder(){
            cout << "Stampa del bst seguendo la visita 'PostOrder'" << endl;
            PostOrder(radice);
        }

        void PostOrder(BSTVer<T>* ptr){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            if(!ptr){
                return;
            }  
            PostOrder(ptr->left);
            PostOrder(ptr->right);
            visit(ptr);
        }

        void InOrder(){
            cout << "Stampa del bst seguendo la visita 'InOrder'" << endl;
            InOrder(radice);
        }

        void InOrder(BSTVer<T>* ptr){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            if(!ptr){
                return;
            }  
            InOrder(ptr->left);
            visit(ptr);
            InOrder(ptr->right);
        }

        BSTVer<T>* min(){
            if(isEmpty()){
                cerr << "Il bst é vuoto";
                exit(1);
            }
            cout << "L'elemento minimo nel'BST e': ";
            return min(radice);
        }
        BSTVer<T>* min(BSTVer<T>* ptr){
            if(ptr->left){
                return min(ptr->left);//Per definizione, il figlio sinistro é < del genitore, quindi la foglia dell'albero sinistro sará l'elemento minore
            }
            else{
                visit(ptr);
                return ptr;
            }
        }
        
        BSTVer<T>* max(){
            if(isEmpty()){
                cerr << "Il bst é vuoto";
                exit(1);
            }
            cout << "L'elemento massimo nel'BST e': ";
            return max(radice);
        }
        BSTVer<T>* max(BSTVer<T>* ptr){
            if(ptr->right){
                return max(ptr->right);//Per definizione, il figlio destro é > del genitore, quindi la foglia dell'albero destro sará l'elemento maggiore
            }
            else{
                visit(ptr);
                return ptr;
            }
        }

        BSTVer<T>* successor(BSTVer<T>* ptr){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            if(ptr->right){
                return min(ptr->right); //Il successore, é l'elemento piú piccolo del sotto albero destro (se esiste)
            }
            //IN CASO CHE IL SUCCESSIVO ELEMENTO NON ESISTESSE
            //Si cerca il primo antenato che abbia come figlio sinistro il nodo stesso o un suo antenato.
            BSTVer<T>* dad = ptr->gen;
            while(ptr!=nullptr && ptr == dad->right){//Caso cui ptr é figlio destro, scorriamo
                ptr = dad;
                dad = dad->gen;
            }
            return dad;
        }

        BSTVer<T>* search(T input){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            return search(radice, input);
        }

        BSTVer<T>* search(BSTVer<T>* ptr, T input){

            if(ptr->val==input){
                return ptr;
            }

            if(ptr->val>input){
                return search(ptr->left, input);
            }

            if(ptr->val<input){
                return search(ptr->right, input);
            }

            return nullptr;

        }

        BSTVer<T>* remove(BSTVer<T>* ptr){
            //Caso 1, il nodo da eliminare é una foglia
            if(ptr->left==nullptr && ptr->right==nullptr){
                if(ptr == ptr->gen->left){//Vedere se é figlio sinitro
                    ptr->gen->left=nullptr;
                }
                else if(ptr == ptr->gen->right){//Vedere se é figlio destro
                    ptr->gen->right=nullptr;
                }
                return ptr;
            }

            //Caso 2, il nodo ha un figlio sinistro
            if(ptr->left && ptr->right==nullptr){
                if(ptr == ptr->gen->left){//Vedere se é figlio sinitro
                    ptr->gen->left=ptr->left;
                }
                else if(ptr == ptr->gen->right){//Vedere se é figlio destro
                    ptr->gen->right=ptr->left;
                }
                return ptr;
            }

            //Caso 3, il nodo ha un figlio destro
            if(ptr->left==nullptr && ptr->right){
                if(ptr == ptr->gen->left){//Vedere se é figlio sinitro
                    ptr->gen->left=ptr->right;
                }
                else if(ptr == ptr->gen->right){//Vedere se é figlio destro
                    ptr->gen->right=ptr->right;
                }
                return ptr;
            }
        return nullptr; 
        }

        BSTVer<T>* remove(T val){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }

            BSTVer<T>* ptr = search(val);
            if(ptr==nullptr){
                cerr << "Valore non presente nel bst";
                exit(2);
            }

            BSTVer<T>* rimuovere = remove(ptr);
            if(rimuovere){
                return rimuovere;
            }
            //Se remove é uguale a nullptr, vuol dire che non é stato rimosso, quindi non é nei casi della funzione precedente
            //Caso 3, il nodo ha sia figlio destro che figlio sinistro
            //Non potendo eliminare e quindi smontare il bst, andiamo a sostituire il nostro nodo con il suo successore
            BSTVer<T>* next = successor(ptr);

            T tmp = ptr->val;
            ptr->val=next->val;
            next->val=tmp;    
            //Adesso che abbiamo invertito il nostro nodo con il suo successore, proviamo a eliminalro dal suo nuovo posto
            rimuovere = remove(next);

        return rimuovere;
        }
        
};


