#include<iostream>
#include<vector>
#include<deque>
using namespace std;
bool check[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, num;
	deque<int> curV;
	vector<int> newV;
	cin >> n;
	num = 1;
	for (int i = 0; i < n; i++) {
		cin >> k;
		curV.push_back(k);
	}
	while (curV.size() != 0) {
		if (check[num]) {
			if (newV.back() == num) {
				newV.pop_back();
				num++;
				break;
			}
			else {
				cout << "Sad";
				return 0;
			}
		}

		int x = curV[0];

		curV.pop_front();
		if (x == num) {
			num++;
			continue;
		}
		if (newV.size() != 0) {
			if (newV.back() > x) {
				newV.push_back(x);
				check[x] = true;
			}
			else {
				cout << "Sad";
				return 0;
			}
		}
		else {
			newV.push_back(x);
			check[x] = true;
		}

	}
	cout << "Nice";
	return 0;
}