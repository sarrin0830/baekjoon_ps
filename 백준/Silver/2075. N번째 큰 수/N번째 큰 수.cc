#include<iostream>
#include<queue>
#define MIN -1000000001
using namespace std;

priority_queue<int,vector<int>,greater<int>>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		cin >> x;
		q.push(x);
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (q.top() < x) {
				q.pop();
				q.push(x);
			}
		}
	}
	cout << q.top();
	return 0;
}