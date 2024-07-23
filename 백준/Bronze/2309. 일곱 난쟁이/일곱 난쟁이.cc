#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	bool check = false;
	int x, y;
	int a[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - a[i] - a[j]==100) {
				x = i;
				y = j;
				check = true;
				break;
			}
		}
		if (check == true) {
			break;
		}

	}
	for (int i = 0; i < 9; i++) {
		if (i == x || i == y) {
			continue;
		}
		else {
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}


	return 0;
}