#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m,n,sum;
    int max=0;
    int a[100]={0,};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                sum=a[i]+a[j]+a[k];
                if(max<sum&&sum<=m){
                    max=sum;
                }
            }
        }
    }
    cout<<max;
    return 0;
}
