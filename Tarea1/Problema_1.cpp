#include<iostream>
#include<vector>

struct Node{

    Node* p;
    Node* left;
    Node* right;
    int value;

    Node():
        p(nullptr), left(nullptr), right(nullptr), value(-99999){

    }

    Node(int Value):
        p(nullptr), left(nullptr), right(nullptr), value(Value){

    }

    Node(Node* P, Node* Left, Node* Right, int Value):
        p(P), left(Left), right(Right), value(Value){

    }

};

class AVLTree{

private:
    Node* root;

public:
    AVLTree(int value):
        root(new Node(value)){

    }

    void InsertValue(int value){

        if (root == nullptr){
            root = new Node(value);
        }

        Node* before = nullptr;
        Node* thiss = root;

        while(thiss != nullptr){

            before = thiss;

            if(value <= thiss->value){
                thiss = thiss->left;
            } else{
                thiss = thiss->right;
            }
        }

        Node* check;

        if(value <= before->value){
            before->left = new Node(before, nullptr, nullptr, value);
            check = before->left;

        } else{
            before->right = new Node(before, nullptr, nullptr, value);
            check = before->right;
        }

        
        while(check != nullptr){
            
            int l = GetHeight(check->left);
            int r = GetHeight(check->right);
            int bal = r - l;

            if(bal < -1 || bal > 1){

                if(bal > 0){

                    if(CheckingBalance(check->right) > 0){

                        TurnLeft(check);
                    } else{
                        TurnRight(check->right);
                        TurnLeft(check);
                    }

                } else{

                    if(CheckingBalance(check->left) > 0){
                        TurnLeft(check->left);
                        TurnRight(check);

                    } else{
                        TurnRight(check);
                    }
                }



            }
            check = check->p;

        }

    }

private:

    int GetHeight(Node* node){

        if(node != nullptr){

            int l = GetHeight(node->left);
            int r = GetHeight(node->right);

            if(l > r){
                return l+1;
            } else{
                return r+1;
            }
            

        }
        return 0;

    }


    void TurnRight(Node* node){

        if(node == root){
            root = node->left;
        }

        Node* temp = node->left->right;
        Node* p = node->p;
        Node* left = node->left;


        if(p != nullptr){

            bool dir = false;

            if(node == p->right){
                dir = true;
            }

            if(dir){
                p->right = node->left;
            } else{
                p->left = node->left;
            }
        }

        node->left->p = p;
        node->left->right = node;
        node->p = node->left;
        node->left = temp;

        if(temp != nullptr){
            temp->p = node;
        }
    }

    void TurnLeft(Node* node){

        if(node == root){
            root = node->right;
        }

        Node* temp = node->right->left;
        Node* p = node->p;
        Node* right = node->right;


        if(p != nullptr){
            bool dir = false;

            if(node == node->right){
                dir = true;
            }

            if(dir){
                p->right = node->right;
            } else{
                p->left = node->right;
            }
        }

        node->right->p = p;
        node->right->left = node;
        node->p = node->right;
        node->right = temp;

        if(temp != nullptr){
            temp->p = node;
        }


    }

    int CheckingBalance(Node* node){

        int l = 0;
        int r = 0;
        if(node->left != nullptr){
            l = GetHeight(node->left);
        }

        if(node->right != nullptr){
            r = GetHeight(node->right);
        }
        
        return r - l;

       
    }

};