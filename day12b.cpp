#include<iostream>  
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdio>
#include<climits>   
#include<cmath>
#include<stack>
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map> 
#define inf 9999999; 
using namespace std;

struct point
{
	int x,y;
}a[10],b[10],c[10];
int T,sum,i,j,ma,mc,mb;
int pp(point p1,point p2,point p3)
{
	 return ((p1.x - p2.x) * (p3.y - p2.y) - (p1.y - p2.y) * (p3.x - p2.x));
}
int main()
{
	in>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		sum=0;
		for(i=1;i<=3;i++)
			cin>>a[i].x>>a[i].y;
		for(i=1;i<=3;i++)
			cin>>b[i].x>>b[i].y;
		bool flag=0;	
		for(i=1;i<=3;i++)
		{
			ma=pp(a[2],a[1],b[i]);
			mb=pp(a[3],a[1],b[i]);
			if(!(ma>0&&mb>0||ma<0&&mb<0))
				sum++;
			else if(ma==0&&mb==0)
			{
				cout<<"intersect"<<endl;
				flag=1;
				break;
			}
			if(mc==0)
			{
				cout<<"intersect"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		if(sum==3)
		{
			cout<<"contain"<<endl;
		}
		else if(sum==0)
		{
			cout<<"disjoint"<<endl;
		}
		else
		{
			cout<<"intersect"<<endl;
		}
	}
}

/*for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				c[j].x=b[i].x-a[j].x;
				c[j].y=b[i].y-a[j].y;
			}
			ma=c[1].x*c[2].y-c[1].y*c[2].x;
			mb=c[2].x*c[3].y-c[2].y*c[3].x;
			mc=c[3].x*c[1].y-c[3].y*c[1].x;
			//cout<<ma<<" "<<mb<<" "<<mc<<endl;
			if(ma>0&&mb>0&&mc>0||ma<0&&mb<0&&mc<0)
				sum++;
			else if(
		}*/

