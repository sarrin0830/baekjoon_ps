#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	vector<string> s[27];
	string newS;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> newS;
		s[newS[0] - 'a'+1].push_back(newS);
	}
	bool check = false;
	for (int i = 1; i <= 26; i++) {
		if (s[i].size() >= 5) {
			char c = i + 'a'-1;
			cout << c;
			check = true;
		}
	}
	if (!check) {
		cout << "PREDAJA";
	}



	return 0;
}