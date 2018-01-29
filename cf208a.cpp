#include <cstdio>  
#include <cstring>  
#include <iostream>  
using namespace std;  
int a[10000];  
int main(){  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<n;i++){  
        scanf("%d",&a[i]);  
    }  
    if(n<=3){  
        cout<<"no"<<endl;  
        return 0;  
    }  
    for(int i=0;i<n;i++){  
        bool flag1=false,flag2=false;  
        for(int j=i+2;j<n;j++){  
            if(a[j]>a[i]&&a[j]>a[i+1]){  
                flag1=true;  
            }  
            else if(a[j]<a[i]&&a[j]<a[i+1]){  
                flag1=true;  
            }  
            else  
                flag2=true;  
        }  
        if(flag1&&flag2){  
            cout<<"yes"<<endl;  
            return 0;  
        }  
    }  
  
    cout<<"no"<<endl;  
    return 0;  
}  
