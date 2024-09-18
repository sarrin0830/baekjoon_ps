#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 10000000001
using namespace std;
vector<long long int>mpVec[1001];
int n, m, s, e;
long long int mp[1001];
vector<pair<int, int>> v[1001];
bool visited[1001];
struct comp
{
	bool operator()(const long long int& a, const long long int& b) {
		return mp[a] > mp[b];
	}
};

void func() {
	priority_queue<long long int, vector<long long int>, comp> q;
	
	q.push(s);
	while (!q.empty()) {
		int num = q.top();
		q.pop();
		if (visited[num]) {
			continue;
		}
		visited[num] = true;
		mpVec[num].push_back(num);
		vector<long long int>curVec = mpVec[num];
		for (int i = 0; i < v[num].size(); i++) {
			int city = v[num][i].first;
			int dis = v[num][i].second;

			if (mp[city] > mp[num] + dis) {
				mp[city] = mp[num] + dis;
				mpVec[city] = curVec;
				q.push(city);
			}
		}
	}

}
int main() {
	ios::sync_with_stdio();
	cin.tie();

	cin >> n >> m;
	int x, y, d;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> d;
		v[x].push_back({ y,d });
	}
	for (int i = 1; i <= n; i++) {
		mp[i] = INF;
	}
	cin >> s >> e;
	mp[s] = 0;
	func();

	cout << mp[e] << '\n';
	cout << mpVec[e].size() << '\n';
	for (int i = 0; i < mpVec[e].size(); i++) {
		cout << mpVec[e][i] << " ";
	}
	return 0;
}