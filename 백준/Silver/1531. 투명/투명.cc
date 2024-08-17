#include<iostream>
using namespace std;
int main() {
	int dp[101][101] = { 0, };
	int n, m,x1,x2,y1,y2,ans=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				dp[j][k]++;
			}
		}
	}
	for (int i = 1; i <= 100;i++) {
		for (int j = 1; j <= 100; j++) {
			if (dp[i][j] > m) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}