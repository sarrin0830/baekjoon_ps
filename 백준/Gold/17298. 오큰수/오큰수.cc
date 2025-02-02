#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
int mp[1000001];
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    int k;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            if (cur.first < k) {
                mp[cur.second] = k;
                q.pop();
            }
            else {
                break;
            }
        }
        q.push({ k,i });
    }

    for (int i = 0; i < n; i++) {
        if (mp[i] == 0) {
            cout << -1 << " ";
        }
        else {
            cout << mp[i]<<" ";
        }
    }

    return 0;
} 