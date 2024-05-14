#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, v;
bool visited[1001];
bool qvisited[1001];
vector<int> vec[1001];

void dfs(int k) {
	visited[k] = true;
	cout << k << " ";
	for (int i = 0; i < vec[k].size(); i++) {
		if (!visited[vec[k][i]]) {
			dfs(vec[k][i]);
		}
	}
}
void bfs(int k) {
	queue<int> q;
	q.push(k);
	qvisited[k] = true;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cout << a<< " ";
		for (int i = 0; i < vec[a].size(); i++) {
			if (!qvisited[vec[a][i]]) {
				q.push(vec[a][i]);
				qvisited[vec[a][i]] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (vec[i].empty()) {
			continue;
		}
		else {
			sort(vec[i].begin(), vec[i].end());
		}
	}

	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}