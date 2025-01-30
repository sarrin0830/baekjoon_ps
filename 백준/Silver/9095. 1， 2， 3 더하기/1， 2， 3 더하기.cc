#include <iostream>
using namespace std;
int ans(int a){
    if(a>=4){
        return (ans(a-1)+ans(a-2)+ans(a-3));
    }
    else if(a==3){
        return 4;
    }
    else if(a==2){
        return 2;
    }
    else{
        return 1;
    }
}
int main()
{
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<ans(n)<<"\n";
    }
    
    
    return 0;
}
