#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 6000000001
using namespace std;
bool visited[20001];
int V, E, K;
long long int dist[20001];
vector<pair<int, int>>graph[20001];

struct cmp
{
	bool operator()(const int& a, const int& b) {
		return dist[a] > dist[b];
	}
};
void bfs() {
	priority_queue<int, vector<int>, cmp>q;
	dist[K] = 0;
	q.push(K);
	while (!q.empty()) {
		long long int cur = INF;
		int topNum = q.top();
		q.pop();
		if (visited[topNum]) {
			continue;
		}
		visited[topNum] = true;
		
		for (int i = 0; i < graph[topNum].size(); i++) {
			pair<int, int> pr = graph[topNum][i];

			if (dist[pr.first] > dist[topNum] + pr.second) {
				dist[pr.first] = dist[topNum] + pr.second;
			}

			if (visited[pr.first]) {
				continue;
			}
			else {
				q.push(pr.first);

			}
		}
	}

}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int u, v, w;
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	bfs();
	for (int i = 1; i <= V; i++) {
		if (!visited[i]) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}