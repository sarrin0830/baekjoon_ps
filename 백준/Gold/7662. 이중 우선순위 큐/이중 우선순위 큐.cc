#include<iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;

int main() {
	int T, k,n;
	char c;
	priority_queue<int, vector<int>, greater<int>> minQue;
	priority_queue<int, vector<int>, less<int>> maxQue;
	map<int, int>cnt;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;

		while (!minQue.empty()) {
			minQue.pop();
		}
		while (!maxQue.empty()) {
			maxQue.pop();
		}
		cnt.clear();
		for (int j = 0; j < k; j++) {
			
			cin >> c;
			if (c == 'I') {
				cin >> n;
				minQue.push(n);
				maxQue.push(n);
				cnt[n]++;
			}
			else if (c == 'D') {
				cin >> n;
				if (n == 1) {
					if (!maxQue.empty()) {
						cnt[maxQue.top()]--;
						maxQue.pop();
					}
				}
				else {
					if (!minQue.empty()) {
						cnt[minQue.top()]--;
						minQue.pop();
					}
				}
				while (!maxQue.empty()&&cnt[maxQue.top()]==0) {
					maxQue.pop();
				}
				while (!minQue.empty() && cnt[minQue.top()] == 0) {
					minQue.pop();
				}
			}
		}
		
		if (maxQue.empty()||minQue.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << maxQue.top() << " " << minQue.top()<<'\n';
		}
	}
}