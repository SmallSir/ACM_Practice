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

/*start:2017/5/20 16:48*/
/*end:2017/5/20 16:14*/
char a[2005],b[2005];
int n;
bool check(int x,int y)
{
	if(y<=x)
		return true;
	if(a[x]<a[y])
		return true;
	else if(a[x]>a[y])
		return false;
	else
		return check(x-1,y+1);
}
int main()
{
	int l,r,ans,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l=1;
	r=n;
	ans=0;
	for(;;)
	{
		if(a[l]>a[r])
		{
			b[++ans]=a[r];
			r--;
		}
		if(a[l]<a[r])
		{
			b[++ans]=a[l];
			l++;
		}
		else
		{
			if(check(l+1,r-1))
			{
				b[++ans]=a[l];
				l++;
			}
			else
			{
				b[++ans]=a[r];
				r--;
			}
			//b[++ans]=a[check(l+1,r-1)];
		}
		if(ans==n)break;
	}
	for(i=1;i<=n;i++)
	{
		cout<<b[i];
		if(i%80==0)
			cout<<endl;
	}
	if(n%80!=0)
		cout<<endl;
}

