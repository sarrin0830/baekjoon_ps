#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check[1000001];
vector<int>v;
void func() {
    check[0] = check[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (!check[i]) {
            v.push_back(i);
            for (int j = i * 2; j <= 1000000; j += i) {
                check[j] = true;
            }
        }
    }
}
void partition(int k) {
    int sum = 0;
    for (int i = 0; i <= k/2; i++) {
        int a = i;
        int b = k - i;
        if (!check[a] && !check[b]) {
            sum++;
        }
    }
    cout << sum << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int n;
    cin >> T;
    func();
    for (int i = 0; i < T; i++) {
        cin >> n;
        partition(n);
    }
    return 0;
}