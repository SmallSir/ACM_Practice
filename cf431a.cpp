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

int i,n,cnt,ans,flag;
int a[105];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	if(a[1]%2==0) {
		cout<<"No"<<endl;
		return 0;
	}
	cnt=0;
	ans=0;
	flag=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]%2!=0)
		{
			ans++;
			if(flag==0)
			{
				flag=1;
			}
			else
			{
				if(ans%2!=0)
				{
					cout<<"--------------"<<i<<endl;
					ans=0;
					cnt++;
					flag=0;
				}
			}
		}
		else
			ans++;
	}
	if(flag==1)
		cnt++;
	if(cnt%2==0)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
