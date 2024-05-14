#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visit[1001];
vector<int> a[1001];

void dfs(int v){
    visit[v]=1;
    for(int i=0;i<a[v].size();i++){
        if(visit[a[v][i]]==0){
            dfs(a[v][i]);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y,m,n,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
    return 0;
}
