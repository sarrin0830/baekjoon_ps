#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
long long int n, b;
long long int mp[6][6];

long long int ans[6][6];
void func(long long int a[6][6], long long int b[6][6]) {
    long long int dp[6][6] = { 0, };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j] += a[i][k] * b[k][j];
            }
            dp[i][j] %= 1000;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = dp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
        ans[i][i] = 1;
    }

    while (b) {
        if (b % 2 == 1) {
            func(ans, mp);
        }
        func(mp, mp);
        b /= 2;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}