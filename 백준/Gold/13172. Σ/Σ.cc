#include<iostream>
#include<vector>
#include<algorithm>
#define div 1000000007
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  else if (a <= b) {
    return gcd(b % a, a);
  }
  else {
    return gcd(b, a);
  }

}
long long int checkMod(long long int k, long long int d) {
  if (d == 0) {
    return 1;
  }
  else if (d == 1) {
    return k;
  }
  long long int curK = checkMod(k, d / 2) % div;
  if (d % 2 == 0) {
    return (curK * curK) % div;
  }
  else {
    return ((curK * curK)%div * k) % div;
  }
}
int m;
long long int sum;
vector<long long int>v;
int main() {
  long long int x, y;
  long long int ans = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    long long int g = gcd(x, y);
    x /= g;
    y /= g;
    ans = (ans + (checkMod(x, div - 2) * y) % div) % div;
  }
  cout << ans;

  return 0;
}