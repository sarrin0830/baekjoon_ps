#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int n;
int ans = 0;
int curSize = 0;
int curX;
int curY;
int siz = 2;
int mp[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
map<pair<int, int>, int>v;
struct pos
{
    int x;
    int y;
    int sum;
    pos(int x, int y, int sum) {
        this->x = x;
        this->y = y;
        this->sum = sum;
    }
};
void bfs() {
    while (!v.empty()) {
        bool visited[21][21] = { false, };
        queue<pos>q;
        q.push(pos(curX, curY, 0));
        visited[curX][curY] = true;
        vector<pos>vec;
        while (!q.empty()) {
            pos curP = q.front();
            q.pop();
            int curS = curP.sum;
            if (mp[curP.x][curP.y] < siz) {
                if (v.find({ curP.x,curP.y }) != v.end()) {
                    vec.push_back(pos(curP.x, curP.y, curS));
                    continue;
                }
            }
            

            for (int i = 0; i < 4; i++) {
                int nx = curP.x + dx[i];
                int ny = curP.y + dy[i];

                if (nx<1 || ny<1 || nx>n || ny>n) {
                    continue;
                }
                else if (mp[nx][ny] > siz || visited[nx][ny]) {
                    continue;
                }
                else {
                    q.push(pos(nx, ny, curS + 1));
                    visited[nx][ny] = true;
                }
            }
        }
        if (vec.empty()) {
            break;
        }
        int mx = vec[0].x;
        int my = vec[0].y;
        int mSum = vec[0].sum;
        for (int i = 1; i < vec.size(); i++) {
            if (mSum > vec[i].sum) {
                mx = vec[i].x;
                my = vec[i].y;
                mSum = vec[i].sum;
            }
            else if (mSum == vec[i].sum) {
                if (mx > vec[i].x) {
                    mx = vec[i].x;
                    my = vec[i].y;
                    mSum = vec[i].sum;
                }
                else if (mx == vec[i].x) {
                    if (my > vec[i].y) {
                        mx = vec[i].x;
                        my = vec[i].y;
                        mSum = vec[i].sum;
                    }
                }
            }
        }
        curX = mx;
        curY = my;
        
        auto it = v.find({ mx,my });
        v.erase(it);
        ans += mSum;
        curSize++;
        if (curSize == siz) {
            siz++;
            curSize = 0;
        }
    }
    cout << ans;
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 9) {
                curX = i;
                curY = j;
                mp[i][j] = 0;
            }
            else if (mp[i][j] != 0) {
                v.insert(pair<pair<int,int>,int>({ i, j },mp[i][j]));
            }
        }

    }
    
    bfs();
    return 0;
}