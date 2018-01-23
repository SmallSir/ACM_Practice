#include<iostream>  
#include<stdio.h>  
#include<string.h>  
using namespace std;  
int main()  
{  
    int n,a,b,c;  
    scanf("%d%d%d%d",&n,&a,&b,&c);  
    int mi = min(a,b);  
    mi = min(mi,c);  
    if(n==1) printf("0\n");  
    else{  
        int ans = min(a,b);  
        n-=2;  
        ans+=mi*n;  
        printf("%d\n",ans);  
    }  
    return 0 ;  
}  
