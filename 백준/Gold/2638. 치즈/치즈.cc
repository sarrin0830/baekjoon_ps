#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int dp[101][101];


int cnt = 0;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
set<pair<int, int>>vec;
set<pair<int, int>>curV;
void bfs(int x, int y, int k) {
  bool visited[101][101] = { false, };
  int cheeze[101][101] = { 0, };
  queue<pair<int, int>>q;
  q.push({ x,y });
  int num = dp[x][y];
  visited[x][y] = true;
  dp[x][y] = k;
  while (!q.empty()) {
    pair<int, int > curq = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = curq.first + dx[i];
      int ny = curq.second + dy[i];
      if (nx < 1 || ny < 1 || nx > m || ny > n) {
        continue;
      }
      else if (visited[nx][ny]) {
        if (dp[nx][ny] == 1) {
          cheeze[nx][ny]++;
          if (cheeze[nx][ny] >= 2) {
            vec.insert({ nx,ny });
          }
        }
      }
      else if (dp[nx][ny] == 1) {
        cheeze[nx][ny]++;
        if (cheeze[nx][ny] >= 2) {
          vec.insert({ nx,ny });
        }
      }
      else {
        dp[nx][ny] = -1;
        visited[nx][ny] = true;
        q.push({ nx,ny });
        dp[nx][ny] = k;
      }

      
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  int mpCount = 0;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dp[i][j];
      if (dp[i][j] == 1) {
        mpCount++;
      }
    }
  }
  bfs(1, 1, -1);

  while (mpCount) {
    ans++;

    for (auto vc : vec) {
      int x = vc.first;
      int y = vc.second;
      dp[x][y] = -1;
      mpCount--;
    }
    vec.clear();

    bfs(1, 1, -1);
  }


  cout << ans;

  return 0;
}