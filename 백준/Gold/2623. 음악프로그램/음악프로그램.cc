#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int topology[1001];
bool visited[1001];
vector<int>vec[1001];

void func() {
    vector<int>ans;
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (topology[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
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
    if (ans.size() < n) {
        cout << 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k,bef;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cin >> k;
        bef = k;
        for (int j = 1; j < t; j++) {
            cin >> k;
            vec[bef].push_back(k);
            topology[k]++;
            bef = k;
        }
    }
    
    func();
    return 0;
}