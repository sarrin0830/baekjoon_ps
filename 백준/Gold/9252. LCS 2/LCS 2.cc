#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dp[1001][1001];
vector<char>ans;
int mx = -1;
int dx, dy;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int x = s1.length();
    int y = s2.length();
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x - 1][y]) {
            x--;
        }
        else if (dp[x][y] == dp[x][y - 1]) {
            y--;
        }
        else {
            ans.push_back(s1[x-1]);
            x--;
            y--;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[ans.size()-1-i];
    }

    return 0;
}