#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int dis[1001][1001];
int visited[1001];
bool ansCheck;

void resetVisit() {
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
	}
}
struct node
{
	int num;
	vector<node*>nextNode;

	node(int num) {
		this->num = num;
	}
};

class Tree {
private:
	node* nodeList[1001] = { NULL, };
public:
	Tree(int n) {
		for (int i = 0; i <= n; i++) {
			nodeList[i] = new node(i);
		}
	}
	void insert(int x, int y) {
		node* xNode = nodeList[x];
		node* yNode = nodeList[y];
		xNode->nextNode.push_back(yNode);
		yNode->nextNode.push_back(xNode);
	}


	void disNode(int x, int y,int sum) {
		if (x == y) {
			cout << sum << '\n';
			ansCheck = true;
			return;
		}
		else if (ansCheck) {
			return;
		}
		else {
			node* curNode = nodeList[x];
			for (int i = 0; i < curNode->nextNode.size(); i++) {
				int k = curNode->nextNode[i]->num;
				if (!visited[k]) {
					visited[k] = true;
					disNode(k, y, sum + dis[x][k]);
				}

			}
		}
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int x, y, d;

	vector<pair<int, int>> v;
	cin >> n >> m;

	Tree tr(n);

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> d;
		dis[x][y] = d;
		dis[y][x] = d;
		tr.insert(x, y);
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		ansCheck = false;
		visited[x] = true;
		tr.disNode(x, y,0);
		resetVisit();
	}

	return 0;
}