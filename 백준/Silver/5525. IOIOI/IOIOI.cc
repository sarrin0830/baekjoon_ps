#include <iostream>
#include <vector>
using namespace std;
int sum = 0;
vector<int> makeTable(string s) {
	int patternSize = s.length();
	vector<int> v(patternSize,0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = v[j - 1];

		}
		if (s[i] == s[j]) {
			v[i] = ++j;
		}
	}
	return v;

}

void kmp(string parent, string pattern) {
	int parentSize = parent.length();
	int patternSize = pattern.length();
	vector<int> pat = makeTable(pattern);
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = pat[j - 1];

		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				sum++;
				j = pat[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	int n,m;
	string s1 = "IOI";
	string s2;
	cin >> n >> m;
	cin >> s2;
	for (int i = 1; i < n; i++) {
		s1 +="OI";
	}

	kmp(s2, s1);
	cout << sum;



	return 0;
}