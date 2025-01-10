#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>vec;
bool mp[1000001];
int dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mx = 0;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        vec.push_back(k);
        if (mx < k) {
            mx = k;
        }
        mp[k] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = vec[i] * 2; j <= mx; j += vec[i]) {
            if (mp[j]) {
                dp[j]--;
                dp[vec[i]]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp[vec[i]] << ' ';
    }
    return 0;
}