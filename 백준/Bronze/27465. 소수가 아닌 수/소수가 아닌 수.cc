#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(n==1||n==2||n==3){
        cout<<4;
    }
    else if(n%2==0){
        cout<<n;
    }
    else{
        cout<<n+1;    
    }
    

    return 0;
}
