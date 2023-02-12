#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check[101]={false,};
vector<int> com[101];

void dfs(int x){
    check[x]=true;
    for(int i=0;i<com[x].size();i++){
        if(check[com[x][i]]){
            continue;
        }
        dfs(com[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x,y,a,b,n;
    int sum=0;
    cin>>x>>y;
    
    for(int i=0;i<y;i++){
        cin>>a>>b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    
    dfs(1);
    
    for(int i=2;i<=x;i++){
        if(check[i]){
            sum++;
        }
    }
    
    cout<<sum;
    
    return 0;
}
