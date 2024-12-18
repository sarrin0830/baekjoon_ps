#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<char>v;
string s1;
string s2;
int len;
void push() {
  bool check = false;
  for (int i = 0; i < len; i++) {
    if (v[v.size() - i-1] != s2[len-i-1]) {
      check = true;
      break;
    }
  }
  if (!check) {
    for (int i = 0; i < len; i++) {
      v.pop_back();
    }
  }
}
int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  
  cin >> s1 >> s2;;
  len = s2.length();
  for (int i = 0; i < s1.length(); i++) {
    v.push_back(s1[i]);
    if (v.size() >= len) {
      push();
    }
  }
  if (v.empty()) {
    cout << "FRULA";
  }
  else {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
  }
 
  return 0;
}