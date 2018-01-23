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

struct moster
{
	int hp,ap;
}a[15],b[15],c[15],l,r;
bool flag,check[15];
int n;
bool flighting()
{
	int i,j,k,x;
	i=1;j=1;
	l=a[1],r=c[1];
	for(;;)
	{
		if(j==n+1)
			return 0;
		if(i==n+1)
			return 1;
		k=r.hp/l.ap;
		if(r.hp%l.ap!=0)
			k++;
		x=l.hp/r.ap;
		if(l.hp%r.ap!=0)
			x++;
		//cout<<j<<" "<< k<<"  "<<i<<"  "<<x<<endl;
		if(x<k)
		{
			r.hp-=l.ap*x;
			i++;
			l=a[i];
		}
		else if(k<x)
		{
			l.hp-=r.ap*k;
			j++;
			r=c[j];
		}
		else
		{
			i++,j++;
			l=a[i];
			r=c[j];
		}
	}
}
void tt(int x)
{
	int i;
	if(flag==true)
		return;
	for(i=1;i<=n;i++)
	{
		if(!check[i])
		{
			check[i]=true;
			c[x].hp=b[i].hp;
			c[x].ap=b[i].ap;
			if(x==n)
			{
				flag=flighting();
				check[i]=false;
			}
			else
			{
				tt(x+1);
				check[i]=false;
			}
		}
	}
}
int main()
{
	int i,T;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].hp>>a[i].ap;
		}
		for(i=1;i<=n;i++)
		{
			cin>>b[i].hp>>b[i].ap;
		}
		flag=false;
		memset(check,0,sizeof(check));
		for(i=1;i<=n;i++)
		{
			if(!check[i])
			{
				check[i]=true;
				c[1].hp=b[i].hp;
				c[1].ap=b[i].ap;
				tt(2);
				check[1]=false;
			}
			if(flag)
			{
				break;
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}
