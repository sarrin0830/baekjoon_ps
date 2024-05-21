#include<stdio.h>
int main(void){
    int a=0;
    int b=0;
    int n=0;
    int arr[30]={0};
    
    for(int j=0;j<28;j++){  
        scanf("%d", &n);
        arr[n-1] = n;
    }
    
    for(int i=0;i<30;i++){
        if(a==0 && arr[i]==0){
            a = i+1;
        }
        else if(b==0 && arr[i]==0){
            b = i+1;
        }
    }
    
    if(a>b){
        printf("%d\n%d", b, a);
    }else{
        printf("%d\n%d", a, b);
    }
    
    return 0;

}