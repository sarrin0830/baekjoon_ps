#include <iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
map<long long int, int>m;
void func(int a, int b, int cnt) {
    queue<long long int>q;
    q.push(a);
    while (!q.empty()) {

        if (q.front() > b) {
            q.pop();
            continue;
        }
        else if (q.front() == b) {
            cout << m[q.front()]+1;
            return;
        }
        long long int q1 = q.front() * 2;
        long long int q2 = q.front() * 10 + 1;
        if (m.find(q1) == m.end()) {
            q.push(q1);
            m[q1] = m[q.front()] + 1;
        }
        if (m.find(q2) == m.end()) {
            q.push(q2);
            m[q2] = m[q.front()] + 1;
        }
        q.pop();
    }
    cout << -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int a, b;
    cin >> a >> b;

    func(a, b,0);
    return 0;
}