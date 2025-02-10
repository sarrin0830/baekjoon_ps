#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
#define INF 1000000001
using namespace std;
vector<pair<int,int>>vec;
int dp[501][501];
int n, r, c;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        vec.push_back({ r,c });
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[j][i+j] = INF;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + vec[j - 1].first * vec[k - 1].second * vec[i + j - 1].second);
            }
        }
    }
    cout << dp[1][n];
    return 0;
} 