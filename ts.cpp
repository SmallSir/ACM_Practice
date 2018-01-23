#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int p[1000];
int a,b,c,i,m,n,h,f;

int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		h = 0;
		for(int i = m;i <= n;i++)
		{
			a = i / 100;
			b = i / 10 - a * 10;
			c = i - a * 100 - b * 10;
			if(i == (a * a * a + b * b * b + c * c * c))
			{
				p[++h] = i;
			}
		}
		sort(p + 1, p + 1 + h);
		if(h == 0)
		{
			printf("no\n");
			return 0;
		}
		else
		{
			printf("%d",p[1]);
			for(int j = 2;j <= h;j++)
				printf(" %d",p[j]);

			printf("\n");
		}
	}

}

