#include<iostream>
using namespace std;
char m[101][101];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m[i][j];
		}
	}
	int a=0, b=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (m[i][j - 1] == '.' && m[i][j] == '.') {
				a++;
				while (j <= n && m[i][j - 1] == '.') {
					j++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (m[j-1][i] == '.' && m[j][i] == '.') {
				b++;
				while (j <= n && m[j-1][i] == '.') {
					j++;
				}
			}
		}
	}
	cout << a << " " << b;
	return 0;
}