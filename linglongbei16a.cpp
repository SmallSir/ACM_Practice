#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

struct step
{
	string str;
	int j;
}a[1000005], b[1000005];
int n, m, ans, ans1;
bool flag;
int tu[1005][1005],tu1[1005][1005];
int i, j;
int main()
{
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> tu[i][j];
			tu1[i][j] = tu[i][j];
		}
	}
	ans = 0;
	ans1 = 0;
	for (i = 1; i <= n; i++)
	{
		for (;;)
		{
			flag = false;
			for (j = 1; j <= m; j++)
			{
				if (tu[i][j] == 0)
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			for (j = 1; j <= m; j++)
			{
				tu[i][j]--;
			}
			ans++;
			a[ans].str = "row";
			a[ans].j = i;
		}
	}
	for (i = 1; i <= m; i++)
	{
		for (;;)
		{
			flag = false;
			for (j = 1; j <= n; j++)
			{
				if (tu[j][i] == 0)
				{
					flag = true;
					break;
				}
				
			}
			if (flag)
				break;
			for (j = 1; j <= n; j++)
			{
				tu[j][i]--;
			}
			ans++;
			a[ans].str = "col";
			a[ans].j = i;
		}
	}

	for (i = 1; i <= m; i++)
	{
		for (;;)
		{
			flag = false;
			for (j = 1; j <= n; j++)
			{
				if (tu1[j][i] == 0)
				{
					flag = true;
					break;
				}
				
			}
			if (flag)
				break;
			for (j = 1; j <= n; j++)
			{
				tu1[j][i]--;
			}
			ans1++;
			b[ans1].str = "col";
			b[ans1].j = i;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (;;)
		{
			flag = false;
			for (j = 1; j <= m; j++)
			{
				if (tu1[i][j] == 0)
				{
					flag = true;
					break;
				}
				//tu1[i][j]--;

			}
			if (flag)
				break;
			for (j = 1; j <= m; j++)
			{
				tu1[i][j]--;
			}
			ans1++;
			b[ans1].str = "row";
			b[ans1].j = i;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (tu[i][j] != 0&&tu1[i][j]!=0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if (ans < ans1)
	{
		cout << ans << endl;
		for (i = 1; i <= ans; i++)
		{
			cout << a[i].str << " " << a[i].j << endl;
		}
	}
	else
	{
		cout << ans1 << endl;
		for (i = 1; i <= ans1; i++)
		{
			cout << b[i].str << " " << b[i].j << endl;
		}
	}
}
