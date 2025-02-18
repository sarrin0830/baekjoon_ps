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
    int m, n, p, q;
    int cnt = 1;
    while (1) {

        
        cin >> m >> n >> p >> q;
        if (!m && !n && !p && !q) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= p; i++) {
            for (int j = 1; j <= q; j++) {
                cin >> b[i][j];
            }
        }

        if (n != p) {
            cout << "Case #" << cnt << ":\n";
            cout << "undefined\n";
        }
        else {
            
            cout << "Case #" << cnt << ":\n";
            for (int i = 1; i <= m; i++) {
                cout << "| ";
                for (int k = 1; k <= q; k++) {
                    int sum = 0;
                    
                    for (int j = 1; j <= n; j++) {
                        sum += a[i][j] * b[j][k];
                    }
                    cout << sum << " ";
                }
                cout << "|\n";
            }
        }


        cnt++;
    }
    return 0;
}