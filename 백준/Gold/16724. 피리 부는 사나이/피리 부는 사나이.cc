#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define ll long long int 
using namespace std;
int n, m, sum;
bool check[1000001];
int dp[1000001];

int mov(char c, int k) {
    if (c == 'D') {
        return k + m;
    }
    else if (c == 'U') {
        return k - m;
    }
    else if (c == 'L') {
        return k - 1;
    }
    else {
        return k + 1;
    }
}

int func(int k, int bef) {
    if (dp[k] == bef) {
        check[k] = true;
        sum++;
        return k;
    }

    if (dp[k] == k || check[k]) {
        return k;
    }
    return dp[k] = func(dp[k], bef);
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> n >> m;

    for (int i = 1; i <= m * n; i++) {
        dp[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            char c = s[j];
            int curN = i * m + j + 1;
            dp[curN] = mov(c, curN);
            if (check[dp[curN]]) {
                continue;
            }
            int cur = func(dp[curN], curN);
        }
    }
    cout << sum;
    return 0;
}