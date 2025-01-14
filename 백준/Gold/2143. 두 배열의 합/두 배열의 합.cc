#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>a, b;
vector<int>aSum, bSum;
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long int ans = 0;
    int T, n, m,k;
    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a.push_back(k);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        b.push_back(k);
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur = a[i];
        aSum.push_back(cur);
        for (int j = i + 1; j < n; j++) {
            cur += a[j];
            aSum.push_back(cur);
        }
    }
    for (int i = 0; i < m; i++) {
        cur = b[i];
        bSum.push_back(cur);
        for (int j = i + 1; j < m; j++) {
            cur += b[j];
            bSum.push_back(cur);
        }
    }
    sort(bSum.begin(), bSum.end());

    for (int i = 0; i < aSum.size(); i++) {
        int curT = T - aSum[i];
        auto u = upper_bound(bSum.begin(), bSum.end(), curT);
        auto d = lower_bound(bSum.begin(), bSum.end(), curT);
        int k = u - d;
        ans += k;
    }
    cout << ans;
    return 0;
}