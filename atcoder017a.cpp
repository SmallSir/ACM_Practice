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

double sum,k;
int n,p;
int a[55];
double check(int xx,int yy)
{
	//cout<<x<<" "<<y<<endl;
	int i;
	double ss;
	ss=1;
	for(i=yy+1;i<=xx;i++)
	{
		ss*=i;
	}
	//cout<<ss<<endl;
	return ss;
}
int main()
{
	int x,y;
	x=y=0;
	cin>>n>>p;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]%2;
		if(a[i]==0)
			x++;
		else
			y++;
	}
	//cout<<x<<" "<<y<<endl;
	//cout<<11111<<endl;
	if(x!=0)
	{
		k=pow(2,x);
	}
	else
	{
		k=1;
	}
	if(p==1)
	{
		for(i=1;i<=y;i++)
		{
			if(i%2==1)
			{
				sum+=check(y,y-i)/check(i,0);
			//	cout<<" "<<i<<" "<<check(y,y-i)<<" "<<check(i,0)<<endl;
			}
			//cout<<sum<<endl;
		}
		//cout<<sum<<endl;
		sum=sum*k;
		//cout<<"ss"<<sum<<endl;
		//cout<<k<<endl;
		//cout<<"aaaa"<<(17592186044416-sum)<<endl;
	}
	else
	{
		//cout<<111111<<endl;
		for(i=1;i<=y;i++)
		{
			if(i%2==0)
			{
				sum+=check(y,y-i)/check(i,0);
			}
		}
		//cout<<sum<<endl;
		if(x==0)
			sum+=1;
		else
			sum+=sum*k;
	}
	printf("%.0lf\n",sum);
}
