#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define INF 2000000001
using namespace std;


vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    int s = 0;
    int l = n-1;
    int mx = INF;
    int ans1 = 0;
    int ans2 = 0;
    while (s < l) {
        int sum = v[s] + v[l];
        if (abs(sum) < mx) {
            mx = abs(sum);
            ans1 = s;
            ans2 = l;
        }
        else {
            if (sum < 0) {
                s++;
            }
            else {
                l--;
            }
        }
    }
    cout << v[ans1] << " " << v[ans2];
    return 0;
}