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

int a[1005],b[1005];
vector<int> tu[1005];
int T,n,flag,x,y,sum,m;
int main()
{
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		flag=0;
		memset(tu,0,sizeof(tu));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			tu[x].push_back(y);
			a[x]++;
			b[y]++;
		}	
		for(i=1;i<=n;i++)
		{
			if(b[i]>1)
			{
				flag=1;
				break;
			}
		}
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
				sum++;
		}
		if(sum>1)
			flag=1;
		if(flag==1)
			cout<<"Light my fire!"<<endl;
		else
			cout<<"I love you my love and our love save us!"<<endl;
	}
	return 0;
}
