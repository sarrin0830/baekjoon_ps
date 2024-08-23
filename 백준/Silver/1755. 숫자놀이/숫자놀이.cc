#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<string, int>>v;
string number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

bool comp(pair<string, int>a, pair<string, int>b) {
	return a.first < b.first;
}

string func(int k) {
	string s = "";
	vector<int> vec;
	while (k != 0) {
		vec.push_back(k % 10);
		k /= 10;
	}
	for (int i = vec.size()-1; i >= 0; i--) {
		s += number[vec[i]];
	}
	return s;
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int m, n;
	cin >> m >> n;
	
	for (int i = m; i <= n; i++) {
		v.push_back({ func(i),i });
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " ";
		if ((i + 1) % 10 == 0) {
			cout << '\n';
		}
	}
}