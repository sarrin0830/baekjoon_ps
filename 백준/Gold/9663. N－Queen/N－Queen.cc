#include<iostream>
using namespace std;
int n;
int sum = 0;
bool mp[15][15];

bool check(int x, int y) {
	for (int i = 1; i <= n; i++) {
		if (mp[x][i] || mp[i][y]) {
			return false;
		}
	}
	int k = 1;
	while (1) {
		if (x-k < 1 || y-k < 1) {
			break;
		}
		if (mp[x-k][y-k]) {
			return false;
		}
		k++;
	}
	k = 1;
	while (1) {
		if (x + k >n || y + k >n) {
			break;
		}
		if (mp[x + k][y + k]) {
			return false;
		}
		k++;
	}
	k = 1;
	while (1) {
		if (x + k > n || y - k < 1) {
			break;
		}
		if (mp[x + k][y - k]) {
			return false;
		}
		k++;
	}
	k = 1;
	while (1) {
		if (x - k <1 || y + k > n) {
			break;
		}
		if (mp[x - k][y + k]) {
			return false;
		}
		k++;
	}

	return true;

}
void chess(int x) {
	if (x == n+1) {
		sum++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check(x, i)) {
			mp[x][i] = true;
			chess(x + 1);
			mp[x][i] = false;
		}
	}
}


int main() {

	ios::sync_with_stdio();
	cin.tie();
	cin >> n;
	chess(1);
	cout << sum;

	return 0;
}