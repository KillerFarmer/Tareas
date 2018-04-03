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


class LinkedList{

private:
    Node* root;
    int size;

public:

    LinkedList(int value):
        root(new Node(value)), size(1){
        
    }
    
    LinkedList():
        root(nullptr), size(0){

    }

    void InsertValue(int value){

        if(root == nullptr){
            root = new Node(value);
            size++;
            return;
        }

        Node* last = root;

        while(last->right != nullptr){

            last = last->right;
        }

        last->right = new Node(nullptr, last, nullptr, value);
        size++;
    }


    int Size(){
        return size;

    }

    void Print(){

        std::vector<int> values;
        values.reserve(size);
    
        Node* move = root;

        while(move != nullptr){
            values.push_back(move->value);
            move = move->right;
        }

        for(int i = 0; i < size; i++){
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;

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
            return;
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

        check = check->p;

        while(check != nullptr){
            
            int l = GetHeight(check->left);
            int r = GetHeight(check->right);
            int bal = r - l;

            bal = CheckingBalance(check);

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

                break;



            }
            check = check->p;

        }

    }

    void PrintByLevel(){

        std::vector<LinkedList> levels;

        if(root == nullptr){
            std::cout << "The tree is empty" << std::endl;
            return;
        }

        levels.push_back(LinkedList(root->value));

        SearchByLevel(levels, root->left, 1);
        SearchByLevel(levels, root->right, 1);
        std::cout << "Lel" << std::endl;
        for(int i = 0; i < levels.size(); i++){
            levels[i].Print();
        }
    }

private:
    // size_type: Importante
    void SearchByLevel(std::vector<LinkedList>& levels, Node* node, size_t depth){

        
        if(node != nullptr){
            
            if(depth + 1 > levels.size()){
                //levels.push_back(new LinkedList());
                
                levels.push_back(LinkedList());
            }

            levels[depth].InsertValue(node->value);

            SearchByLevel(levels, node->left, depth + 1);
            SearchByLevel(levels, node->right, depth + 1);

        }
    }

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
        Node* P = node->p;
        //Node* Left = node->left;


        if(P != nullptr){

            bool dir = false;

            if(node == P->right){
                dir = true;
            }

            if(dir){
                P->right = node->left;
            } else{
                P->left = node->left;
            }
        }

        node->left->p = P;
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
        Node* P = node->p;
        //Node* Right = node->right;


        if(P != nullptr){
            bool dir = false;

            if(node == P->right){
                dir = true;
            }

            if(dir){
                P->right = node->right;
            } else{
                P->left = node->right;
            }
        }

        node->right->p = P;
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



int main(){


    AVLTree tree(100);

    /*
	tree.InsertValue(2);
	tree.InsertValue(4);
    tree.InsertValue(5);
    tree.InsertValue(6);
    tree.InsertValue(7);
    tree.InsertValue(8);
    tree.InsertValue(9);
    */


    std::vector<int> list = {29,71,82,48,39,101,22,46, 17,3,20,25,10};

    for(int x : list){
        tree.InsertValue(x);
    }

    std::cout << "---------------" << std::endl;
    tree.PrintByLevel();
    std::cout << "---------------" << std::endl;

    AVLTree tree2(1);

    for(int x: {2, 3, 4, 5, 6}){
        tree2.InsertValue(x);
    }

    tree2.PrintByLevel();
	std::cin.get();
}