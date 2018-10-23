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

int nxt[200005],n;
char a[200005],b[200005];
void get_next()
{
	int i = 1;
	int j = 0;
	nxt[1] = 0;
	while(i<=n)
	{
		if(j==0||b[j] == b[i])
		{
			i++;
			j++;
			nxt[i] = j;
		}
		else
			j = nxt[j];
	}
}
bool KMP()
{
	int i,j;
	i = j = 0;
	while(i<=2*n&&j<=n)
	{
		if(a[i] == b[j]||j==0)
		{
			i++;
			j++;
		}
		else
		{
			j = nxt[j];
		}
	}
	if(j==n+1)
	{
		return 1;
	}
	else
	{
		i = 2*n,j=0;
		while(i>0&&j<=n)
		{
			if(a[i] == b[j]||j==0)
			{
				i--;
				j++;
			}
			else
			{
				j = nxt[j];
			}	
		}
		if(j==n+1)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int T,i;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(nxt,0,sizeof(nxt));
		cin>>n;
		getchar();
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		m = len(a[1]);
		for(i=1;i<=n;i++)
		{

			for(j=i+1;j<=n;j++)
			{

			}
		}
		get_next();
		if(KMP()==0)
			cout<<"Sad"<<endl;
		else
			cout<<"Yeah"<<endl;
	}
}
