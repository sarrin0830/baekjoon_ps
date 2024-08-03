#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio();
	cin.tie();
	bool check = false;
	string s;
	vector<int>v;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int k = 0;
		while (i < s.length()) {
			if (s[i] == '.') {
				
				break;
			}
			k++;
			i++;
			
		}
		if (k == 0) {
			v.push_back(-1);
			continue;
		}
		else if (k % 2 != 0) {
			check = true;
			break;
		}
		else {
			v.push_back(k);
			if (i == s.length()) {
				continue;
			}
			else {
				v.push_back(-1);
			}
		}
	}
	
	if (check) {
		cout << "-1";
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == -1) {
				cout << '.';
			}
			else {
				for (int j = 0; j < v[i] / 4; j++) {
					cout << "AAAA";
				}
				for (int j = 0; j < v[i] % 4; j++) {
					cout << "B";
				}
			}
		}
	}
}