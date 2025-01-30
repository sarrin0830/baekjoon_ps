#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <queue>
#define ll long long int
using namespace std;
vector<int>vec;

int n, k;
ll dp[10001];

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    int a;
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = vec[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - vec[i]];
        }
    }
    cout << dp[k];
    return 0;
} 