#include <iostream>

using namespace std;

template<class T>
class BSTVer{

    private:
        T val;
        BSTVer<T>*gen;
        BSTVer<T>*left;
        BSTVer<T>*right;
        template<class U>
        friend class BST;
    public:
        BSTVer(T val){
            this->val=val;
            this->gen=nullptr;
            this->left=nullptr;
            this->right=nullptr;
        }

        friend ostream& operator <<(ostream& os, BSTVer<T>& obj){
            os << "Val= " << obj.val << " ";
            return os;
        }
        

};
