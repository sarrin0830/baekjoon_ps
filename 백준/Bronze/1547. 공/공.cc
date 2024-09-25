#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	int k = 1;
	int n, x,y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (k == x) {
			k = y;
			y = x;
			x = k;
		}
		else if (k == y) {
			k = x;
			x = y;
			y = k;
		}
	}
	cout << k;
	return 0;
}