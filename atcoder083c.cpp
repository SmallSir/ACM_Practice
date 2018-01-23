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

double MAX;
int t[3005];
int a,b,c,j,d,e,f,k,cnt,x,n,sum,ans,i;
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	for(i=0;i<=f/a;i++)
	{
		for(j=0;j<=f/b;j++)
		{
			if(j*b*100+i*a*100>f)
				break;
			t[j*b*100+i*a*100]=1;
		}
	}
	MAX=-1;
	for(i=1;i<=f;i++)
	{
		if(t[i]==0)
			continue;
		for(j=0;j<=f/c;j++)
		{
			for(k=0;k<=f/d;k++)
			{
				ans=k*d+j*c;
				if(i+ans>f)
					break;
				if(MAX<=(double)(ans*100)/(ans+i)*1.0&&e*i>=100*ans)
				{
					cnt=ans;
					sum=ans+i;
					MAX=(double)(ans*100)/(ans+i)*1.0;
				}
			}
		}
	}
	cout<<sum<<" "<<cnt<<endl;
}
