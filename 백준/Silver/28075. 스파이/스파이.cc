#include<iostream>
using namespace std;
int n,m;
int a[2][3];
int sum;
void f( int place, int s,int day) {
	
	if (day == n) {
		if (s >= m) {
			sum++;
		}
		return;
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (place == j) {
					f(j, s +( a[i][j]/2), day + 1);
				}
				else {
					f(j, s + a[i][j], day + 1);
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			f(j,a[i][j],1);
		}
	}
	cout << sum;
	return 0;
}