#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

#define ll long long int
#define INF 1000000001

using namespace std;
bool visited[501];
vector<int>vec[501];
int n, m;
bool check;
void dfs(int k,int bef) {
    for (int i = 0; i < vec[k].size(); i++) {
        int cur = vec[k][i];
        if (visited[cur]) {
            if (bef != cur) {
                check = true;
            }
        }
        else {
            visited[cur] = true;
            dfs(cur,k);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int s, e, cnt;
    int T = 1;
    while (1) {
        cnt = 0;

        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            vec[i].clear();

        }
        for (int i = 0; i < m; i++) {
            cin >> s >> e;
            vec[s].push_back(e);
            vec[e].push_back(s);
        }
        for (int i = 1; i <= n; i++) {
            check = false;
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            dfs(i,-1);
            if (!check) {
                cnt++;
            }
        }
        cout << "Case " << T << ": ";
        if (cnt == 1) {
            cout << "There is one tree.\n";
        }
        else if (cnt > 1) {
            cout << "A forest of " << cnt << " trees.\n";
        }
        else {
            cout << "No trees.\n";
        }
        T++;
    }
    return 0;
}