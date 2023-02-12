#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int xo;
    int m,t;
    cin>>m;
    cin>>t;
    xo=t;
    for(int i=1;i<m;i++){
        cin>>t;
        xo=xo^t;
    }
    if(xo!=0){
        cout<<"koosaga";
    }
    else{
        cout<<"cubelover";
    }

    return 0;
}
