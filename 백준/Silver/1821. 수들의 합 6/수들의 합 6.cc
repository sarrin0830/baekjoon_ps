#include<iostream>
#include<vector>
using namespace std;
int n, f;
long long int mul[11];
bool check = false;
bool visited[11];
void func(vector<int> v,int siz) {
	if (check) {
		return;
	}
	if (siz == n) {
		if (v.size() != n) {
			return;
		}
		long long int sum = 0;
		for (int i = 0; i <= n - 1; i++) {
			sum += mul[i] * v[i];
		}
		if (sum == f) {
			for (int i = 0; i < n; i++) {
				cout << v[i]<<" ";
			}
			check = true;
			return;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				continue;
			}
			else {
				visited[i] = true;
				v.push_back(i);
				func(v, siz+1);
				visited[i] = false;
				v.pop_back();
			}
		}
	}
}
long long int combination(int a, int b) {
	long long int sum = 1;
	if (b > a / 2) {
		b = a - b;
	}
	for (int i = a; i >= a - b + 1; i--) {
		sum *= i;
	}
	for (int i = 1; i <= b; i++) {
		sum /= i;
	}
	return sum;
}
void setting() {
	
	for (int i = 0; i <= n; i++) {
		long long int sum = 0;
		mul[i] = combination(n-1, i);
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	cin >> n>>f;
	vector<int>v;
	setting();
	func(v,0);
	return 0;
}