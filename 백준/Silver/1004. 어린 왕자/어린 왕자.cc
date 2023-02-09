#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool start(int cx,int cy,int x1,int y1, int r){
    if(pow(abs(cx-x1),2)+pow(abs(cy-y1),2)<pow(r,2)){
        return true;
    }
    else{
        return false;
    }
}
bool end(int cx,int cy,int x2,int y2, int r){
    if(pow(abs(cx-x2),2)+pow(abs(cy-y2),2)<pow(r,2)){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    int x1,x2,y1,y2,n,cx,cy,r,cnt;
    cin>>T;
    for(int i=0;i<T;i++){
        cnt=0;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>cx>>cy>>r;
            if(start(cx,cy,x1,y1,r)!=end(cx,cy,x2,y2,r)){
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
