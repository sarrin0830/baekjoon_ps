#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,cnt;
vector<int>v;
bool visited[26][26];
char pic[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x,int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n||visited[nx][ny]||pic[nx][ny]=='0') {
			continue;
		}
		else {
			cnt++;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ansCount = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pic[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pic[i][j] == '1' && !visited[i][j]) {
				cnt = 1;
				ansCount++;
				dfs(i, j);
				
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ansCount << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}