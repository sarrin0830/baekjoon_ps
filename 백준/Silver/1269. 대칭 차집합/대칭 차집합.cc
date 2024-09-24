#include<iostream>
#include<queue>
#include<map>
using namespace std;

map<int, bool>mp1;
map<int, bool>mp2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m,x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		mp1[x] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		mp2[x] = true;
	}
	int sum = n + m;
	for (auto i :mp1) {
		if (mp2.find(i.first) != mp2.end()) {
			sum--;
		}
	}
	for (auto i : mp2) {
		if (mp1.find(i.first) != mp1.end()) {
			sum--;
		}
	}
	cout << sum;
	return 0;
}