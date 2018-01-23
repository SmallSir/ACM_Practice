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

int sum,cnt;
int a[10];
int vis[10];
bool dfs(int ans,int flag)
{
	if(flag==3&&ans==sum/2)
		return true;
	for(int i =1;i<=6;i++)
	{
		if(vis[i]==0)
		{
			ans+=a[i],vis[i]=1;
			if(dfs(ans,flag+1))
				return true;
			ans-=a[i],vis[i]=0;
		}
	}
	return false;
}
int main()
{
	for(int i = 1;i <= 6;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%2!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sort(a+1,a+1+6);
	if(dfs(0,0))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;

}
