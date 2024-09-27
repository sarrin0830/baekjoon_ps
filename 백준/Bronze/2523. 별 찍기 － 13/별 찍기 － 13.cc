#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		cout << '*';
	}
	cout << '\n';
	for (int i = n-2; i >=0; i--) {
		
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}