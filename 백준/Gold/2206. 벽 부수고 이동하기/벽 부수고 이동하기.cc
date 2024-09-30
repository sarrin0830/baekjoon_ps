#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct pos
{
    int x;
    int y;
    int distance;
    bool wall;
    pos(int x, int y, int distance, bool wall) {
        this->x = x;
        this->y = y;
        this->distance = distance;
        this->wall = wall;
    }
};

int n, m;
int mp[1001][1001];
bool visitd1[1001][1001];
bool visitd2[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
    queue<pos>q;
    q.push(pos(1, 1, 1, false));

    while (!q.empty()) {
        pos curPos = q.front();
        int nDistance = curPos.distance;
        bool checkWall = curPos.wall;
        q.pop();
        if (curPos.x == n && curPos.y == m) {
            cout << nDistance;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];

            if (nx<1 || ny<1 || nx>n || ny>m) {
                continue;
            }
            else if (mp[nx][ny]) {
                if (!checkWall) {
                    visitd2[nx][ny] = true;
                    q.push(pos(nx, ny, nDistance + 1, true));
                }
            }
            else {

                if (checkWall) {
                    if (visitd2[nx][ny]) {
                        continue;
                    }
                    else {
                        visitd2[nx][ny] = true;
                        q.push(pos(nx, ny, nDistance + 1, checkWall));
                    }
                }
                else {
                    if (visitd1[nx][ny]) {
                        continue;
                    }
                    else {
                        visitd1[nx][ny] = true;
                        q.push(pos(nx, ny, nDistance + 1, checkWall));
                    }
                }

            }

        }
    }
    cout << -1;

}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            mp[i][j] = c - '0';
        }
    }
    bfs();
    return 0;
}