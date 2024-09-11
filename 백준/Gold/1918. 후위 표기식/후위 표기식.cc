#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


void func(string s) {
	vector<char>v;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << s[i];
		}
		else if (s[i] == '*' || s[i] == '/') {
			while (!v.empty()&&(v.back()=='*'||v.back()=='/')&& v.back() != '(') {
				cout << v.back();
				v.pop_back();
			}
			v.push_back(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!v.empty()&&v.back()!='(') {
				cout << v.back();
				v.pop_back();
			}
			v.push_back(s[i]);
		}
		else if (s[i] == '(') {
			v.push_back(s[i]);
		}
		else if (s[i] == ')') {
			while (v.size()!=0&&v.back() != '(') {
				cout << v.back();
				v.pop_back();
			}
			v.pop_back();
		}
	}
	while (!v.empty()) {
		cout << v.back();
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio();
	cin.tie();
	string s;
	cin >> s;

	func(s);


	return 0;
}