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

LL k,cnt,b,a,f,i,sum;
int main()
{
	cin>>a>>b>>f>>k;
	cnt=b-f;
	sum=0;
	for(i=1;i<=k;i++)
	{
		if(cnt<0)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(i%2!=0)
		{
			if(i!=k)
			{
				if(cnt<2*(a-f))
				{
					sum++;
					cnt=b-2*(a-f);
				}
				else
				{
					cnt-=2*(a-f);
				}
			}
			else
			{
				if(cnt<a-f)
				{
					sum++;
					cnt=b-a+f;
				}
				if(cnt<0)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
		else
		{
			if(i!=k)
			{
				if(cnt<2*f)
				{
					sum++;
					cnt=b-2*f;
				}
				else
				{
					cnt-=2*f;
				}
			}
			else
			{
				if(cnt<f)
				{
					sum++;
					cnt=b-f;
				}
				if(cnt<0)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<sum<<endl;
}
