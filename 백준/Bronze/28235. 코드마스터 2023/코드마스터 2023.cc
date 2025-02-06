#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (s == "SONGDO") {
        cout << "HIGHSCHOOL";
    }
    else if (s == "CODE") {
        cout << "MASTER";
    }
    else if (s == "2023") {
        cout << "0611";
    }
    else {
        cout << "CONTEST";
    }
    return 0;
} 