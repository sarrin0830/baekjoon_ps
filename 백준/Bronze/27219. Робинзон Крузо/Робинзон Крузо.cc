#include <iostream>
#include <algorithm>
#include <vector>
#include<map>
#include <queue>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k = n / 5;
    n = n % 5;
    for (int i = 0; i < k; i++) {
        cout << 'V';
    }
    for (int i = 0; i < n; i++) {
        cout << 'I';
    }
    return 0;
} 