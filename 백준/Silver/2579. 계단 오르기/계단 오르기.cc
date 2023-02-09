#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int dp[301]={0,};;
    int score[301]={0,};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    dp[0]=score[0];
    dp[1]=score[1]+score[0];
    dp[2]=max(score[2]+score[1],score[2]+score[0]);
    for(int i=3;i<n;i++){
        dp[i]=max(dp[i-2]+score[i],score[i-1]+score[i]+dp[i-3]);
    }
    cout<<dp[n-1];

    return 0;
}
