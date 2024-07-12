#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
bool a[1500001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int>deq;
	int n;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1) {
			cin >> y;
			deq.push_front(y);
		}
		else if (x == 2) {
			cin >> y;
			deq.push_back(y);
		}
		else if (x == 3) {
			if (deq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if (x == 4) {
			if (deq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if (x == 5) {
			cout << deq.size() << '\n';
		}
		else if (x == 6) {
			if (deq.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (x == 7) {
			if (deq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << deq.front() << '\n';
			}
		}
		else {
			if (deq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << deq.back() << '\n';
			}
		}
	}
}