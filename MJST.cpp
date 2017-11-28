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
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		LL n, m, sum = 0;
		scanf("%lld%lld", &n, &m);
		if(m >= n - 1)
		{
			if(m >= n * (n - 1) / 2) sum = n * (n - 1) / 2;
			else
			{
				LL ans = n - 1;
				sum = sum + n - 1;
				m = m - (n - 1);
				for(LL i = 2; i <= n; i++)
				{
					LL k;
					ans--;
					if(m >= ans) k = ans;
					else k = m;
					m -= k;
					sum = sum + k + 2 * (ans - k);
				}
			}
		}
		else 
		{
			sum = sum + m;
			sum += (m - 1) * m;
			sum += (n * (n - 1) / 2 - m - m * (m - 1) / 2) * n;
		}
		printf("%lld\n", sum * 2);
	}
	return 0;
}
