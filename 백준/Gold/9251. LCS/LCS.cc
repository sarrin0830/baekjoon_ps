#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2,x,y;
    int lcs[1001][1001]={0,};
    cin>>s1>>s2;
    x='0'+s1;
    y='0'+s2;
    for(int i=0;i<x.length();i++){
        for(int j=0;j<y.length();j++){
            if(i==0||j==0){
                lcs[i][j]=0;
                continue;
            }
            
            if(x[i]==y[j]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<lcs[x.length()-1][y.length()-1];

    return 0;
}
