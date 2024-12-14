#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int r, c;
char mp[21][21];
bool visited[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;

void func(int x,int y,int sum,bool check[]) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx<1 || ny<1 || nx>r || ny>c) {
      continue;
    }
    else if (visited[nx][ny]) {
      continue;
    }
    else if (check[(mp[nx][ny] - 'A')]) {
      continue;
    }
    else {
      visited[nx][ny] = true;
      check[(mp[nx][ny] - 'A')] = true;
      func(nx, ny, sum + 1, check);
      visited[nx][ny] = false;
      check[(mp[nx][ny] - 'A')] = false;
    }
  }

  if (ans < sum) {
    ans = sum;
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> r >> c;
  bool checkArr[26] = { false, };
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> mp[i][j];
    }
  }
  visited[1][1] = true;
  checkArr[(mp[1][1] - 'A')] = true;
  func(1, 1, 1,checkArr);
  cout << ans;
}