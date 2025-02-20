#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include<deque>
#include <queue>
#include<string>
#define ll long long int
#define INF 1000000001

using namespace std;
int n;
int a[21][21];
int b[21][21];

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a;
    int x, y;
    
    while (1) {
        int sum = 1;
        cin >> a;
        if (a == 0) {
            break;
        }
        for (int i = 0; i < a; i++) {
            cin >> x >> y;
            sum *= x;
            sum -= y;
        }
        cout << sum << '\n';
    }
    

    return 0;
}