#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    long long int sum=0;
    cin>>n>>k;
    int a[n]={0,};
    int d[n-1]={0,};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        d[i-1]=(a[i]-a[i-1]);
    }
    sort(d,d+n-1);
    for(int i=0;i<n-k;i++){
        sum+=d[i];
    }
    cout<<sum;
    return 0;
}
