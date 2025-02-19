#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include<deque>
#include <queue>
#include<string>
#define ll long long int
#define INF 1000000001

using namespace std;
int n;
int a[21][21];
int b[21][21];

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << "Congratulations, you are within the speed limit!\n";
    }
    else {
        if (b - a <= 20) {
            cout << "You are speeding and your fine is $100.\n";
        }
        else if (b - a <= 30) {
            cout << "You are speeding and your fine is $270.\n";
        }
        else {
            cout << "You are speeding and your fine is $500. \n";
        }
    }
    return 0;
}