#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
int n, m;
int mim = 100;
int mp[10][10];
int dp[10][10];
vector<pair<int,int>>vec;

void func(int k) {
    if (k == vec.size()) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!dp[i][j]&&mp[i][j]==0) {
                    cnt++;
                }
            }
        }

        if (mim > cnt) {
            
            mim = cnt;
        }
        return;
    }

    pair<int, int> cur = vec[k];
    int x = cur.first;
    int y = cur.second;
    int curDp[9][9];

    if (mp[x][y] == 1) {
        int c = x;
        while (c <= n && mp[c][y]!=6) { //아래
            dp[c][y]++;
            c++;
        }
        func(k + 1);
        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }

        c = x;
        while (c >= 1 && mp[c][y] != 6) {   //위
            dp[c][y]++;
            c--;
        }
        func(k + 1);
        while (c <= x) {    //위
            dp[c][y]--;
            c++;
        }

        c = y;
        while (c >= 1 && mp[x][c] != 6) {   //왼
            dp[x][c]++;
            c--;
        }
        func(k + 1);
        while (c <= y) {    //왼
            dp[x][c]--;
            c++;
        }
        
        c = y;
        while (c <= m && mp[x][c] != 6) {   //오른
            dp[x][c]++;
            c++;
        }
        func(k + 1);
        while (c >= y) {    //오른
            dp[x][c]--;
            c--;
        }

    }
    else if (mp[x][y] == 2) {

        int c = x;
        int d = x;
        while (c <= n && mp[c][y] != 6) {   //아래
            dp[c][y]++;
            c++;
        }
        while (d >= 1 && mp[d][y] != 6) {   //위
            dp[d][y]++;
            d--;
        }
        func(k + 1);
        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }
        while (d <= x) {    //위
            dp[d][y]--;
            d++;
        }

        c = y;
        d = y;
        while (c <= m && mp[x][c] != 6) {   //오른
            dp[x][c]++;
            c++;
        }
        while (d >= 1 && mp[x][d] != 6) {   //왼
            dp[x][d]++;
            d--;
        }
        func(k + 1);
        while (c >= y) {    //오른
            dp[x][c]--;
            c--;
        }
        while (d <= y) {    //왼
            dp[x][d]--;
            d++;
        }

    }
    else if (mp[x][y] == 3) {

        int c = x;
        int d = y;
        while (c <= n && mp[c][y] != 6) {   //아래
            dp[c][y]++;
            c++;
        }
        while (d >= 1 && mp[x][d] != 6) {   //왼
            dp[x][d]++;
            d--;
        }
        func(k + 1);
        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }
        while (d <= y) {    //왼
            dp[x][d]--;
            d++;
        }
        c = x;
        d = y;
        while (c >= 1 && mp[c][y] != 6) {   //위
            dp[c][y]++;
            c--;
        }
        while (d >= 1 && mp[x][d] != 6) {   //왼
            dp[x][d]++;
            d--;
        }
        func(k + 1);
        while (c <= x) {    //위
            dp[c][y]--;
            c++;
        }
        while (d <= y) {    //왼
            dp[x][d]--;
            d++;
        }

        c = x;
        d = y;
        while (c >= 1 && mp[c][y] != 6) {   //위
            dp[c][y]++;
            c--;
        }
        while (d <= m && mp[x][d] != 6) {   //오른
            dp[x][d]++;
            d++;
        }
        func(k + 1);
        while (c <= x) {    //위
            dp[c][y]--;
            c++;
        }
        while (d >= y) {    //오른
            dp[x][d]--;
            d--;
        }


        c = x;
        d = y;
        while (c <= n && mp[c][y] != 6) {   //아래
            dp[c][y]++;
            c++;
        }
        while (d <= m && mp[x][d] != 6) {   //오른
            dp[x][d]++;
            d++;
        }
        func(k + 1);
        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }
        while (d >= y) {    //오른
            dp[x][d]--;
            d--;
        }
    }
    else if (mp[x][y] == 4) {
        int c = x;
        int d = y;
        int e = x;
        while (c <= n && mp[c][y] != 6) {   //아래
            dp[c][y]++;
            c++;
        }
        while (d >= 1 && mp[x][d] != 6) {   //왼
            dp[x][d]++;
            d--;
        }
        while (e >= 1 && mp[e][y] != 6) {   //위
            dp[e][y]++;
            e--;
        }
        func(k + 1);
        while (d <= y) {    //왼
            dp[x][d]--;
            d++;
        }

        d = y;
        while (d <= m && mp[x][d] != 6) {   //오른
            dp[x][d]++;
            d++;
        }
        func(k + 1);

        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }
        while (d >= y) {    //오른
            dp[x][d]--;
            d--;
        }
        while (e <= x) {    //위
            dp[e][y]--;
            e++;
        }

        c = y;
        d = x;
        e = y;
        while (c >= 1 && mp[x][c] != 6) {   //왼
            dp[x][c]++;
            c--;
        }
        while (d <= n && mp[d][y] != 6) {   //아래
            dp[d][y]++;
            d++;
        }
        while (e <= m && mp[x][e] != 6) {   //오른
            dp[x][e]++;
            e++;
        }
        func(k + 1);

        while (d >= x) {    //아래
            dp[d][y]--;
            d--;
        }
        d = x;
        while (d >= 1 && mp[d][y] != 6) {   //위
            dp[d][y]++;
            d--;
        }
        func(k + 1);

        while (d <= x) {    //위
            dp[d][y]--;
            d++;
        }
        while (c <= y) {    //왼
            dp[x][c]--;
            c++;
        }
        while (e >= y) {    //오른
            dp[x][e]--;
            e--;
        }
    }
    else {
        int c = x;
        int d = x;
        int e = y;
        int f = y;

        while (c <= n && mp[c][y] != 6) {   //아래
            dp[c][y]++;
            c++;
        }
        while (d >= 1 && mp[d][y] != 6) {   //위
            dp[d][y]++;
            d--;
        }
        while (e <= m && mp[x][e] != 6) {   //오른
            dp[x][e]++;
            e++;
        }
        while (f >= 1 && mp[x][f] != 6) {   //왼
            dp[x][f]++;
            f--;
        }
        func(k + 1);
        while (e >= y) {    //오른
            dp[x][e]--;
            e--;
        }
        while (f <= y) {    //왼
            dp[x][f]--;
            f++;
        }
        while (c >= x) {    //아래
            dp[c][y]--;
            c--;
        }
        while (d <= x) {    //위
            dp[d][y]--;
            d++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] >= 1&&mp[i][j]<=5) {
                vec.push_back({ i,j });
                dp[i][j] = 1;
            }
        }
    }
    func(0);
    cout << mim;
    return 0;
} 