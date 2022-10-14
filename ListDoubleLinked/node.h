#include <iostream>

using namespace std;

template<class T>
class Node{
    private:
        Node<T> *next; //prossimo
        Node<T> *pre; //previous one / precedente
        T val;
        template<class U>
        friend class listdl;
    public:
        Node(T val){
            this->val = val;
            this->next = nullptr;
            this->pre = nullptr;
        }

        Node<T> *getNext(){
            return this->next;
        }
        Node<T> *getPre(){
            return this->pre;
        }

        friend ostream& operator << (ostream&os, const Node<T>& obj){
            os << "Valore: "<<obj.val;
            return os;
        }
};