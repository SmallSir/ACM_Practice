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

int n,m,l,r,i;
int a[200005],lis[200005],ans[200005];
int j,len,k;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=1;j<min(2,m);j++)
		{
			a[j*n+i]=a[i];
		}
	}
	memset(lis,0,sizeof(lis));
	memset(ans,0,sizeof(ans));
	lis[1] = a[1];
	ans[1] = 1;
	len = 1;
	k = 0;
	for(i = 2;i<= n *min(2,m);i++)
	{
		if(lis[len] <= a[i])
		{
			lis[++len] = a[i];
			ans[len] = i;
		}
		else
		{
			l = 1;
			r = len;
			while(l<r)
			{
				k = (l + r)/2;
				if(lis[k] > a[i])
				{
					r = k;
				}
				else
				{
					l= k +1;
				}
			}
			lis[l] = a[i];
			ans[l] = i;
		}
	}
	int flag = 0;
	for(i=1;i<=len;i++)
	{
		if(ans[i] >n)
			flag++;
	}
	cout<<flag<<" "<<len<<endl;
	if(m == 1)
		cout<<len<<endl;
	else
	{
		int ff = 0;
		for(i=len-flag+1;i<len;i++)
		{
			if(lis[i] !=lis[i+1])
			{
				ff = 1;
				break;
			}
		}
		if(ff = 1)
		{
			cout<< len + m - 2<<endl;
		}
		else
		{
			cout<<len - flag + flag * (m-1)<<endl;
		}
	}
}
