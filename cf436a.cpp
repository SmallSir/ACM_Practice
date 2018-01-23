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

string str;
int i,n,sum,b[30];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>str[i];
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		if(str[i]<='z'&&str[i]>='a')
		{
			sum=0;
			for(;i<=n;i++)
			{
				if(str[i]>='A'&&str[i]<='Z')
					break;
				if(b[str[i]-'a']==0)
				{
					sum++;
					b[str[i]-'a']=1;
				}
			}
			cnt=max(cnt,sum);
		}
	}
	cout<<cnt<<endl;
}
