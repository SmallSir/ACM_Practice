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

char a[100005];
int i,sum,n;
string str;
int main()
{
	cin>>str;
	n=str.length();
	sum=0;
	for(i=0;i<n;i++)
	{
		if(str[i]=='i'||str[i]=='o')
		{
			if(i==0)
				continue;
			if(str[i]=='i')
			{
				sum--;
				sum=max(sum,0);
			}
			else
			{
				if(str[i-1]=='i')
					sum++;
				else if(str[i-1]=='o')
				{
					sum++;
				}
				else
				{
					sum--;
					sum=max(sum,0);
				}
			}
		}
		else
			a[sum++]=str[i];
	}
	for(i=0;i<sum;i++)
		cout<<a[i];
	cout<<endl;
 return 0;
}
