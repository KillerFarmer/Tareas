#include<iostream>
#include<vector>

struct Node{

    Node* p;
    Node* left;
    Node* right;
    int value;


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



class BinaryTree{

private:
    Node* root;

public:

    BinaryTree(int value):
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

        if(value <= before->value){
            before->left = new Node(before, nullptr, nullptr, value);

        } else{
            before->right = new Node(before, nullptr, nullptr, value);
        }
 

    }

    bool FindValue(int value) const{

        if(root->value == value){
            return true;
        }

        Node* finding = root;

        while(finding != nullptr){

            if(value <= finding->value){
                finding = finding->left;
            } else{
                finding = finding->right;
            }

            if(finding != nullptr && finding->value == value){
                return true;
            }
        }

        return false;
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

};






void FindValue(BinaryTree tree, int value){

    if(tree.FindValue(value)){
        std::cout << "The value " << value <<  " was found" << std::endl;
    } else{
        std::cout << "The value " << value <<  " was not found" << std::endl;

    }
}

int main(){
    BinaryTree tree(10);

    

    tree.InsertValue(8);
    tree.InsertValue(12);
    tree.InsertValue(9);
    tree.InsertValue(11);
    tree.InsertValue(20);
    tree.InsertValue(6);

    FindValue(tree, 11);
    FindValue(tree, 10);
    FindValue(tree, 8);
    FindValue(tree, 20);
    FindValue(tree, 16);
    FindValue(tree, 0);
    FindValue(tree, 2);
    FindValue(tree, 200);

    std::cout << "------------" << std::endl;
    tree.PrintByLevel();
    std::cout << "------------" << std::endl;

    LinkedList list(1);
    list.InsertValue(2);
    list.InsertValue(3);
    list.InsertValue(4);
    list.InsertValue(5);
    list.InsertValue(6);
    list.Print();

    
}