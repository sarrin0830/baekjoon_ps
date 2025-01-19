#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define ll long long int 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s;
    int cnt = 0;
    while (1) {
        
       getline(cin,s);
       if (cin.eof()) {
           break;
       }
       cnt++;
    }
    cout << cnt;
    return 0;
}