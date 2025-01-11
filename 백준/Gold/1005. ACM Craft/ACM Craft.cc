#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[1001];
int topology[1001];
int dp[1001];
int mp[1001];
vector<int>vec[1001];

int n, k;

void func(int k) {
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (topology[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int temp = q.front();
        if (temp == k) {
            cout << dp[k] << '\n';
            break;
        }
        q.pop();
        for (int i = 0; i < vec[temp].size(); i++) {
            int cur = vec[temp][i];
            if (!visited[cur]) {
                topology[cur]--;
                dp[cur] = max(dp[cur], mp[cur] + dp[temp]);
                if (topology[cur] == 0) {
                    q.push(cur);
                    visited[cur] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t,x,y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;

        for (int j = 1; j <= n; j++) {
            visited[j] = false;
            topology[j] = 0;
            vec[j].clear();
            cin >> x;
            mp[j] = x;
            dp[j] = x;
        }
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            vec[x].push_back(y);
            topology[y]++;
        }
        cin >> k;
        func(k);
    }



    return 0;
}