#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;

int n, m;
struct point
{
	int x,y;
	/*bool friend operator < (piont a, point b)
	{
		if(a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	}*/
};
map<point,bool> check;
//point p;
int main()
{
	for(;;)
	{
		int i;
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(i=1;i<=m;i++)
		{
			point p;
			cin>>x>>y;
			//a.x = x; a.y = y;
			if(x<y)
				swap(x,y);
			p.x=x;
			p.y=y;
			if(!check[p])
			{
				check[p]=true;
				tu[x].push_back(y);
				tu[y].push_back(x);
			}
		}
	}
}
