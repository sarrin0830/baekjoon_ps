#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int a, b, c,d;
	cin >> a >> b >> c;
	int k = a + b - c;
	d = b;
	int siz = 0;
	while (b != 0) {
		b /= 10;
		siz++;
	}
	int sum = a*pow(10, siz);
	sum = sum+d-c;
	cout << k << '\n' << sum;
}