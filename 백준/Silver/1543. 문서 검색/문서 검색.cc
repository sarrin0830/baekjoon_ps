#include<iostream>
#include<string>
using namespace std;
string s1, s2;
int mx = 0;
int len;
void func(int start, int sum) {
	if (len > s1.length() - start) {
		if (mx < sum) {
			mx = sum;
		}
	}
	else {
		if (s1.substr(start, len) == s2) {
			func(start + len, sum + 1);
		}
		else {
			func(start + 1, sum);
		}
	}
}
int main() {
	ios::sync_with_stdio();
	cin.tie();
	getline(cin, s1);
	getline(cin, s2);
	len = s2.length();
	func(0, 0);
	cout << mx;
}