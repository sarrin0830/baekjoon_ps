#include<iostream>
#include<vector>
using namespace std;
int m,n,s;
int mx = -1;
vector<int>v;
bool dp[51][1001];
void func() {
	if (s + v[0] <= m) {
		dp[0][s + v[0]] = true;
	}
	if (s - v[0] >= 0) {
		dp[0][s - v[0]] = true;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!dp[i - 1][j]) {
				continue;
			}
			else {
				if (j + v[i] <= m) {
					dp[i][j + v[i]] = true;
				}
				if (j - v[i] >= 0) {
					dp[i][j - v[i]] = true;
				}
			}
		}
	}
	for (int i = m; i >= 0; i--) {
		if (dp[n-1][i]) {
			mx = i;
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int x;
	
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	func();
	cout << mx;
}