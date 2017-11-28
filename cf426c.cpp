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

int T;
LL n,a,b,i;
map<LL,int> check;
int main()
{
	for(i=1;i<=1e6;i++)
	{
		check[i*i*i]=i;
	}
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&a,&b);
		n=check[a*b];
		if(n!=0&&a%n==0&&b%n==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
