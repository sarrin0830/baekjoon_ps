#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sum = 0;
	int ans = 0;
	int l, r;
	vector<pair<int, int>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		v.push_back({ l,1 });
		v.push_back({ r,-1 });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		sum += v[i].second;
		if (sum > ans) {
			ans = sum;
		}
	}
	cout << ans;
	return 0;
}