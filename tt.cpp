#include <stdio.h>  
typedef long long ll;  
const int MAX=1e6+5;  
const int INF=0x3f3f3f3f;  
int n,a[3*MAX],b[3*MAX];  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        int s=0;  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            a[i+n]=a[i];  
        }  
        for(int i=1;i<=n;i++)  
        {  
            int x;  
            scanf("%d",&x);  
            b[i]=a[i]-x;  
            b[i+n]=b[i];  
        }  
        int sum=0,suma=0;  
        int maxa=-INF;  
        int l,r,temp=1;// l  r 可以记录区间  
        for(int i=1;i<=2*n;i++)    
        {    
            suma+=a[i];  
            sum+=b[i];  
            if(suma>maxa)  
            {  
                maxa=suma;  
                l=temp;  
                r=i;  
            }  
            if(sum<0)//限制了,重来吧   
            {  
                suma=0;  
                sum=0;  
                temp=i+1;  
                if(temp>n+1)break;  
            }  
        }    
        printf("%d\n",l-1);  
    }  
    return 0;  
}  

