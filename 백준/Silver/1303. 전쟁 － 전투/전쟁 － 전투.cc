#include<iostream>
using namespace std;

int n, m;
int sum;
int wSum;
int bSum;

bool visited[101][101];
char war[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x,char c) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || nx<1 || ny>m || nx>n) {
			continue;
		}
		else if (visited[ny][nx]) {
			continue;
		}
		else if(war[ny][nx]==c) {
			visited[ny][nx] = true;
			sum++;
			dfs(ny, nx,c);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> war[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				sum = 0;
				dfs(i, j,war[i][j]);
				if (sum == 0) {
					sum++;
				}
				if (war[i][j] == 'W') {
					wSum += sum * sum;
				}
				else {
					bSum += sum * sum;
				}
			}
		}
	}
	cout << wSum << " " << bSum;
	return 0;
}