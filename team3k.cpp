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

int tu[505][505];
int sum,n;
struct point
{
	int x,y;
}p[505];
bool cmp(point x,point y)
{
	if(x.x==y.x)
		return x.y<y.y;
	return x.x<y.x;
}
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	while(cin>>n)
	{
		int i,j;
		int xx,yy;
		int bx,by,cy,cx;
		memset(p,0,sizeof(p));
		memset(tu,0,sizeof(tu));
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>p[i].x>>p[i].y;
			p[i].x+=100;
			p[i].y+=100;
			tu[p[i].x][p[i].y]=1;
		}
		sort(p+1,p+1+n,cmp);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				bool flag=0;
				if(p[j].x>p[i].x&&p[j].y>=p[i].y)
				{
					xx=p[j].x-p[i].x;
					yy=p[j].y-p[i].y;
					bx=p[j].x-yy,cx=p[i].x-yy;
					by=p[j].y+xx;cy=p[i].y+xx;
					//cout<<p[i].x<<" "<<p[i].y<<" "<<p[j].x<<" "<<p[j].y<<endl;
					//cout<<bx<<" "<<by<<" "<<cx<<" "<<cy<<endl;
					//cout<<"--------------------"<<endl;
					if(bx>=0&&bx<=200&&by>=0&&by<=200&&cx<=200&&cx>=0&&cy<=200&&cy>=0)
					{
						if(tu[bx][by]==1&&tu[cx][cy]==1)
							flag=1;
					}

				}
				if(flag==1)
					sum++;
			}
		}
		cout<<sum<<endl;
	}
 
 return 0;
}
