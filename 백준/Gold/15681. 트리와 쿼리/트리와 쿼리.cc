#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#define INF 2000000001
using namespace std;
vector<int> vec[100001];
struct node
{
    int num;
    node* parNode;
    vector<node*> childNode;
    int subSize;
    node(int num) {
        this->num = num;
        parNode = nullptr;
        subSize = 1;
    }
};
node* mp[100001] = { nullptr, };
class tree {
private:
    node* root;
public:
    tree() {
        root = nullptr;
    }
    void insert(int k) {
        if (root == nullptr) {
            root = new node(k);
            mp[k] = root;
            return;
        }
    }
    void insert(int u, int v) {
        node* uNode = mp[u];
        node* vNode = new node(v);
        vNode->parNode = uNode;
        uNode->childNode.push_back(vNode);
        mp[v] = vNode;
    }
};
tree tr;
void func(int k) {
    bool visited[100001] = { false, };
    queue<int>q;
    q.push(k);
    visited[k] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            int curNum = vec[cur][i];
            if (!visited[curNum]) {
                visited[curNum] = true;
                q.push(curNum);
                tr.insert(cur, curNum);
            }
        }
    }
}

int reSize(int k) {
    if (mp[k]->childNode.empty()) {
        return 1;
    }
    else {
        int sum = 0;
        for (int i = 0; i < mp[k]->childNode.size(); i++) {
            sum += reSize(mp[k]->childNode[i]->num);
        }
        mp[k]->subSize += sum;
        return mp[k]->subSize;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, q;
    int u, v;
    int k;
    cin >> n >> r >> q;
    
    tr.insert(r);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    func(r);
    reSize(r);
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << mp[k]->subSize << '\n';
    }
    return 0;
}