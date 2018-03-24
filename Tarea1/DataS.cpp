#include "DataS.h"

class Node {

public:
	Node* left;
	Node* right;
	Node* p;
	// Red -> 0
	// Black -> 1
	bool color;
	int value;

public:

	Node(Node* Left, Node* Right, Node* P, int Value):
		left(Left), right(Right), p(P), color(false), value(Value){

	}
};



class RBTree {

private:
	Node* root;

public:
	
	RBTree(int value): 
		root(new Node(nullptr, nullptr, nullptr, value)) {

	}


	void RBInsert(int z) {

		Node* y = nullptr;
		Node* x = root;


		while (x != nullptr) {

			y = x;

			if (z < x->value) {
				x = x->left;
			}
			else {
				x = x->right;
			}

		}

		Node* n = new Node(nullptr, nullptr, y, z);

		if (y == nullptr) {
			root = n;
		}
		else if(z < y->value) {
			y->left = n;
		}
		else {
			y->right = n;
		}

	}

};