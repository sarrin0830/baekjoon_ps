#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int cnt = 0;
bool compare(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}
struct node
{
	int num;
	node* parNode;
	vector<node*>childNode;
	
	node(int num) {
		this->num = num;
		parNode = NULL;
	}
};

class Tree {
private:
	node* root;
	node* nodeList[51] = { NULL, };
public:
	Tree(){
		root = NULL;
	}
	void resetNode() {
		for (int i = 0; i < n; i++) {
			nodeList[i] = new node(i);
		}
	}
	void insertRoot(int k) {
		node* curNode = nodeList[k];
		root = curNode;
		nodeList[k] = curNode;
	}
	void insert(int child,int par) {
		node* parNode = nodeList[par];
		node* chilNode = nodeList[child];
		parNode->childNode.push_back(chilNode);
		chilNode->parNode = parNode;
	}
	void erase(int del) {
		node* delNode = nodeList[del];
		node* parNode = delNode->parNode;
		if (parNode == NULL) {
			root = NULL;
			return;
		}
		else {
			
			for (int i = 0; i < parNode->childNode.size(); i++) {
				if (parNode->childNode[i]->num == del) {
					parNode->childNode.erase(parNode->childNode.begin() + i);
					break;
				}
			}
			
		}
	}

	node* returnRoot() {
		return root;
	}

	void checkCnt(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		if (curNode->childNode.size() == 0) {
			cnt++;
		}
		else {
			for (int i = 0; i < curNode->childNode.size(); i++) {
				checkCnt(curNode->childNode[i]);
			}

		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Tree tr;
	int x;
	
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back({ i,x });

	}
	tr.resetNode();
	sort(v.begin(), v.end(), compare);
	tr.insertRoot(v[0].first);

	for (int i = 1; i < n; i++) {
		tr.insert(v[i].first, v[i].second);
	}
	cin >> x;
	tr.erase(x);
	tr.checkCnt(tr.returnRoot());
	cout << cnt;
	return 0;
}