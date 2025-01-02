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
int v, e;
int eSum;
int vertex[10001];
struct pos {
    int v1;
    int v2;
    int weight;
    pos(int v1, int v2, int weight) {
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }
};
bool comp(pos a, pos b) {
    return a.weight < b.weight;
}
vector<pos> q;

int find(int x) {
    if (vertex[x] == x) {
        return x;
    }
    else {
        return vertex[x] = find(vertex[x]);
    }
}
void kruskal() {
    int ans = 0;
    int idx = 0;
    while (eSum != v - 1) {
        pos curP = q[idx];
        idx++;
        int curV1 = find(curP.v1);
        int curV2 = find(curP.v2);
        int curWeight = curP.weight;
        if (curV1 != curV2) {
            eSum++;
            ans += curWeight;
            if (curV1> curV2) {
                vertex[curV1] = curV2;
            }
            else {
                vertex[curV2] = curV1;
            }
        }
    }
    cout << ans;
}

int main() {
    int a, b;
    int c;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        q.push_back(pos(a, b, c));
    }
    for (int i = 1; i <= v; i++) {
        vertex[i] = i;
    }
    sort(q.begin(), q.end(), comp);
    kruskal();
    return 0;
}