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

double sum;
double dp[1050][1050],a[20][1050];
int n,m,i,j,k,t,T,st;
int main()
{
	t=0;
	cin>>T;
	while(T--)
	{
		//n=m=k=0;
		//sum=0;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		t++;
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];
		//int ans=(1<<n)-1;
		for(i=0;i<1050;i++)
			for(j=0;j<1050;j++)
				dp[i][j]=-1.0;//dp[i][j]表示做了i题后目前的状态是j
		dp[0][0]=0;
		//int sum;	
		for(i=1;i<=m;i++)
		{
			for(j=0;j<(1<<n);j++)
			{
				if(dp[i-1][j]<0) continue;
				for(k=0;k<n;k++)
				{
					if(!(j&(1<<k)))//此时这个人是否已经在这一轮中做过题
					{
						st=j|(1<<k);//同步此时这个人做题后的这一轮的做题情况
						if(st==(1<<n)-1) st=0;//假设n为2 从001->100减一后就是11也就是两个人都做过题了，所以就说明这轮的做题情况结束了
						dp[i][st]=max(dp[i][st],dp[i-1][j]+a[k+1][i]);//st这个状态是通过j这个状态转变而来的，而k+1的原因是，考虑到1左移的位数其实是位数加+1这个人的概率值，因为二进制有一个2的0次方的问题
						
					}
				}
			}
		}
		sum=0;
		for(i=0;i<(1<<n);i++)
		{
			sum=max(sum,dp[m][i]);
			//cout<<"hahah   "<<dp[m][i]<<endl;
		}
		printf("Case #%d: %.5lf\n", t, sum);
	}
}


