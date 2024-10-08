#include<iostream>
#include<queue>
#include<algorithm>
#include<vector> 
#define ll long long int
using namespace std;
bool check[25][1001];
int n;
int ans;

void func(int k, int sum) {
	if (check[k][sum]) {
		return;
	}
	check[k][sum] = true;
	if (k == n + 1) {
			ans++;
	}
	else {
		func(k + 1, sum + 1);
		func(k + 1, sum + 5);
		func(k + 1, sum + 10);
		func(k + 1, sum + 50);
	}
}
int main() {


	cin >> n;
	func(1, 0);
	cout << ans;

	return 0;
}