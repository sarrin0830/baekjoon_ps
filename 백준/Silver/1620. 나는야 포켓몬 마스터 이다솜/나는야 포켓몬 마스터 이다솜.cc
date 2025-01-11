#include <iostream>
#include <map>

#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> a;
    map<int,string> b;
    int n,m,t;
    int c;
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        a.insert(make_pair(s,i));
        b.insert(make_pair(i,s));
    }
    
    for(int i=0;i<m;i++){
        cin>>s;
        c=0;
        t=1;
        if(0<=s[0]-'0'&&s[0]-'0'<=9){
            for(int j=s.length()-1;j>=0;j--){
                c+=(s[j]-'0')*t;
                t*=10;
            }
            cout<<b[c]<<'\n';
        }
        else{
            cout<<a[s]<<'\n';
        }

    }
    return 0;
}
