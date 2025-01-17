#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = 'A' + (s[i] - 'a');
        cout << c;
    }
    return 0;
}