#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int x;
  vector<int>curV;
  vector<int>nextV;

  vector<int>curVm;
  vector<int>nextVm;
  for (int i = 0; i < 3; i++) {
    cin >> x;
    nextV.push_back(x);
    nextVm.push_back(x);
  }

  for (int i = 2; i <= n; i++) {
    
    curV = nextV;
    curVm = nextVm;

    cin >> x;
    nextV[0] = max(curV[0], curV[1]) + x;
    nextVm[0] = min(curVm[0], curVm[1]) + x;

    cin >> x;
    nextV[1] = max(max(curV[0], curV[1]), curV[2]) + x;
    nextVm[1] = min(min(curVm[0], curVm[1]), curVm[2]) + x;

    cin >> x;
    nextV[2] = max(curV[1], curV[2]) + x;
    nextVm[2] = min(curVm[1], curVm[2]) + x;
  }

  int mx = 0;
  int mim = 1000000;
  for (int i = 0; i < 3; i++) {
    if (nextVm[i] < mim) {
      mim = nextVm[i];
    }
    if (nextV[i] > mx) {
      mx = nextV[i];
    }
  }
  cout << mx << " " << mim;
  return 0;
}