#include<iostream>
#include<queue>
#include<algorithm>
#include<vector> 
#define ll long long int
using namespace std;

ll gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (a > b) {
		return gcd(b, a);
	}
	else {
		return gcd(b % a, a);
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	ll k = gcd(a, b);
	cout << k << '\n' << a * b / k;

	return 0;
}