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
				dp[i][j]=-1.0;//dp[i][j]��ʾ����i���Ŀǰ��״̬��j
		dp[0][0]=0;
		//int sum;	
		for(i=1;i<=m;i++)
		{
			for(j=0;j<(1<<n);j++)
			{
				if(dp[i-1][j]<0) continue;
				for(k=0;k<n;k++)
				{
					if(!(j&(1<<k)))//��ʱ������Ƿ��Ѿ�����һ����������
					{
						st=j|(1<<k);//ͬ����ʱ�������������һ�ֵ��������
						if(st==(1<<n)-1) st=0;//����nΪ2 ��001->100��һ�����11Ҳ���������˶��������ˣ����Ծ�˵�����ֵ��������������
						dp[i][st]=max(dp[i][st],dp[i-1][j]+a[k+1][i]);//st���״̬��ͨ��j���״̬ת������ģ���k+1��ԭ���ǣ����ǵ�1���Ƶ�λ����ʵ��λ����+1����˵ĸ���ֵ����Ϊ��������һ��2��0�η�������
						
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


