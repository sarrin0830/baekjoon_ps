#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m;
bool dp[10001];
vector<int>v;
void func(vector<int> vec) {

	if (vec.size() == m) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (dp[v[i]]) {
			continue;
		}
		dp[v[i]] = true;
		vec.push_back(v[i]);
		func(vec);
		vec.pop_back();
		dp[v[i]] = false;
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<int>newV;
	func(newV);
}