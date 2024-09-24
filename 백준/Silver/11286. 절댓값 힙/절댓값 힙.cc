#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct comp {
	bool operator() (int a, int b){
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	priority_queue<int,vector<int>,comp> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
				continue;
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}


	return 0;
}