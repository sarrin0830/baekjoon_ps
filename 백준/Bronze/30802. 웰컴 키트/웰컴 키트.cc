#include<iostream>
#include<cmath>
using namespace std;


int main() {
	int tSum = 0;

	int n,t,p;
	cin >> n;
	int a[6] = { 0, };
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		tSum += ceil((double)a[i] / t);
	}
	cout << tSum << '\n';
	cout << n / p << " " << n % p;
}