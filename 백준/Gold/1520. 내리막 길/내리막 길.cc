#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
using namespace std;

int mp[501][501];
int dp[501][501];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int func(int a, int b) {
    if (a == m && b == n) {
        return 1;
    }
    else if (dp[a][b] != -1) {
        return dp[a][b];
    }

    dp[a][b] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx<1 || ny<1 || nx>m || ny>n) {
            continue;
        }
        else {
            if (mp[nx][ny] < mp[a][b]) {
                dp[a][b] += func(nx, ny);
            }
        }
    }
    return dp[a][b];

    
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            dp[i][j] = -1;
        }
    }
    cout<<func(1, 1);
    return 0;
} 