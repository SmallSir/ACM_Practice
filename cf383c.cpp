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

int cnt,ans;
vector<int> tu[105];
int check[105],n;
int GCD(int x, int y)
{
	if(y == 0) return x;
	else return GCD(y, x % y);
}

int LCM(int x, int y)
{
	return x / GCD(x, y) * y;
}
void dfs(int x,int flag)
{
	//cnt++;
	int k=tu[x][0];
	check[x]=1;
	if(check[k]==1)
	{
		if(k!=flag)
			cnt=-1;
		if(x==flag&&cnt==1)
			cnt++;
			
		return;
	}
	else
	{
		cnt++;
		dfs(k,flag);
	}

}
int main()
{
	cin>>n;
	int i,x;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		tu[i].push_back(x);
	}
	ans=1;
	for(i=1;i<=n;i++)
	{
		memset(check,0,sizeof(check));
		cnt=1;
		dfs(i,i);
		if(cnt<0)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(cnt%2==0)
			cnt/=2;
		ans=LCM(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
