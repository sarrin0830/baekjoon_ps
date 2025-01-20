#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define ll long long int 
using namespace std;
int k;
int student[100001];
bool check[100001];
int T, n;
int sum = 0;
int func(int a) {

    if (student[a] == k) {
        sum++;
        return k;
    }

    if (student[a] == a||check[a]) {
        return a;
    }
    else {
        int cur = func(student[a]);
        if (k == cur) {
            student[a] = cur;
            sum++;
        }
        return cur;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        sum = 0;
        for (int j = 1; j <= n; j++) {
            student[j] = j;
            check[j] = false;
        }

        for (int j = 1; j <= n; j++) {
            cin >> k;
            if (k == j) {
                sum++;
                check[j] = true;
                continue;
            }
            else if (check[student[k]]) {

                check[j] = true;
                continue;
            }
            student[j] = k;
            k = j;
            int cur = func(j);
            if (cur == j) {
                check[cur] = true;
            }
        }

        for (int j = 1; j <= n; j++) {
            student[j] = j;
        }
        cout << n - sum <<'\n';
    }
    return 0;
}