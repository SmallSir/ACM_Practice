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

int sum,n,i,j,c;
int main()
{
	sum = 0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			c = i ^ j;
			if(c>=1&&c<=n&&c>j&&i+j>c&&i+c>j&&j+c>i)
				sum++;
		}
	}
	cout<<sum<<endl;
 return 0;
}
