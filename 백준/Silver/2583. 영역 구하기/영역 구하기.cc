#include<iostream>
#include<vector>
#include<algorithm>
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
		if (nx <= 0 || ny <= 0 || nx >n || ny > m) {
			continue;
		}
		else if (mp[ny][nx] == 0&&!visited[ny][nx]) {
			sum++;
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	vector<int>v;
	int k, x1, y1,x2,y2;
	cin >> m >> n >>k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1;
		cin >> x2 >> y2; 
		for (int i = y1+1; i <=y2 ; i++) {
			for (int j = x1+1; j <= x2; j++) {
				mp[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			
			if (!visited[i][j]&&mp[i][j]==0) {
				sum = 1;
				visited[i][j] = true;
				dfs(i, j);
				v.push_back(sum);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}