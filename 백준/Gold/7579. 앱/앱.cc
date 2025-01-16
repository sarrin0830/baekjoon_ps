#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int sum;
int c[101];
int mem[101];
int dp[101][10001];
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    int k;
    for (int i = 1; i <= n; i++) {
        cin >> k;

        mem[i] = k;
    }

    for (int i = 1; i <= n; i++) {
        cin >> k;
        c[i] = k;
        sum += k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            int curMem = mem[i];
            int curApp = c[i];
            if (curApp <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curApp] + curMem);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int j = 0; j <= sum; j++) {
        if (dp[n][j] >= m) {
            cout << j;
            break;
        }
    }
    return 0;
}