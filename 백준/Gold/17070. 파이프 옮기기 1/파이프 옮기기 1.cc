#include<iostream>
#include <queue>
using namespace std;
int n;
// -> : 1, cross-> : 2, bottom -> : 3
struct pipe
{
	int x;
	int y;
	int direct;
	pipe(int x, int y, int direct) {
		this->x = x;
		this->y = y;
		this->direct = direct;
	}
};
int sum = 0;
int mp[17][17];
int dp[17][17];
void func(int x, int y, int p) {
	queue<pipe>q;
	q.push(pipe(x, y, p));
	dp[x][y] = 1;
	while (!q.empty()) {
		int dx = q.front().x;
		int dy = q.front().y;
		int pos = q.front().direct;
		q.pop();
		if (dx == n && dy == n) {
			sum++;
		}

		if (pos == 1) {
			int nx[2] = { dx,dx + 1 };
			int ny[2] = { dy + 1,dy + 1 };

			for (int i = 0; i < 2; i++) {
				if (nx[i] <= n && ny[i] <= n) {
					if (i == 0 && mp[nx[i]][ny[i]]==1) {
						continue;
					}
					else if (i == 1 && (mp[nx[i]][ny[i]] == 1 || mp[dx][ny[i]] == 1 || mp[nx[i]][dy] == 1)) {
						continue;
					}
					dp[nx[i]][ny[i]] += dp[dx][dy];
					q.push(pipe(nx[i], ny[i], i + 1));
				}
			}

		}
		else if (pos == 2) {
			int nx[3] = { dx,dx + 1,dx + 1 };
			int ny[3] = { dy + 1,dy + 1,dy };

			for (int i = 0; i < 3; i++) {
				if (nx[i] <= n && ny[i] <= n) {

					if ((i == 0||i==2) && (mp[nx[i]][ny[i]] == 1)) {
						continue;
					}
					else if (i == 1 && (mp[nx[i]][ny[i]] == 1 || mp[dx][ny[i]] == 1 || mp[nx[i]][dy] == 1)) {
						continue;
					}

					dp[nx[i]][ny[i]] += dp[dx][dy];
					q.push(pipe(nx[i], ny[i], i + 1));
				}
			}
		}
		else {
			int nx[2] = { dx + 1, dx+1 };
			int ny[2] = { dy + 1,dy };

			for (int i = 0; i < 2; i++) {
				if (nx[i] <= n && ny[i] <= n) {
					if (i == 1 && mp[nx[i]][ny[i]] == 1) {
						continue;
					}
					else if (i == 0 && (mp[nx[i]][ny[i]] == 1 || mp[dx][ny[i]] == 1 || mp[nx[i]][dy] == 1)) {
						continue;
					}
					
					dp[nx[i]][ny[i]] += dp[dx][dy];

					q.push(pipe(nx[i], ny[i], i+2));
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio();
	cin.tie();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
		}
	}
	func(1, 2, 1);
	cout << sum;


	return 0;
}