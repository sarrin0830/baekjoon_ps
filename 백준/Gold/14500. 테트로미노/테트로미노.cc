#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n, m;
int mx = 0;
int box[502][502];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[502][502];
void dfs(int x, int y, int k,int sum) {
	if (k == 4) {
		if (sum > mx) {
			mx = sum;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > m || ny > n) {
			continue;
		}
		if (!visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(nx, ny, k + 1, sum + box[ny][nx]);
			visited[ny][nx] = false;
		}

	}
}
void tFunc(int x, int y, int k, int sum) {
	int a = sum;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		a += box[ny][nx];
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		a -= box[ny][nx];
		if (mx < a) {
			mx = a;
		}
		a += box[ny][nx];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> box[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = true;
			dfs(j, i,1,box[i][j]);
			visited[i][j] = false;
			tFunc(j, i, 1, box[i][j]);
		}
	}
	cout << mx;
}
