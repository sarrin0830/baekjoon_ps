#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
#define INF 1000000001
using namespace std;

ll h[100001];
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    while (1) {
        int n;
        cin >> n;
        ll mx = 0;
        vector<int> vec;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        for (int i = 0; i < n; i++) {
            while (!vec.empty() && h[vec.back()] > h[i]) {

                ll tp = h[vec.back()];
                vec.pop_back();

                ll sum;
                if (vec.empty()) {
                    sum = i * tp;
                }
                else {
                    sum = (i - vec.back() - 1) * tp;
                }

                if (mx < sum) {
                    mx = sum;
                }
            }
            vec.push_back(i);
        }

        while (!vec.empty()) {
            ll tp = h[vec.back()];
            vec.pop_back();
            
            ll sum;
            if (vec.empty()) {
                sum = n * tp;
            }
            else {
                sum = (n - vec.back() - 1) * tp;
            }

            if (mx < sum) {
                mx = sum;
            }
        }
        cout << mx << '\n';
    }



    return 0;
}