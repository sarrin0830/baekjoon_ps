#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n;
	vector<long long int>v;
	long long int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += abs(v[i] - v[j]);
		}
	}
	cout << sum;
	return 0;
} 