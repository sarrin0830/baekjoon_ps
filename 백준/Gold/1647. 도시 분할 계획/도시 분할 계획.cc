#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define ll long long int
using namespace std;
int n, m;
vector<pair<int, int>>vec[100001];
bool visited[100001];
struct compare
{
    bool operator()(pair<int, int>&a, pair<int, int>&b) {
        return a.second > b.second;
    }
};
void prim() {
    int mx = 0;
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        int curV = q.top().first;
        int curE = q.top().second;
        q.pop();
        if (!visited[curV]) {
            sum += curE;
            if (mx < curE) {
                mx = curE;
            }
            visited[curV] = true;
            for (int i = 0; i < vec[curV].size(); i++) {
                if (!visited[vec[curV][i].first]) {
                    q.push(vec[curV][i]);
                }
            }
        }
    }
    cout << sum-mx;
}

int main() {
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }
    prim();
    return 0;
}