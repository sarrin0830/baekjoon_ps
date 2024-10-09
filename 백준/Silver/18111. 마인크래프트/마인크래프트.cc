#include<iostream>
#include<queue>
#include<algorithm>
#include<vector> 
#define ll long long int
using namespace std;

ll gd[501][501];
ll flr[257];
int main() {
	ll n, m, b;
	cin >> n >> m >> b;
	int mx = 0;
	ll sum = 0;
	int mim = 257;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> gd[i][j];
			flr[gd[i][j]]++;
			if (mx < gd[i][j]) {
				mx = gd[i][j];
			}
			if (mim > gd[i][j]) {
				mim = gd[i][j];
			}
		}
	}
	ll t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum += mx - gd[i][j];
		}
	}
	ll siz = n * m;
	int k = mx;
	int ans_t = 250000000;
	int ans_h = 0;

	while (1) {
		if (k == mim) {
			if (ans_t > t) {
				ans_t = t;
				ans_h = k;
			}
			else if (ans_t == t) {
				if (ans_h < k) {
					ans_h = k;
				}
			}
			break;
		}

		if (flr[k] == siz) {
			if (ans_t > t) {
				ans_t = t;
				ans_h = k;
			}
			else if (ans_t == t) {
				if (ans_h < k) {
					ans_h = k;
				}
			}
		}
		if (sum <= b) {
			
			if (ans_t > t + sum) {
				ans_t = t + sum;
				ans_h = k;
			}
			else if (ans_t == t + sum) {
				if (ans_h < k) {
					ans_h = k;
				}
			}

		}

		t += flr[k] * 2;
		sum -= (siz - flr[k]);
		b += flr[k];
		flr[k - 1] += flr[k];
		k--;

	}
	cout << ans_t << " " << ans_h;

}