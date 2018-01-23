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

int main()
{
	int a,b,c,x,t;
	scanf("%d%d%d%d",&a,&b,&c,&x);
	if(x<b&&x<=2*c&&2*x>=c)
	{
		t=x>c?x:c;
		printf("%d\n",a>(2*b+1)?a:(2*b+1));
		printf("%d\n",b>(t*2+1)?b:(t*2+1));
		printf("%d\n",t);
	}
	else
		printf("-1\n");
	return 0;
}
