#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec[100001];

int par[100001];
bool visited[100001];
int n;
struct node
{
    int data;
    node* parNode;
    vector<node*>childNode;
    node(int data) {
        this->data = data;
    }
};
node* vst[100001];
class Tree {
private:
    node* root;
    node* findNode(int data) {
        return vst[data];
    }
public:
    Tree() {
        root = new node(1);
        vst[1] = root;
    }
    void insert(int k) {
        visited[k] = true;
        node* curNode = findNode(k);
        for (int i = 0; i < vec[k].size(); i++) {
            if (visited[vec[k][i]]) {
                continue;
            }
            node* newNode;
            newNode = new node(vec[k][i]);
            par[vec[k][i]] = k;
            vst[vec[k][i]] = newNode;
            curNode->childNode.push_back(newNode);
        }

        for (int i = 0; i < vec[k].size(); i++) {
            if (visited[vec[k][i]]) {
                continue;
            }
            insert(vec[k][i]);
        }


    }
    void print() {
        for (int i = 2; i <= n; i++) {
            cout << par[i]<<'\n';
        }
        
    }

};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    cin >> n;
    Tree tr;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    tr.insert(1);
    tr.print();
}
