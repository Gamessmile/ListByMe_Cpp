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

        void min(){
            if(isEmpty()){
                cerr << "Il bst é vuoto";
                exit(1);
            }
            cout << "L'elemento minimo nel'BST e': ";
            min(radice);
        }
        void min(BSTVer<T>* ptr){
            if(ptr->left){
                min(ptr->left); //Per definizione, il figlio sinistro é < del genitore, quindi la foglia dell'albero sinistro sará l'elemento minore
                return;
            }
            else{
                visit(ptr);
                return;
            }
        }
        
        void max(){
            if(isEmpty()){
                cerr << "Il bst é vuoto";
                exit(1);
            }
            cout << "L'elemento massimo nel'BST e': ";
            max(radice);
        }
        void max(BSTVer<T>* ptr){
            if(ptr->right){
                max(ptr->right);//Per definizione, il figlio destro é > del genitore, quindi la foglia dell'albero destro sará l'elemento maggiore
                return;
            }
            else{
                visit(ptr);
                return;
            }
        }

        void successor(BSTVer<T>* ptr){
            if(isEmpty()){
                cerr << "Il bst e' vuoto";
                exit(1);
            }
            if(ptr->right){
                min(ptr->right); //Il successore, é l'elemento piú piccolo del sotto albero destro (se esiste)
                return
            }
            //IN CASO CHE IL SUCCESSIVO ELEMENTO NON ESISTESSE
            //.:.Aspettando spiegazione Sara che discorso brutto e non mi va di capire per ora

        }
        



};

