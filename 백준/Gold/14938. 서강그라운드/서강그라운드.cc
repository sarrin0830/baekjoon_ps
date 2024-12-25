#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#define INF 1000001
using namespace std;
int n, m, r;
int mx;
int val[101];
int dist[101];
vector<pair<int, int>>v[101];

void func(int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q;
    q.push({ k,0 });

    while (!q.empty()) {
        int vol = q.top().first;
        int bet = q.top().second;
        q.pop();
        for (int i = 0; i < v[vol].size(); i++) {

            pair<int,int> next = v[vol][i];
            int nextVol = next.first;
            int nextDist = next.second;
            

            if (dist[nextVol] > nextDist + bet) {
                dist[nextVol] = nextDist + bet;
                q.push({ nextVol,dist[nextVol] });
            }
        }
        
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) {
            sum += val[i];
        }
    }
    if (sum > mx) {
        mx = sum;
    }
}

void distReset() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, l;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        v[a].push_back({ b,l });
        v[b].push_back({ a,l });
    }
    for (int i = 1; i <= n; i++) {
        distReset();
        dist[i] = 0;
        func(i);
    }
    cout << mx;
    return 0;
}