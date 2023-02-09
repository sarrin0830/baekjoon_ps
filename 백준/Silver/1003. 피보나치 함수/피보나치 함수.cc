#include <iostream>
#include<algorithm>
using namespace std;
int dp[40];

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if(dp[n]!=0){
        
        return dp[n];
    }
    else {
        dp[n]=fibonacci(n-1)+fibonacci(n-2);
        return dp[n];
    }
}
int main()
{
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        if(n==0){
            cout<<1<<" "<<0<<'\n';
        }
        else{
            cout<<fibonacci(n-1)<<" "<<fibonacci(n)<<'\n';
        }
            
    }
    return 0;
}
