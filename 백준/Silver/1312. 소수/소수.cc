#include<iostream>
using namespace std;

int main() {
	int a, b, n,k;
	cin >> a >> b >> n;
	a = a % b;
	for (int i = 1; i < n; i++) {
		a = (a * 10) % b;
	}
	cout << (int)(a*10 / b);
	return 0;
}