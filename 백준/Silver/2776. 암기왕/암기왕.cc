#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n, m, k;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        map<int, bool>mp;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> k;
            mp[k] = true;
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            if (mp[k]) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}