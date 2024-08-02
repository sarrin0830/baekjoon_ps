#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string ans;

int main() {
	ios::sync_with_stdio();
	cin.tie();
	string s;
	cin >> s;
	for (int i = 1; i < s.length() - 1; i++) {
		for (int j = i + 1; j < s.length(); j++) {
			string s1 = s.substr(0, i);
			string s2 = s.substr(i, j - i);
			string s3 = s.substr(j, s.length() - j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			string sumS = s1 + s2 + s3;
			if (ans == "" || ans > sumS) {
				ans = sumS;
			}
		}
	}
	cout << ans;
	return 0;
}