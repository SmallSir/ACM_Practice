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

int T,m,n,MAX,i,j,ans,r;
string str;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>m;
		cin>>str;
		n=str.length();
		MAX=0;
		for(i=1;i<n;i++)
		{
			r=i-1;
			ans=0;
			for(j=i;j<n;j++)
			{
				while(ans<=m&&r<=min(n-1,i+i-1))
				{
					r++;
					ans+=abs(str[r]-str[i+i-1-r]);
				}
				MAX=max(MAX,r-j);
				ans-=abs(str[j]-str[i+i-1-j]);
			}
		}
		for(i=1;i<n;i++)
		{
			ans=0,r=i-1;
			for(j=i+1;j<n;j++)
			{
				while(ans<=m&&r<=min(n-1,i+i))
				{
					r++;
					ans+=abs(str[r]-str[i+i-r]);
				}
				MAX=max(MAX,r-j);
				ans-=abs(str[j]-str[i*2-j]);
			}
		}
		cout<<MAX<<endl;
	}
	return 0;
}
