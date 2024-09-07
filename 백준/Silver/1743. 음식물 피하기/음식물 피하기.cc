#include<iostream>
using namespace std;
int n, m;
int mp[101][101];
bool visited[101][101];
int sum;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > m || ny > n) {
			continue;
		}
		else if (mp[ny][nx] == 1&&!visited[ny][nx]) {
			sum++;
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int mx = 0;
	int k, x, y;
	cin >> n >> m>>k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		mp[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
			if (!visited[i][j]&&mp[i][j]) {
				sum = 1;
				visited[i][j] = true;
				dfs(i, j);
				if (sum > mx) {
					mx = sum;
				}
			}
		}
	}
	cout << mx;
	return 0;
}