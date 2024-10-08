#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int cnt=0;
    int k=666;
    string s;
    cin>>n;
    while(1){
        s=to_string(k);
        for(int i=0;i<s.length()-2;i++){
            if(s[i]=='6'&&s[i+1]=='6'&&s[i+2]=='6'){
                cnt++;
                if(cnt==n){
                    cout<<k;
                    return 0;
                }
                break;
            }
        }
    
        
        k++;
    }
    return 0;
}
