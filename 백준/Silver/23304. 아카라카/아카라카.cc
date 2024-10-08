#include<iostream>
#include<queue>
#include<algorithm>
#include<vector> 
#define ll long long int
using namespace std;
bool check;

void func(string s) {
	if (s.length() <= 1) {
		return;
	}
	if (check) {
		return;
	}
	int st = 0;
	int ed = s.length() - 1;
	
	string s1 = "";
	string s2 = "";
	while (st < ed) {
		s1 += s[st];
		s2 += s[ed];
		if (s[st] != s[ed]) {
			check = true;
			return;
		}
		
		st++;
		ed--;
	}
	func(s1);
	func(s2);

}


int main() {
	string s;
	cin >> s;
	func(s);
	if (check) {
		cout << "IPSELENTI";
	}
	else {
		cout << "AKARAKA";
	}
	return 0;
}
