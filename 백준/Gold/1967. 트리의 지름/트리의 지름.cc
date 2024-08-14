#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool visited[10001];
int mx = 0;
struct node
{
	int num;
	int parPlus;
	node* myParNode;
	vector<pair<node*, int>>childList;
	node(int num) {
		this->num = num;
		myParNode = NULL;
		parPlus = 0;
	}
};

node* nodeList[10001] = { NULL, };
vector<node*>leafNode;
class Tree {
private:
	int siz;
	node* root;
	
public:
	Tree(int n) {
		siz = n;
		for (int i = 1; i <= n; i++) {
			nodeList[i] = new node(i);
		}
		root = nodeList[1];
	}
	void insert(int par, int child, int k) {
		node* parNode = nodeList[par];
		node* childNode = nodeList[child];

		childNode->myParNode = parNode;
		parNode->childList.push_back({ childNode, k });

		childNode->parPlus = k;
	}
	void dfs(node* curNode,int sum) {
		if (curNode == NULL) {
			mx = max(mx, sum);
			return;
		}
		else {
			for (int i = 0; i < curNode->childList.size(); i++) {
				pair<node*, int>curPair = curNode->childList[i];

				if (visited[curPair.first->num]) {
					continue;
				}
				visited[curPair.first->num] = true;
				dfs(curPair.first,curPair.second+sum);
			}
			if (curNode->childList.size() == 0) {
				dfs(NULL, sum);
			}
			node* newNode = curNode->myParNode;
			if (newNode == NULL) {
				dfs(NULL, sum);
				return;
			}

			if (!visited[newNode->num]) {
				visited[newNode->num] = true;
				dfs(newNode,curNode->parPlus + sum);
			}
			
		}
	}
};
void clearVisited(int n) {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int n, par, child, k;
	cin >> n;
	Tree tr(n);

	for (int i = 0; i < n-1; i++) {
		cin >> par >> child >> k;
		tr.insert(par, child, k);
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (nodeList[i]->childList.size() == 0) {
			visited[i] = true;
			tr.dfs(nodeList[i], 0);
		}
		clearVisited(n);
	}
	cout << mx;
	return 0;
}