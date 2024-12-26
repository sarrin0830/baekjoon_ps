#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int n, k;
int ans = 0;
int fast = 100001;
bool visited[100001];
set<int> st;
void func() {
    queue<pair<int, int>>q;
    int before = 0;
    q.push({ n,0 });
    visited[n] = true;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int pos = p.first;
        int cnt = p.second;
        q.pop();
        if (before < cnt) {
            for (auto s : st) {
                visited[s] = true;
            }
            st.clear();
            before = cnt;
        }
        if (cnt > fast) {
            break;
        }
        if (pos == k) {
            fast = cnt;
            ans++;
            continue;
        }
        
        if (pos - 1 >= 0 && !visited[pos - 1]) {
            q.push({ pos - 1, cnt + 1 });
            st.insert(pos - 1);
        }
        if (pos + 1 <= 100000 && !visited[pos + 1]) {
            q.push({ pos + 1, cnt + 1 });
            st.insert(pos + 1);
        }
        if (pos * 2 <= 100000 && !visited[pos * 2]) {
            q.push({ pos * 2, cnt + 1 });
            st.insert(pos * 2);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    func();
    cout << fast << '\n' << ans;
    return 0;
}