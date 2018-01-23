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

int T,n,cnt,i;
LL x;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt = 0;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			if(x%4==0)
				cnt++;
		}
		if(cnt<n/2)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
 return 0;
}
