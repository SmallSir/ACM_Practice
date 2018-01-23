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
using namespace std; 


/*start:17/5/19 14:34*/
/*end:17/5/19   14:50   */
map<int,bool> a;
int ans,n,xx;
bool check(int x)
{
	int T=25;
	int i=(x/50)%475;
	while(T--)
	{
		i=(i*96+42)%475;
		//cout<<26+i<<endl;
		if(26+i==n)
			return true;
	}
	return false;
}

int main()
{
	int y,x;
	int ans1,ans2;
	cin>>n>>x>>y;
	ans=0;
	if(x<y)
	{
		ans+=(y-x)/100;
		if((y-x)%100!=0)
		{
			ans++;
		}
		x+=100*ans;
	}
	if(check(x))
	{
		cout<<ans<<endl;
		return 0;
	}
	xx=x;
	for(;;)
	{
		xx-=50;
		if(xx<y)
			break;
		if(check(xx))
		{
			//cout<<1111<<endl;
			cout<<ans<<endl;
			return 0;
		}
	}
	int k=0;
	for(;;)
	{
		x+=50;
		k++;
		if(check(x))
		{
			break;
		}
	}
	cout<<ans+(k+1)/2<<endl;
}
