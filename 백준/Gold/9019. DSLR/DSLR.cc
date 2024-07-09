#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;

void bfs(int x, int y) {
	bool visited[10001] = { 0, };
	int xp[4] = { 0, };
	int k;
	queue<pair<int,string>> q;
	q.push({ x,"" });
	while (!q.empty()) {
		
		int num = q.front().first;
		string command = q.front().second;
		q.pop();
		if (num == y) {
			cout << command << '\n';
			return;
		}		
		int newNum;
		newNum = (num * 2) % 10000;	//1
		if (!visited[newNum]) {
			visited[newNum] = true;
			q.push({ newNum,command + 'D' });
		}
		/*---------------------*/
		
		newNum = (num +9999)%10000;	//2
		if (!visited[newNum]) {
			visited[newNum] = true;
			q.push({ newNum,command + 'S' });
		}
		/*---------------------*/
		k = num;					//3
		for (int i = 0; i < 4; i++) {
			xp[3 - i] = k % 10;
			k /= 10;
		}
		for (int i = 0; i < 4; i++) {
			k = k * 10 + xp[(i + 1) % 4];
		}
		
		newNum = k;
		if (!visited[newNum]) {
			visited[newNum] = true;
			q.push({ newNum,command + 'L' });
		}
		/*---------------------*/
		k = num;					//4
		for (int i = 0; i < 4; i++) {
			xp[3 - i] = k % 10;
			k /= 10;
		}
		for (int i = 0; i < 4; i++) {
			k = k * 10 + xp[(i + 3) % 4];
		}

		newNum = k;
		if (!visited[newNum]) {
			visited[newNum] = true;
			q.push({ newNum,command + 'R' });
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		bfs(x, y);
	}
}
