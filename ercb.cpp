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

char str[200005];
int n,x,y,i,sum;
int main()
{
	sum=0;
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)
		cin>>str[i];
	for(i=1;i<=n;i++)
	{
		if(str[i]=='.')
		{
			if(str[i-1]=='x')
			{
				if(y!=0)
				{
					str[i]='y';
					sum++;
					y--;
				}
			}
			else if(str[i - 1] =='y')
			{
				if(x!=0)
				{
					str[i]='x';
					sum++;
					x--;
				}
			}
			else
			{
				if(x==y&&x==0)
					continue;
				if(x==0)
				{
					str[i]='y';
					sum++;
					y--;
				}
				else if(y==0)
				{
					str[i]='x';
					sum++;
					x--;
				}
				else if(x>=y)
				{
					str[i]='x';
					sum++;
					x--;
				}
				else
				{
					str[i]='y';
					sum++;
					y--;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
