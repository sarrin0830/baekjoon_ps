#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include<deque>
#include <queue>
#define ll long long int
#define INF 1000000001

using namespace std;
int n;
bool check;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int dir = 0;    //0 : 오른, 1 : 위, 2 : 왼, 3 : 아래
int ans = 0;
int mp[101][101];
deque<pair<int, int>>deq;

void printA() {
    for (int i = 0; i < deq.size(); i++) {
        mp[deq[i].first][deq[i].second] = 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
bool checkCrash(int x, int y) {
    for (int i = 0; i < deq.size(); i++) {
        if (deq[i].first == x && deq[i].second == y) {
            return true;
        }
    }
    return false;
}
void func(int x, char c) {
    pair<int, int>curP = deq.front();
    int nx = curP.first;
    int ny = curP.second;
    for (int i = 0; i < x; i++) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 1 || nx>n || ny<1 || ny>n || checkCrash(nx,ny)) {
            check = true;
            break;
        }
        deq.push_front({ nx,ny });
        if (mp[nx][ny] != 1) {
            mp[deq.back().first][deq.back().second] = 0;
            deq.pop_back();
        }

        ans++;
    }
    if (c == 'D') {
        dir = (dir + 3) % 4;
    }
    else {
        dir = (dir + 1) % 4;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int k, a, b, l, x;
    vector<pair<int, char>>vec;
    char c;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        mp[a][b] = 1;   //apple
    }
    cin >> l;
    deq.push_back({ 1,1 });

    cin >> x >> c;
    vec.push_back({ x,c });
    int bef = x;
    for (int i = 1; i < l; i++) {
        cin >> x >> c;
        vec.push_back({ x - bef,c });
        bef = x;
    }

    for (int i = 0; i < l; i++) {
        pair<int, char> cur = vec[i];

        if (check) {
            break;
        }
        func(cur.first, cur.second);
    }
    if (!check) {
        func(n, 'C');
    }
    cout << ans + 1;
    return 0;
}