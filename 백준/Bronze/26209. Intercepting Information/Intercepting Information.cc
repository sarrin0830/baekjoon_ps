#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>vec;


int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int k;
    bool check = false;
    for (int i = 0; i < 8; i++) {
        cin >> k;
        if (k == 0 || k == 1) {
            continue;
        }
        check = true;
    }
    if (check) {
        cout << "F";
    }
    else {
        cout << "S";
    }
    return 0;
}