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

LL a,k,b;
int T;
LL gcd(LL x, LL y)
{
	if(y == 0) return x;    
    if(x < y)      return gcd(y,x);    
    else        return gcd(y, x%y); 
}
bool check(LL x)
{
	LL i;
	for(i=1;i*i*i<=1e9;i++)
	{
		if(i*i*i==x)
			return 1;
	}
	return 0;
}
int main()
{
	LL x,y;
	cin>>T;
	while(T--)
	{
		cout<<T<<endl;
		cin>>a>>b;
		k=gcd(a,b);		
		x=a/k;
		y=b/k;
		if(x==y)
		{
			if(check(x)==1)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		else
		{
			if(a%(x*x*k)==0&&b%(y*y*k)==0&&a/(x*x*k)==b/(y*y*k))
			{
				if(check(b/(y*y*k))==1)
				{
					cout<<"Yes"<<endl;
				}
				else
				{
					cout<<"No"<<endl;
				}
			}
		}
	}
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 
 return 0;
}
