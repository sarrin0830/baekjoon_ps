#include<iostream>
using namespace std;
int main() {
	int sum = 0;
	int e, f, c;
	cin >> e >> f >> c;
	e = e + f;
	while (e >= c) {
		sum += e/c;
		e = e % c + e / c;
	}
	cout << sum;
	return 0;
}