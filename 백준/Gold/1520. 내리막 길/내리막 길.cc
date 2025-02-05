#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
int m, n;
int mp[501][501];
int dp[501][501];
int dx[4]={1, -1, 0, 0};
int dy[4] = { 0,0,1,-1 };

int func(int x,int y) {
    if (x == m && y == n) {
        return 1;
    }
    else if (dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for(int i=0;i<4;i++){ 
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<1 || ny<1 || nx>m || ny>n) {
            continue;
        }
        else {
            if (mp[nx][ny] < mp[x][y]) {
                dp[x][y] = dp[x][y] + func(nx, ny);
            }
        }
    }
    return dp[x][y];
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
    cout << func(1, 1);
    return 0;
} 