#include<iostream>
using namespace std;
char mp[51][51];
int main() {
	int a = 0;
	int b = 0;
	int sum = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		bool check = false;
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'X') {
				check = true;
			}
		}
		if (!check) {
			a++;
		}
	}

	for (int i = 1; i <= m; i++) {
		bool check = false;
		for (int j = 1; j <= n; j++) {
			if (mp[j][i] == 'X') {
				check = true;
			}
		}
		if (!check) {
			b++;
		}
	}
	if (a > b) {
		cout << a;
	}
	else {
		cout << b;
	}

	return 0;
}