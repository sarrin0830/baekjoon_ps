#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<string, int>m1, pair<string, int>m2) {
	if (m1.second == m2.second) {
		return m1.first > m2.first;
	}
	else {
		return m1.second < m2.second;
	}
	
}

int main() {
	int n;
	string s;
	map<string, int>m;
	vector < pair<string, int>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s]++;
	}
	for (auto k : m) {
		v.push_back({ k.first,k.second });
	}

	sort(v.begin(), v.end(), comp);
	cout << v.back().first;
	return 0;
}