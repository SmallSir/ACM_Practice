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

char s;
int n,i,sum,ans;
int main()
{
	cin>>n;
	getchar();
	ans=sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%c",&s);
		if(s==' ')
		{
			sum=max(sum,ans);
			ans=0;
		}
		else
		{
			if(s<='Z'&&s>='A')
				ans++;
		}
	}
	cout<<max(ans,sum)<<endl;
 return 0;
}
