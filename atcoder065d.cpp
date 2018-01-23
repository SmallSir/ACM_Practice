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

struct point
{
	long long int x,y;
	bool operator < (const point &o) const  
    {  
        return x < o.x || y < o.y;  
    }  
}p,pp[100005];
int n,i;
long long int sum;
map<point,bool> mm;
bool cmp(point x,point y)
{
	if(x.x==y.x)
		return x.y<y.y;
	else
		return x.x<y.x;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>p.x>>p.y;
		mm[p]=true;
	}
	map<point,int>::iterator iter;
	n=mm.size();
	//cout<<n<<"----"<<endl;
	for(i=1,iter=mm.begin();iter!=mm.end();iter++,i++)
	{
		pp[i]=mm[i];
		cout<<pp[i].x<<" "<<pp[i].y<<endl;
	}
	sort(pp+1,pp+1+n,cmp);
	sum=0;
	cout<<"---------------------"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<pp[i].x<<" "<<pp[i].y<<endl;
	}
	for(i=2;i<=n;i++)
	{
		sum+=min(abs(pp[i].x-pp[i-1].x),abs(pp[i].y-pp[i-1].y));
	}
	cout<<sum<<endl;
}
