#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

LL sum,ans,cnt,l,r;
int i,T,flag,n;
LL MOD=1e9+7;
string str;
long long int fast_pow(long long int x,long long int y)  
{  
    long long int res;  
    res=1;  
    while(y!=0)  
    {  
        if(y&1) res=(res*x)%MOD;  
        y>>=1;  
        x=(x*x)%MOD;  
    }  
    return res;  
}  
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>str;
		n=str.length();
		sum=0;
		ans=0;
		flag=-1;
		for(i=0;i<n;i++)
		{
			if(str[i]=='(')
			{
				i++;
				if(flag==-1)
				{
					flag=0;
					l=i;
					ans=0;
					for(;i<n;i++)
					{
						if(str[i]==')')
						{
							r=i-1;
							break;
						}
						ans=(ans*10+str[i]-'0')%MOD;
					}
				}
				else
				{
					flag=-1;
					cnt = 0;
					for(;i<n;i++)
					{
						if(str[i]==')')
							break;
						cnt=(cnt*10+str[i]-'0')%MOD;
					}
					LL k = fast_pow(10,r-l+1);
					while(cnt--)
						sum = (sum*k+ ans)%MOD;
					ans=0;
				}
			}
			else if(flag==-1&&str[i]<='9'&&str[i]>='0')
				sum=(sum*10+str[i]-'0')%MOD;
		}
		cout<<sum<<endl;
	}
 return 0;
}
