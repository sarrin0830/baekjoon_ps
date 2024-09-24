#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)<<' ';
	}
	return 0;
}