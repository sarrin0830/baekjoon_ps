#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, m;
vector<int>v;
map<vector<int>, int>check;
void func(int idx, vector<int>ans) {
    if (ans.size() == m) {
        sort(ans.begin(), ans.end());
        if (check.find(ans) != check.end()) {
            return;
        }
        else {
            check[ans] = 1;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        ans.push_back(v[i]);
        func(idx + 1, ans);
        ans.pop_back();
    }
    
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    map<int,int>mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k;
        mp[k] = 1;
    }
    for (auto i : mp) {
        v.push_back(i.first);
    }
    sort(v.begin(), v.end());
    vector<int>newV;
    func(0,newV);
    return 0;
}