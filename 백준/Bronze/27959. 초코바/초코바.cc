#include<iostream>
using namespace std;


int main() {
    int n,k;
    cin >> n>>k;
    if (n * 100 >= k) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}