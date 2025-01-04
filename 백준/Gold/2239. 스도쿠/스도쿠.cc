#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define INF 100000001
using namespace std;
int mp[10][10];
bool col[10][10];
bool row[10][10];
bool square[10][10];

void dfs(int k) {
    
    int x = k / 9;
    int y = k % 9;
    if (k == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mp[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    if (mp[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                square[(x  / 3) * 3 + y / 3][i] = true;
                mp[x][y] = i;
                dfs(k + 1);
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + y / 3][i] = false;
                mp[x][y] = 0;
            }
        }
    }
    else {
        dfs(k + 1);
    }

}

int main() {
    char c;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c;
            mp[i][j] = c - '0';
            if (mp[i][j] != 0) {
                col[j][c - '0'] = true;
                row[i][c - '0'] = true;
                square[(i/ 3) * 3 + j / 3][c - '0'] = true;
            }
        }
    }
    dfs(0);
    return 0;
}