#include<iostream>

class Node{

    public:
        Node* p;
        Node* left;
        Node* right;
        int value;

    public:

        Node(Node* P, Node* Left, Node* Right, int Value):
            p(P), left(Left), right(Right), value(Value){}

        Node(int Value):
            p(nullptr), left(nullptr), right(nullptr), value(Value){}

};


class BinaryTree{

    private:
        Node* root;

    public:
        BinaryTree(int value):
            root(new Node(value)){
            
        }

        BinaryTree():
            root(nullptr){

        }


        void InsertValue(int value){

            if(root == nullptr){
                root = new Node(value);
                return;
            }

            Node* before = nullptr;
            Node* dis = root;

            while(dis != nullptr){
                
                before = dis;

                if(value <= dis->value){
                    dis = dis->left;
                } else{
                    dis = dis->right;
                }
            }

            if(value <= dis->value){
                
            }


        }

};

int main(){

}