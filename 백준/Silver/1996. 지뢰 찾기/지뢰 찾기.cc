#include<iostream>
using namespace std;
int dp[1001][1001];
int n;
int dx[3] = { -1,0,1 };
int dy[3] = { -1,0,1 };
void func(int a, int b, int k) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x = dx[i] + a;
			int y = dy[j] + b;
			if (x <= 0 || y <= 0 || x > n || y > n||(i==1&&j==1)||(dp[x][y]==-1)) {
				continue;
			}
			else {
				dp[x][y] += k;
			}
		}
	}
}
int main() {
	
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c >= '1' && c <= '9') {
				dp[i][j] = -1;
				func(i, j, c-'0');
			}
			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] >= 10) {
				cout << 'M';
			}
			else if (dp[i][j] == -1) {
				cout << '*';
			}
			else {
				cout << dp[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}