#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include<deque>
#include <queue>
#define ll long long int
#define INF 1000000001

using namespace std;
int n;


int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    int s = 1;
    int e = n-1;
    cout << n << " ";
    while (s < e) {
        cout << s << " " << e << " ";
        s++;
        e--;
    }
    if (s == e) {
        cout << s;
    }
    return 0;
}