#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio();
	cin.tie();
	int s = 1;
	int n;
	int e = 1;
	int ans = 0;
	int sum = 0;
	cin >> n;
	while (s <= n) {
		if (s == e) {
			sum = s;
		}
		if (sum == n) {
			ans++;
			sum -= s;
			s++;	
		}
		else if (sum > n) {
			sum -= s;
			s++;
		}
		else if (sum < n) {
			e++;
			sum += e;
		}
	}
	cout << ans;
	return 0;
}