#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define INF 100000001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum;
    int mim = INF;
    int n, s, k;
    vector<int>v;
    cin >> n >> s;
    int st = 0;
    int ed = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    sum = v[0];
    while (ed < n) {
        if (st > ed) {
            ed = st;
            if (st < n) {
                sum = v[st];
            }
        }
        else if (sum >= s) {
            if (mim > ed - st + 1) {
                mim = ed - st + 1;
            }
            sum -= v[st];
            st++;
            
        }
        else {
            ed++;
            if (ed < n) {
                sum += v[ed];
            }
        }

    }

    if (mim == INF) {
        cout << 0;
    }
    else {
        cout << mim;
    }

    return 0;
}