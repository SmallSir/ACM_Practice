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

char str[108],s[108];
int n,T,l,r,i,j,flag,sum;
int main()
{
	cin>>str;
	cin>>T;
	while(T--)
	{
		sum = 0;
		cin>>l>>r;
		cin>>s;
		n=strlen(s);
		for(i=l;i<=r;i++)
		{
			if(s[0]==str[i])
			{
				flag = 0;
				for(j=0;j<n;j++)
				{
					if(str[i+j]!=s[j]||i+j>r)
					{
						flag =1;
						break;
					}
				}
				if(flag ==0)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
 return 0;
}
