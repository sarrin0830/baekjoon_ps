#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<int>vec[32001];
int topology[32001];
bool visited[32001];

void func() {
    queue<int>q;
    for (int i = 1; i <=n; i++) {
        if (topology[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
        
    }
    while (!q.empty()) {
        int k = q.front();
        cout << k << " ";
        q.pop();
        for (int i = 0; i < vec[k].size(); i++) {
            int cur = vec[k][i];
            if (!visited[cur]) {
                topology[cur]--;
                if (topology[cur] == 0) {
                    q.push(cur);
                    visited[cur] = true;
                }
            }
        }
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