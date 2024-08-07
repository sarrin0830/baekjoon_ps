#include<iostream>
using namespace std;
int n;
int paper[2200][2200];
int ans[3]; //0 : 1, 1: 2, 2 : 0
void func(int sx, int sy,int siz) {
	bool check = false;
	int k = paper[sy][sx];
	for (int i = sy; i < sy + siz; i++) {
		for (int j = sx; j < sx + siz; j++) {
			if (paper[i][j] != k) {
				check = true;
				break;
			}
		}
		if (check == true) {
			break;
		}
	}

	if (check != true) {
		ans[k + 1]++;
	}
	else {
		for (int i = sy; i < sy + siz; i+=siz/3) {
			for (int j = sx; j < sx + siz; j += siz / 3) {
				func(j, i, siz / 3);
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
			cin >> paper[i][j];
		}
	}
	func(1, 1, n);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}