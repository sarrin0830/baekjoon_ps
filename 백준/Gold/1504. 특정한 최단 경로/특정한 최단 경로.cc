#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define INF 200000001
using namespace std;
int n,e;
int u, v;
int endU, endV;
int depth[801];
struct compare
{
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
};
vector<pair<int,int>> mp[801];
priority_queue <pair<int, int>, vector<pair<int,int>>,compare> q;
void func() {
    for (int i = 1; i <= n; i++) {
        depth[i] = INF;
    }
    q.push({ 0,1 });
    while (!q.empty()) {
        int len = q.top().first;
        int next = q.top().second;
        q.pop();
        for (int i = 0; i < mp[next].size(); i++) {
            int cur = mp[next][i].first;
            int dist = mp[next][i].second;
            if (depth[cur] > dist + len) {
                depth[cur] = dist + len;
                q.push({ depth[cur],cur });
            }
        }
    }
    endU = depth[u];
    endV = depth[v];
}

int func1(int k,int end) {
    for (int i = 1; i <= n; i++) {
        depth[i] = INF;
    }
    q.push({ 0,k });
    while (!q.empty()) {
        int len = q.top().first;
        int next = q.top().second;
        q.pop();
        for (int i = 0; i < mp[next].size(); i++) {
            int cur = mp[next][i].first;
            int dist = mp[next][i].second;
            if (depth[cur] > dist + len) {
                depth[cur] = dist + len;
                q.push({ depth[cur],cur });
            }
        }
    }
    return depth[end];
}
int main() {
    int a, b, c;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        mp[a].push_back({ b,c });
        mp[b].push_back({ a,c });
    }
    cin >> u >> v;
    func();
    int uton = func1(u, n);
    int vton = func1(v, n);
    int uv = func1(u, v);
    long long int x = endU + uv + vton;
    long long int y = endV + uv + uton;
    long long int mx = INF;
    if (u == 1 && v == n||u==n&&v==1) {
        if (uv == INF) {
            cout << -1;
        }
        else {
            cout << uv;
        }
        return 0;
    }
    if (x <mx) {
        mx = x;
    }
    if (y < mx) {
        mx = y;
    }
    if (mx == INF) {
        cout << -1;
    }
    else {
        cout << mx;
    }
    return 0;
}