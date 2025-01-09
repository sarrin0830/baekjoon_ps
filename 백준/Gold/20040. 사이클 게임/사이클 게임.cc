#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int ans = -1;
int vertex[500001];
bool visited[500001];
bool check;

int refactor(int k) {
    if (k == vertex[k]) {
        return k;
    }
    else {
        return vertex[k] = refactor(vertex[k]);
    }
}

void func(int a, int b, int cur) {
    if (!visited[a] && !visited[b]) {
        if (a < b) {
            vertex[a] = a;
            vertex[b] = a;
        }
        else {
            vertex[a] = b;
            vertex[b] = b;
        }
        visited[a] = true;
        visited[b] = true;
    }
    else if (visited[a] && !visited[b]) {
        visited[b] = true;
        vertex[b] = vertex[a];
    }
    else if (!visited[a] && visited[b]) {
        visited[a] = true;
        vertex[a] = vertex[b];
    }
    else {
        refactor(a);
        refactor(b);
        if (vertex[a] == vertex[b]) {
            ans = cur + 1;
            check = true;
        }
        else if (vertex[a] > vertex[b]) {
            vertex[vertex[a]] = vertex[b];
        }
        else {
            vertex[vertex[b]] = vertex[a];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vertex[i] = -1;

    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (check) {
            continue;
        }
        func(a, b, i);
    }
    if (ans == -1) {
        cout << 0;
    }
    else {
        cout << ans;
    }

    return 0;
}