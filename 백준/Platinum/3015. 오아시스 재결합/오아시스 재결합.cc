#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

#define ll long long int
#define INF 1000000001

using namespace std;
int n;
ll cnt;
vector<int>vec;
vector<pair<ll, int>>st;

void func(int k) {
    ll curN = vec[k];
    if (st.empty()) {
        st.push_back({ curN,1 });
    }
    else if (st.back().first > curN) {
        cnt++;
        st.push_back({ curN,1 });
    }
    else if (st.back().first == curN) {
        cnt = cnt + st.back().second++;
        if (st.size() > 1) {
            cnt++;
        }
    }
    else if (st.back().first < curN) {
        cnt+=st.back().second;
        st.pop_back();
        func(k);
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    ll k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        vec.push_back(k);
        func(i);
    }
    cout << cnt;
    return 0;
}