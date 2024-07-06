#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k=3;
	for (int i = 1; i < n; i++) {
		k = 2*k - 1;
	}
	cout << k * k;
	return 0;
}