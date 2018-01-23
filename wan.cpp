#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "w", stdout);
	printf("20\n");
	for(int k = 1; k <= 20; k++)
	{
	printf("10 1000\n");
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 1000; j++)
			printf("%.1lf ", (j % 6) * 0.1 + 0.1);
		printf("\n");
	}
}
}
