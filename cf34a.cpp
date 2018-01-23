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

int cnt,flag,n,T,i,j;
int main()
{
	cin>>T;
	while(T--)
	{
		flag = 0;
		cin>>n;
		for(i = 0;i<=40;i++)
		{
			for(j = 0;j<=15;j++)
			{
				cnt = i*3+j*7;
				if(cnt == n)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
 return 0;
}
