#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int topology[32001];
bool visited[32001];
vector<int>vec[32001];

struct compare
{
    bool operator()(int& a, int& b) {
        return a > b;
    }
};

void func() {
    vector<int>ans;
    priority_queue<int, vector<int>, compare>q;
    for (int i = 1; i <= n; i++) {
        if (topology[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.top();
        ans.push_back(cur);
        q.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            if (!visited[next]) {
                topology[next]--;
                if (topology[next] == 0) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        topology[b]++;

    }

    func();
    return 0;
}