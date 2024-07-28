#include<iostream>
using namespace std;
struct node
{
	node* left;
	node* right;
	int value;
	node(int value) {
		this->value = value;
		left = right = NULL;
	}
};

class BST {
private:
	node* root;
public:
	BST() {
		root = NULL;
	}
	void insert(int value) {
		node* newNode = new node(value);
		if (root == NULL) {
			root = newNode;
			return;
		}
		node* curNode = root;
		node* parNode =NULL;
		while (curNode != NULL) {
			parNode = curNode;
			if (value < curNode->value) {
				curNode = curNode->left;
			}
			else {
				curNode = curNode->right;
			}
		}
		if (value < parNode->value) {
			parNode->left = newNode;
		}
		else {
			parNode->right = newNode;
		}
	}
	void pastOrder(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		pastOrder(curNode->left);
		pastOrder(curNode->right);
		cout << curNode->value << '\n';
	}
	node* returnRoot() {
		return root;
	}
};

int main() {
	int x;
	BST bt;
	while (cin >> x) {
		bt.insert(x);
	}
	bt.pastOrder(bt.returnRoot());
	return 0;
}