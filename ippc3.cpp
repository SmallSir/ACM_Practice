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

int T,n,a[10][10];
bool flag;
int i,j,z;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		if(n>=6||n<=2)
		{
			cout<<"Bad Team!"<<endl;
			continue;
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<=n-i;j++)
			{
				cin>>a[i][i+j];
				a[j+i][i]=a[i][i+j];
			}
		}
		flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(z=j+1;z<+n;z++)
				{
					if(a[i][j]==a[j][z]&&a[i][j]==a[i][z])
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"Bad Team!"<<endl;
		else
			cout<<"Great Team!"<<endl;
	}
	return 0;
}
