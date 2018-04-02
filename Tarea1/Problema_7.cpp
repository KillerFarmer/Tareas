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


    int Size() const{
        return size;

    }

    void Print() const{

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

    int GethDepth(Node* node){

        Node* finding = root;

        if(finding == nullptr){
            return -2;
        }


        for(int i = 0; node != nullptr; i++){

            if(node == finding){
                return i;

            } else if(node->value <= finding->value){
                finding = finding->left;
            } else{
                finding = finding->right;
            }

        }

        return -1;
    }
    
    Node* Root(){
        return root;
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

        Node* node = GetNode(value);
        
        if(node == nullptr){
            std::cout << node->value << " is not in the Binary Tree" << std::endl;
            return 0;
        }
        int min;
        

        if(node == root){

            if(node->right == nullptr){
                min = value;

            } else{
                min = SearchMinimum(node->right);

            }

        } else if(node->right != nullptr){
            min = SearchMinimum(node->right);

        } else{

            Node* rightSon = nullptr;
            
            
            while(node->p != nullptr  && node->p->right == node){
                rightSon = node;
                node = node->p;
            }

            std::cout << "Status: " << node->value << std::endl;

            if(node->p == nullptr){
                std::cout << value << " doesn't have succesor" << std::endl;
                min = -99999;

            } else {
                min = node->p->value;
            }
        

        }

        return min;

    }

    bool CompareWithRoot(Node* node){
        return node == root;
    }

private:
    
    void SearchByLevel(std::vector<LinkedList>& levels, Node* node, size_t depth){

        
        if(node != nullptr){
            
            if(depth + 1 > levels.size()){
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

static void FindValue(BinaryTree tree, int value){

    if(tree.FindValue(value)){
        std::cout << "The value " << value <<  " was found" << std::endl;
    } else{
        std::cout << "The value " << value <<  " was not found" << std::endl;

    }
}


static void CommonAncestor(BinaryTree& tree, int a, int b){

    Node* nodeA = tree.GetNode(a);
    Node* nodeB = tree.GetNode(b);

    if(nodeA == nullptr){
        std::cout << a << " is not in the Binary Tree";
        return;

    } else if(nodeB == nullptr){
        std::cout << a << " is not in the Binary Tree";
        return;

    } else if(tree.CompareWithRoot(nodeA)){

        std::cout << a << " is the root. So " << a << " is the ancestor of " << b << std::endl;
        return;

    } else if(tree.CompareWithRoot(nodeB)){
        std::cout << b << " is the root. So " << b << " is the ancestor of " << a << std::endl;
        return;
    }

    int depthA = tree.GethDepth(nodeA);

    // Searching A  

    Node* before = nullptr;
    Node* node = tree.Root();
    

    for(int i = 0; i <= depthA+1; i++){

        if((nodeA->value <= node->value && nodeB->value > node->value) || 
            (nodeB->value <= node->value && nodeA->value > node->value)){
             std::cout << node->value << " is the common ancestor of <" << nodeA->value << "> and <" << nodeB->value << "> \n";
            break;
        }

        if(node == nodeA){
            
            if(node->p != nullptr){
                std::cout << node->p->value << " is the common ancestor of <" << nodeA->value << "> and <" << nodeB->value << "> \n";
                break;
            }

            std::cout << nodeA->value << " is the most old ancestor of " << nodeB->value << std::endl;

        } else if(node == nodeB){

            if(node->p != nullptr){
                std::cout << node->p->value << " is the common ancestor of <" << nodeA->value << "> and <" << nodeB->value << "> \n";
                break;
            }

            std::cout << nodeB->value << " is the most old ancestor of " << nodeA->value << std::endl;
        }

        before = node;
        if(nodeA->value <= node->value){
            node = node->left;
        } else{
            node = node->right;
        }


    }
    
    




}

static bool CompareByLevel(Node* T, Node* t);

static void SubTree(BinaryTree& T, BinaryTree t){

    // Tronara con valores repetidos
    Node* root = T.GetNode(t.Root()->value);

    if(t.Root() == nullptr){
         std::cout << "T_2 is a subTree of T_1" << std::endl;
         return;
    }
    
    bool isSub = CompareByLevel(root, t.Root());

    if(isSub == true){
        std::cout << "T_2 is a subTree of T_1" << std::endl;

    } else{
        std::cout << "T_2 is not a subTree of T_1" << std::endl;
    }



}

static bool CompareByLevel(Node* T, Node* t){

    if(T == nullptr && t == nullptr){
        return true;

    } else if(t != nullptr){

        if(T == nullptr){
            return false;
        }

        bool c1 ,c2;
        if(t->value == T->value){

            c1 = CompareByLevel(T->left, t->left);
            c2 = CompareByLevel(T->right, t->right);

            if(!c1 || !c2){
                return false;
            }
            return true;

        } 
        return false;

    }
    return true;
}

int main(){

    /*
    BinaryTree tree(10);

    tree.InsertValue(8);
    tree.InsertValue(12);
    tree.InsertValue(9);
    tree.InsertValue(11);
    tree.InsertValue(20);
    tree.InsertValue(6);

    BinaryTree t2(10);
    t2.InsertValue(8);
    t2.InsertValue(6);
    t2.InsertValue(12);
    t2.InsertValue(21);
    */

    //SubTree(tree, t2);

    BinaryTree t1(50);
    t1.InsertValue(40);
    t1.InsertValue(30);
    t1.InsertValue(20);
    t1.InsertValue(10);
    t1.InsertValue(0);
    t1.InsertValue(60);
    t1.InsertValue(70);
    t1.InsertValue(80);
    t1.InsertValue(90);
    t1.InsertValue(100);
    t1.InsertValue(45);
    t1.InsertValue(55);
    t1.InsertValue(35);
    t1.InsertValue(65);

    std::cout << "----------" << std::endl;
    t1.PrintByLevel();
    std::cout << "----------" << std::endl;

    BinaryTree t2(60);
    t2.InsertValue(70);
    t2.InsertValue(80);
    t2.InsertValue(90);
    t2.InsertValue(100);
    t2.InsertValue(110);

    

    std::cout << "----------" << std::endl;
    t2.PrintByLevel();
    std::cout << "----------" << std::endl;
    
    SubTree(t1, t2);

}