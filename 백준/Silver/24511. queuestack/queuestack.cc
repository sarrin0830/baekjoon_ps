
#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n, m;
bool queuedeck[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> queuedeck[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (queuedeck[i] == 0)
            dq.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        dq.push_front(x);
        cout << dq.back() << " ";
        dq.pop_back();

    }
}