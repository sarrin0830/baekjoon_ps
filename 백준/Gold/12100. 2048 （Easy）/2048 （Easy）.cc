#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <queue>
#define ll long long int
#define INF 1000000001
using namespace std;
ll mp[21][21];
ll mx = 0;
int n;

void dirLeft(int);
void dirRight(int);
void dirUp(int);
void dirDown(int);
void func(int k,int beFunc) {

    if (k == 5) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mx < mp[i][j]) {
                    mx = mp[i][j];
                }
            }
        }
        return;
    }
    
        dirLeft(k);
        dirRight(k);
        dirDown(k);
        dirUp(k);
}

void dirLeft(int cnt) {
    ll bef[21][21] = { 0, };
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        int numIdx = -1;
        for (int j = 1; j <= n; j++) {
            bef[i][j] = mp[i][j];
            if (mp[i][j] == 0) {
                continue;
            }
            else if (numIdx == -1) {
                numIdx = j;
            }
            else {
                if (mp[i][j] == mp[i][numIdx]) {

                    mp[i][cur] = mp[i][j] * 2;
                    if (cur != numIdx) {
                        mp[i][numIdx] = 0;
                    }
                    mp[i][j] = 0;
                    numIdx = -1;
                }
                else {
                    mp[i][cur] = mp[i][numIdx];
                    if (cur != numIdx) {
                        mp[i][numIdx] = 0;
                    }
                    numIdx = j;
                }

                cur++;
            }
        }
        if (numIdx != -1) {
            mp[i][cur] = mp[i][numIdx];
            if (cur != numIdx) {
                mp[i][numIdx] = 0;
            }
        }
    }

    func(cnt + 1,1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = bef[i][j];
        }

    }
}

void dirRight(int cnt) {
    ll bef[21][21] = { 0, };
    for (int i = 1; i <= n; i++) {
        int cur = n;
        int numIdx = -1;
        for (int j = n; j >= 1; j--) {
            bef[i][j] = mp[i][j];
            if (mp[i][j] == 0) {
                continue;
            }
            else if (numIdx == -1) {
                numIdx = j;
            }
            else {
                if (mp[i][j] == mp[i][numIdx]) {

                    mp[i][cur] = mp[i][j] * 2;
                    if (cur != numIdx) {
                        mp[i][numIdx] = 0;
                    }
                    mp[i][j] = 0;
                    numIdx = -1;
                }
                else {
                    mp[i][cur] = mp[i][numIdx];
                    if (cur != numIdx) {
                        mp[i][numIdx] = 0;
                    }
                    numIdx = j;
                }

                cur--;
            }
        }
        if (numIdx != -1) {
            mp[i][cur] = mp[i][numIdx];
            if (cur != numIdx) {
                mp[i][numIdx] = 0;
            }
        }
    }

    func(cnt + 1,2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = bef[i][j];
        }

    }
}


void dirDown(int cnt) {
    ll bef[21][21] = { 0, };
    for (int i = 1; i <= n; i++) {
        int cur = n;
        int numIdx = -1;
        for (int j = n; j >= 1; j--) {
            bef[j][i] = mp[j][i];
            if (mp[j][i] == 0) {
                continue;
            }
            else if (numIdx == -1) {
                numIdx = j;
            }
            else {
                if (mp[j][i] == mp[numIdx][i]) {

                    mp[cur][i] = mp[j][i] * 2;
                    if (cur != numIdx) {
                        mp[numIdx][i] = 0;
                    }
                    mp[j][i] = 0;
                    numIdx = -1;
                }
                else {
                    mp[cur][i] = mp[numIdx][i];
                    if (cur != numIdx) {
                        mp[numIdx][i] = 0;
                    }
                    numIdx = j;
                }

                cur--;
            }
        }
        if (numIdx != -1) {
            mp[cur][i] = mp[numIdx][i];
            if (cur != numIdx) {
                mp[numIdx][i] = 0;
            }
        }
    }

    func(cnt + 1,3);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = bef[i][j];
        }

    }
}


void dirUp(int cnt) {
    ll bef[21][21] = { 0, };
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        int numIdx = -1;
        for (int j = 1; j <= n; j++) {
            bef[j][i] = mp[j][i];
            if (mp[j][i] == 0) {
                continue;
            }
            else if (numIdx == -1) {
                numIdx = j;
            }
            else {
                if (mp[j][i] == mp[numIdx][i]) {

                    mp[cur][i] = mp[j][i] * 2;
                    if (cur != numIdx) {
                        mp[numIdx][i] = 0;
                    }
                    mp[j][i] = 0;
                    numIdx = -1;
                }
                else {
                    mp[cur][i] = mp[numIdx][i];
                    if (cur != numIdx) {
                        mp[numIdx][i] = 0;
                    }
                    numIdx = j;
                }

                cur++;
            }
        }
        if (numIdx != -1) {
            mp[cur][i] = mp[numIdx][i];
            if (cur != numIdx) {
                mp[numIdx][i] = 0;
            }
        }
    }

    func(cnt + 1,4);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = bef[i][j];
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    func(0,1);
    func(0,2);
    func(0,3);
    func(0,4);
    cout << mx;
    return 0;
}