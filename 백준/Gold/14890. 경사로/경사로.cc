#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
int mp[101][101];
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, l;
    int ans = 0;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int sum = 1;
        bool check = true;
        for (int j = 2; j <= n; j++) {
            if (mp[i][j-1] == mp[i][j]) {
                sum++;
            }
            else if ((mp[i][j - 1] - mp[i][j]) == -1) {
                if (sum >= l) {
                    sum = 1;
                }
                else {
                    check = false;
                    break;
                }
                
            }
            else if ((mp[i][j - 1] - mp[i][j]) == 1) {
                int cur = 1;
                if (cur == l) {
                    sum = 0;
                    continue;
                }
                while (1) {
                    j++;
                    if (j > n) {
                        check = false;
                        break;
                    }
                    if (mp[i][j] == mp[i][j - 1]) {
                        cur++;
                    }
                    else {
                        check = false;
                        break;
                    }
                    if (cur == l) {
                        sum = 0;
                        break;
                    }
                }
                
            }
            else {
                check = false;
                break;
            }
        }
        if (check) {
            ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 1;
        bool check = true;
        for (int j = 2; j <= n; j++) {
            if (mp[j-1][i] == mp[j][i]) {
                sum++;
            }
            else if ((mp[j - 1][i] - mp[j][i]) == -1) {
                if (sum >= l) {
                    sum = 1;
                }
                else {
                    check = false;
                    break;
                }

            }
            else if ((mp[j-1][i] - mp[j][i]) == 1) {
                int cur = 1;
                if (cur == l) {
                    sum = 0;
                    continue;
                }
                while (1) {
                    j++;
                    if (j > n) {
                        check = false;
                        break;
                    }
                    if (mp[j][i] == mp[j - 1][i]) {
                        cur++;
                    }
                    else {
                        check = false;
                        break;
                    }
                    if (cur == l) {
                        sum = 0;
                        break;
                    }
                }
                
            }
            else {
                check = false;
                break;
            }

        }
        if (check) {
            ans++;
        }
    }

    cout << ans;
    return 0;
} 