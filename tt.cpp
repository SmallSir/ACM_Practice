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
	int i,j,n;
	char a[105][10];
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=5;j++)
		{	
			scanf("%c",&a[i][j]);
			printf("%c",a[i][j]);
		}
		printf("----------");
	}
	//cout<<i<<endl;

}
