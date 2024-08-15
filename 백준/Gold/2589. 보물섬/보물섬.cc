#include<iostream>
#include<queue>
using namespace std;
char mp[51][51];
int a, b;
int mx = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct pos {
	int x;
	int y;
	int len;
	pos(int x, int y, int len) {
		this->x = x;
		this->y = y;
		this->len = len;
	}
};
void bfs(int i, int j) {
	int maxValue = 0;
	bool visited[51][51] = { false, };
	queue<pos>q;
	visited[i][j] = true;
	q.push(pos(i, j, 0));
	while (!q.empty()) {
		if (q.front().len > maxValue) {
			maxValue = q.front().len;
		}
		for (int i = 0; i < 4; i++) {
			int nx = q.front().x + dx[i];
			int ny = q.front().y + dy[i];
			if (nx<1||ny<1||nx>a||ny>b||mp[nx][ny] == 'W') {
				continue;
			}
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(pos(nx, ny, q.front().len + 1));
			}
		}
		q.pop();
	}
	if (maxValue > mx) {
		mx = maxValue;
	}
}

int main() {
	ios::sync_with_stdio();
	cin.tie();
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (mp[i][j] == 'W') {
				continue;
			}
			else {
				bfs(i, j);
			}
		}
	}
	cout << mx;
	return 0;
}