#include<iostream>
#include<algorithm>
#include<queue>
#define INF 10000001
using namespace std;
int n,m;
int mp[101][101];
 
void func() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			for (int k = 1; k <= n; k++) {
				if (k == j) {
					continue;
				}
				if (mp[k][j] > mp[k][i] + mp[i][j]) {
					mp[k][j] = mp[k][i] + mp[i][j];
				}
				
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << mp[i][j] << " ";
			}
		}
		cout << '\n';
	}
}


int main() {
	ios::sync_with_stdio();
	cin.tie();
	int x, y, d;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mp[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++) {
		cin >> x >> y >> d;
		if (mp[x][y] > d) {
			mp[x][y] = d;
		}
		
	}
	func();


	return 0;
}