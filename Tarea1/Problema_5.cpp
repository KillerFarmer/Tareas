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

        if(root == nullptr){
            return false;

        }  else if(root->value == value){
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

    bool FindValue(int value, Node* node) const{

        if(root->value == value){
            node = root;
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
                node = finding;
                return true;
            }
        }

        return false;
    }  

    Node* GetNode(int value){

        if(root == nullptr){
            return nullptr;
            
        }  else if(root->value == value){
            return root;
        }

        Node* finding = root;

        while(finding != nullptr){

            if(value <= finding->value){
                finding = finding->left;
            } else{
                finding = finding->right;
            }

            if(finding != nullptr && finding->value == value){
                return finding;
            }
        }

        return nullptr;
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

    int Maximum(){
        if(root == nullptr){
            std::cout << "The Tree is empy" << std::endl;
            return -99999;
        }
        return SearchMaximum(root);
    }

    int Minimum(){
        
        if(root == nullptr){
            std::cout << "The Tree is empy" << std::endl;
            return -99999;
        }
        return SearchMinimum(root);
    }

    int Succesor(int value){
        /*
        Node* node;
        FindValue(value, node);
        int min;

        if(node == root){
            min = SearchMinimum(node->right);
        } else{

            while(node != nullptr && node->p->left != node){
                node = node->p;
            }

            if(node == nullptr){
                std::cout << value << " doesn't have succesor" << std::endl;
                return -99999;
            } else{
                return Minimum(node->right);
            }
            

        }
        */
        /*
        Node* node;
        FindValue(value, node);
        if(node == nullptr){
            std::cout << value << " is not in the Binary Tree" << std::endl;
        }
        int min;

        if(node == root){
            if(node->right == nullptr){
                min = value;
            } else{
                min = SearchMinimum(node->right);
            }
        } else{

            while(node != nullptr && node->p->left != node){
                node = node->p;
            }

            if(node == nullptr){
                std::cout << value << " doesn't have succesor" << std::endl;
                min = -99999;
            } else{
                min = SearchMinimum(node->right);
            }

        }

        return min;
        */

        Node* node = GetNode(value);
        
        

        if(node == nullptr){
            std::cout << node->value << " is not in the Binary Tree" << std::endl;
            return 0;
        }
        int min;
        

        if(node == root){

            if(node->right == nullptr){
                min = -99999;
                std::cout << node->value << " doens't have successor" << std::endl;

            } else{
                min = SearchMinimum(node->right);

            }

        } else if(node->right != nullptr){
            min = SearchMinimum(node->right);

        } else{

            Node* rightSon = nullptr;
            /*
            while(node != nullptr && node->p->right == node){
                rightSon = node;
                node = node->p;
            }

            if(node == nullptr){
                std::cout << value << " doesn't have succesor" << std::endl;
                return -99999;
                //min = -99999;

            } else if(rightSon == nullptr){

                if(node->p != nullptr){
                    min ==
                } else if(node->right != nullptr){
                    min = SearchMinimum(node->right);
                } else{
                    min = node->p->value;
                }
            }
            */
            
            while(node->p != nullptr  && node->p->right == node){
                rightSon = node;
                node = node->p;
            }

            if(node->p == nullptr){
                std::cout << value << " doesn't have succesor" << std::endl;
                min = -99999;
            } else {
                min = node->p->value;
            }
            /*
            if(node == nullptr){
                
                std::cout << value << " doesn't have succesor" << std::endl;
                return -99999;
                //min = -99999;

            } else{

                if(node->p == nullptr){
                    
                } else{
                    min = node->p->value;
                }
                
            } 
            */

        }

        return min;

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

    int SearchMaximum(Node* node){

        if(node != nullptr){
            Node* temp = node->right;
            if(node->right == nullptr){
                return node->value;
            }
            return SearchMaximum(node->right);
        } 

        //return node->value;
    }

    int SearchMinimum(Node* node){

        if(node != nullptr){
            if(node->left == nullptr){
                return node->value;
            }
            return SearchMaximum(node->left);

        } 
        return node->value;
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

    std::cout << "--------------" << std::endl;
    tree.PrintByLevel();
    std::cout << "--------------" << std::endl;

    std::cout << "The succesor of 6 is " << tree.Succesor(6) << std::endl;
    std::cout << "The succesor of 8 is " << tree.Succesor(8) << std::endl;
    std::cout << "The succesor of 9 is " << tree.Succesor(9) << std::endl;
    std::cout << "The succesor of 10 is " << tree.Succesor(10) << std::endl;
    std::cout << "The succesor of 11 is " << tree.Succesor(11) << std::endl;
    std::cout << "The succesor of 12 is " << tree.Succesor(12) << std::endl;
    std::cout << "The succesor of 20 is " << tree.Succesor(20) << std::endl;


    

    BinaryTree tree2(50);

    tree2.InsertValue(40);
    tree2.InsertValue(30);
    tree2.InsertValue(20);
    tree2.InsertValue(10);
    tree2.InsertValue(0);

    std::cout << "--------------" << std::endl;
    tree2.PrintByLevel(); 
    std::cout << "--------------" << std::endl;

    for(int v : {0, 10, 20, 30, 40, 50}){
        std::cout << "The succesor of " << v << " is " <<tree2.Succesor(v) << std::endl;;
    }


    tree2.InsertValue(60);
    tree2.InsertValue(70);
    tree2.InsertValue(80);
    tree2.InsertValue(90);
    tree2.InsertValue(100);

    std::cout << "--------------" << std::endl;
    tree2.PrintByLevel(); 
    std::cout << "--------------" << std::endl;

    for(int v : {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100}){
        std::cout << "The succesor of " << v << " is " <<tree2.Succesor(v) << std::endl;;
    }


    tree2.InsertValue(45);
    tree2.InsertValue(55);
    tree2.InsertValue(35);
    tree2.InsertValue(65);
    tree2.InsertValue(99);

    std::cout << "--------------" << std::endl;
    tree2.PrintByLevel(); 
    std::cout << "--------------" << std::endl;

    for(int v : {0, 10, 20, 30, 35, 40, 45, 50, 55, 60, 65, 70, 80, 90, 99, 100}){
        std::cout << "The succesor of " << v << " is " <<tree2.Succesor(v) << std::endl;;
    }

    


    std::cout << std::endl;

    //tree.PrintByLevel();
    

    


}