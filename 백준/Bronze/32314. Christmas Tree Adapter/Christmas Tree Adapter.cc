#include<iostream>
using namespace std;


int main() {
    int a, w, v;
    cin >> a;
    cin >> w >> v;
    if (a <= w / v) {
        cout << 1;
    }
    else {
        cout << 0;
    }


    return 0;
}