#include <iostream>

using namespace std;

int main()
{
    int n,num;
    double p=0;
    double q=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num%3==0){
            q+=1.0;
        }
        else if(num%3==1){
            p+=1.0;
        }
        else{
            p-=1.0;
            q-=1.0;
        }
    }
    cout.precision(9);
    cout<<fixed;
    cout<<p<<" "<<q;
    return 0;
}
