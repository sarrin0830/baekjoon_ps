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
    int T;
    int a, b;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << "Case " << i + 1 << ": " << a + b << '\n';
    }
}