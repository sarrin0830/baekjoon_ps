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
    int n;
    ll mx = 0;
    vector<int>vec;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++) {
        while (!vec.empty() && h[vec.back()] > h[i]) {
            ll tp = h[vec.back()];
            ll sum;
            vec.pop_back();
            if (vec.empty()) {
                sum = (i - 1) * tp;
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
        ll sum;
        vec.pop_back();
        if (vec.empty()) {
            sum = n * tp;
        }
        else {
            sum = (n - vec.back()) * tp;
        }
        if (mx < sum) {
            mx = sum;
        }
    }
    cout << mx;


    return 0;
}