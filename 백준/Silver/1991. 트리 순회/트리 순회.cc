#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	node* left;
	node* right;
	char value;
	node(char value) {
		this->value = value;
		left = right = NULL;
	}
};

class Tree {
public:
	Tree() {
		root = new node('A');
		nodeList.push_back(root);
	}
	void insert(char par, char left, char right) {
		node* parNode = findNode(par);
		if (parNode == NULL) {
			parNode = new node(par);
			nodeList.push_back(parNode);
		}

		if (left == '.') {
			parNode->left = NULL;
		}
		else {
			node* leftNode = new node(left);
			parNode->left = leftNode;
			nodeList.push_back(leftNode);
		}
		
		if (right == '.') {
			parNode->right = NULL;
		}
		else {
			node* rightNode = new node(right);
			parNode->right = rightNode;
			nodeList.push_back(rightNode);
		}

		
	}
	void preOrder(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		cout << curNode->value;
		preOrder(curNode->left);
		preOrder(curNode->right);
	}
	void inOrder(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		inOrder(curNode->left);
		cout << curNode->value;
		inOrder(curNode->right);
	}
	void postOrder(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		postOrder(curNode->left);
		postOrder(curNode->right);
		cout << curNode->value;
	}
	node* getRoot() {
		return root;
	}
private:
	node* root;
	vector<node*>nodeList;
	node* findNode(char k) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == k) {
				return nodeList[i];
			}
		}
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	char par, left, right;
	Tree tr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> par >> left >> right;
		tr.insert(par, left, right);
	}
	tr.preOrder(tr.getRoot());
	cout << '\n';
	tr.inOrder(tr.getRoot());
	cout << '\n';
	tr.postOrder(tr.getRoot());

}