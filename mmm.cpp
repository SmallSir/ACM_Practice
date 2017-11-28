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
const int Max = 1e6;
typedef long long LL;
int n, num[Max + 5];

int main()
{
	while(~scanf("%d", &n))
	{
		memset(num, 0, sizeof(num));
		int sum = 0;
		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			num[x]++;
		}
		for(int i = 1; i <= n; i++){
			int x = num[i];
			if(x % 2 == 1)
			{
				num[i] = 1;
				sum += x / 2;
			}
			else
			{
				if(num[i] > 2){
					num[i] = 2;
					sum = sum + x / 2 - 1;
				}
			}
			//printf("num[%d] = %d\n", i, num[i]);
		}
		//printf("** %d\n", sum);
		int one = 0;
		for(int i = 1; i <= n; i++)
		{
			if(num[i] == 0)
			{
				one = 0;
				continue;
			}
			if(one == 2) {
				if(num[i] > 0) {
					num[i]--;
					sum++;
					one = 0;
				}
			}
			if(num[i] == 1) one++;
			else if(num[i] == 2)
			{
				one = 0;
				sum++;
			}
			//printf("num[%d] = %d, sum = %d\n", i, num[i], sum);
		}
		printf("%d\n", sum);
	}
	return 0;
}

