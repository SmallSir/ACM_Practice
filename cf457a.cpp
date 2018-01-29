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

int x,h,m;
LL cnt;
int main()
{
	scanf("%d",&x);
	scanf("%d %d",&h,&m);
	cnt = 0;
	for(;;)
	{
		if(m%10==7||h%10==7)
		{
			printf("%d\n",cnt);
			return 0;
		}
		m-=x;
		if(m<0)
		{
			m=60+m;
			h--;
			if(h<0)
				h=23;
		}
		cnt++;
	}
	return 0;
}
