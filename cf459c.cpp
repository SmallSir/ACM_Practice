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

int res,i,n,l,r,j;
char str[5005];
int main()
{
	cin>>str;
	res=0;
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		l=0,r=0;
		for(j=i;j<n;j++)
		{
			if(str[j]=='(')
				l++;
			else if(str[j]==')')
				l--;
			else
			{
				l--;
				r++;
			}
			if(l==0)
				res++;
			if(l<0)
			{
				if(r==0)
					break;
				else if(r>0)
				{
					l+=2;
					r--;
				}
			}
		}
	}
	cout<<res<<endl;
 return 0;
}
