#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int mp[9][9];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[9][9];
int mx = 0;
int cnt;
void func(int x, int y) {
	queue<pair<int,int>>q;
	visited[x][y] = true;
	q.push({ x,y });
	cnt++;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) {
				continue;
			}
			else if (visited[nx][ny]||mp[nx][ny]!=0) {
				continue;
			}
			else {
				cnt++;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		q.pop();
	}
}

int main() {

	ios::sync_with_stdio();
	cin.tie();
	int aSiz = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) {
				aSiz++;
			}
		}
	}
	int siz = n * m;
	for (int i = 1; i <= siz-2; i++) {
		if (mp[(i - 1) / m + 1][(i - 1) % m + 1]) {
			continue;
		}
		for (int j = i + 1; j <= siz-1; j++) {
			if (mp[(j - 1) / m + 1][(j - 1) % m + 1]) {
				continue;
			}
			for (int k = j + 1; k <= siz; k++) {
				if (mp[(k - 1) / m + 1][(k - 1) % m + 1]) {
					continue;
				}
				else {

					mp[(i - 1) / m + 1][(i - 1) % m + 1] = 1;
					mp[(j - 1) / m + 1][(j - 1) % m + 1] = 1;
					mp[(k - 1) / m + 1][(k - 1) % m + 1] = 1;
					cnt = 0;
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							if (mp[i][j] == 2&&!visited[i][j]) {
								func(i, j);
							}
						}
					}
					cnt = siz - cnt-aSiz-3;
					if (mx < cnt) {
						mx = cnt;
					}

					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							visited[i][j] = false;
						}
					}
					mp[(i - 1) / m + 1][(i - 1) % m + 1] = 0;
					mp[(j - 1) / m + 1][(j - 1) % m + 1] = 0;
					mp[(k - 1) / m + 1][(k - 1) % m + 1] = 0;
				}

			}
		}
	}

	cout << mx;
	return 0;
}