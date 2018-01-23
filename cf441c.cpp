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
//strattime:2017/10/18 21:08
//endtime:2017/10/18 21:29

const int MAXN=1e5+5;
LL a[MAXN],c[MAXN],b[MAXN];
int j,i,n,m,k,tot;
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]%k]++;
	}
	for(i=0;i<k;i++)
	{
		if(b[i]>=m)
		{
			cout<<"Yes"<<endl;
			tot=0;
			for(j=1;j<=n;j++)
			{
				if(a[j]%k==i)
				{
					c[++tot]=a[j];
				}
				if(tot==m)
					break;
			}
			for(j=1;j<m;j++)
				cout<<c[j]<<" ";
			cout<<c[j]<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}

