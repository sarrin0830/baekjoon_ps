#include<iostream>
using namespace std;
int main() {
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	int sum = 0;
	int x = m;
	int ans = 0;
	if (m + T > M) {
		cout << -1;
		return 0;
	}
	while (sum != N) {
		if (x + T <= M) {
			sum++;
			x += T;
		}
		else {
			x -= R;
			if (x < m) {
				x = m;
			}
		}
		ans++;
	}
	cout << ans;

	return 0;
}