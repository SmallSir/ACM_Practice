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

int i,j,n;
LL a,b,x;
int main()
{
	cin>>b>>a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x<a)
		{
			if(i==n)
				cout<<1<<endl;
			else
				cout<<1<<" ";
		}
		else
		{
			if(a<b)
			{
				if(i==n)
					cout<<-1<<endl;
				else
					cout<<-1<<" ";
			}
			else if(a==b)
			{
				if(x %(a+1) == 0)
				{
					if(i==n)
						cout<<-1<<endl;
					else
						cout<<-1<<" ";
				}
				else
				{
					if(i==n)
						cout<<1<<endl;
					else
						cout<<1<<" ";
				}
			}
			else
			{
				if(x%(b+1)==0)
				{
					if(i==n)
						cout<<-1<<endl;
					else
						cout<<-1<<" ";
				}
				else
				{	if(i==n)
						cout<<1<<endl;
					else
						cout<<1<<" ";
				}
			}
		}
	}
	return 0;
}
