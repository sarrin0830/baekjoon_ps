#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 5000001
using namespace std;
struct edge
{
	int s;
	int e;
	int t;
	edge(int s, int e, int t) {
		this->s = s;
		this->e = e;
		this->t = t;
	}
};
int n, m, w;


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	int TC, s, e, t;
	cin >> TC;
	for (int test = 0; test < TC; test++) {
		cin >> n >> m >> w;
		vector<edge>v;
		int dp[501];
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			v.push_back(edge(s, e, t));
			v.push_back(edge(e, s, t));
		}

		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			v.push_back(edge(s, e, -t));
		}


		
		dp[1] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < v.size(); j++) {
				int start = v[j].s;
				int end = v[j].e;
				int dis = v[j].t;

				if (dp[start] == INF) {
					continue;
				}
				else {
					if (dp[end] > dp[start] + dis) {
						dp[end] = dp[start] + dis;
					}
				}
			}
		}
		bool recycle = false;
		for (int j = 0; j < v.size(); j++) {
			int start = v[j].s;
			int end = v[j].e;
			int dis = v[j].t;

			if (dp[start] == INF) {
				continue;
			}
			else {
				if (dp[end] > dp[start] + dis) {
					recycle = true;
					break;
				}
			}
		}


		if (recycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}