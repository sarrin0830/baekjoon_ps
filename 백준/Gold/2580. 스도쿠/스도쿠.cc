#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int mp[10][10];
bool col[10][10];
bool square[10][10];
bool row[10][10];

void dfs(int count) {
    if (count == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = count / 9;
    int y = count % 9;
    if (mp[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                mp[x][y] = i;
                dfs(count + 1);
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
                mp[x][y] = 0;
            }
        }
    }
    else {
        dfs(count+1);
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mp[i][j];
            if (mp[i][j] != 0) {
                row[i][mp[i][j]] = true;
                col[j][mp[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][mp[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}