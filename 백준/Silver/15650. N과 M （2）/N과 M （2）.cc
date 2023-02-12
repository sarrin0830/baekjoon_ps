#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
bool check[9]={false,};
int arr[9]={0,};
int maxx=0;
void dfs(int k){
    if (k==m){
        
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        maxx=0;
    }
    else{
        for(int i=maxx;i<n;i++){
            if(check[i]==false){
                check[i]=true;
                arr[k]=i+1;
                maxx=arr[k];
                dfs(k+1);
                check[i]=false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    dfs(0);
    
    return 0;
}
