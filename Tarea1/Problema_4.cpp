#include<iostream>
#include<vector>
#include <stdlib.h> 
#include <time.h> 

struct Node {

	Node* p;
	std::vector<Node*> children;
	int value;

	Node() : p(nullptr), children(), value(-9999) {

	}

	Node(int Value, Node* P) :
		p(P), children(), value(Value) {

	}

};

class RandomAryTree {

private:
	Node * root;
	int limit;

public:

	RandomAryTree(int height, int Limit):
		root(new Node(1, nullptr)), limit(Limit){
		GenerateChildren(root, height);


	}

    bool isBinary(){

        if(root == nullptr){
            return true;

        } else if(root->children.size() == 0){
            return true;
        }

        return CheckingBinary(root);


    }

private:

	void GenerateChildren(Node* node, int height) {

		if (height != 0) {

			srand(time(NULL));

			int children = rand() % limit + 1;
			

			for (int i = 0; i < children; i++) {
                srand(time(NULL));
				int value = rand() % 100 + 1;
				node->children.push_back(new Node(value, node));
				GenerateChildren(node->children[i], height - 1);
			}

		}
	}

    
    bool CheckingBinary(Node* node){

        if(node->children.size() == 0){
            return true;

        } else if(node->children.size() > 2){
            return false;
        }

        bool check = true;

        for(int i = 0; i < node->children.size(); i++){

            check = check && CheckingBinary(node->children[i]);


        }
        return check;

    }


};

int main() {

	RandomAryTree tree(3,3);
    if(tree.isBinary()){
        std::cout << "This tree is binary" << std::endl;

    } else{

        std::cout << "This tree is not binary" << std::endl;
    }
	
}
