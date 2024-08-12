#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}
int main() {
	vector<pair<int,int>> v;
	vector<int> vec;
	int k;
	for (int i = 1; i <= 8; i++) {
		cin >> k;
		v.push_back({ k,i });
	}
	int sum = 0;
	sort(v.begin(), v.end(),comp);
	for (int i = 7; i >= 3; i--) {
		sum += v[i].first;
		vec.push_back(v[i].second);
	}
	sort(vec.begin(), vec.end());
	cout << sum<<'\n';
	for (int i = 0; i <5; i++) {
		cout << vec[i] << " ";
	}
}