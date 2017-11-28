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

char tu[10][10],s;
int i,j,T,sum;
bool flag;
int main()
{
	cin>>T;
	while(T--)
	{
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
				cin>>tu[i][j];
		cin>>s;
		flag=0;
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(tu[i][j]==s)
				{
					if(tu[i][j-1]==s&&tu[i][j+1]=='.'||tu[i][j-1]=='.'&&tu[i][j+1]==s||tu[i][j-1]==s&&tu[i][j-2]=='.'||tu[i][j-1]=='.'&&tu[i][j-2]==s||tu[i][j+2]==s&&tu[i][j+1]=='.'||tu[i][j+2]=='.'&&tu[i][j+1]==s)
						flag=1;
					if(tu[i+1][j]==s&&tu[i-1][j]=='.'||tu[i+1][j]=='.'&&tu[i-1][j]==s||tu[i+1][j]==s&&tu[i+2][j]=='.'||tu[i+1][j]=='.'&&tu[i+2][j]==s||tu[i-2][j]==s&&tu[i-1][j]=='.'||tu[i-2][j]=='.'&&tu[i-1][j]==s)
						flag=1;
					if(tu[i+1][j+1]==s&&tu[i-1][j-1]=='.'||tu[i+1][j+1]=='.'&&tu[i-1][j-1]==s||tu[i+1][j+1]==s&&tu[i+2][j+2]=='.'||tu[i+1][j+1]=='.'&&tu[i+2][j+2]==s||tu[i-2][j-2]==s&&tu[i-1][j-1]=='.'||tu[i-2][j-2]=='.'&&tu[i-1][j-1]==s)
						flag=1;
					if(tu[i+1][j-1]==s&&tu[i-1][j+1]=='.'||tu[i+1][j-1]=='.'&&tu[i-1][j+1]==s||tu[i+1][j-1]==s&&tu[i+2][j-2]=='.'||tu[i+1][j-1]=='.'&&tu[i+2][j-2]==s||tu[i-2][j+2]==s&&tu[i-1][j+1]=='.'||tu[i-2][j+2]=='.'&&tu[i-1][j+1]==s)
						flag=1;
				}
			}
		}
		if(flag==1)
		{
			cout<<"Kim win!"<<endl;
			continue;
		}
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				sum=0;
				if(tu[i][j]=='.')
				{
					if(tu[i][j-1]==s&&tu[i][j+1]=='.'||tu[i][j-1]=='.'&&tu[i][j+1]==s||tu[i][j-1]==s&&tu[i][j-2]=='.'||tu[i][j-1]=='.'&&tu[i][j-2]==s||tu[i][j+2]==s&&tu[i][j+1]=='.'||tu[i][j+2]=='.'&&tu[i][j+1]==s)
						sum++;
					if(tu[i+1][j]==s&&tu[i-1][j]=='.'||tu[i+1][j]=='.'&&tu[i-1][j]==s||tu[i+1][j]==s&&tu[i+2][j]=='.'||tu[i+1][j]=='.'&&tu[i+2][j]==s||tu[i-2][j]==s&&tu[i-1][j]=='.'||tu[i-2][j]=='.'&&tu[i-1][j]==s)
						sum++;
					if(tu[i+1][j+1]==s&&tu[i-1][j-1]=='.'||tu[i+1][j+1]=='.'&&tu[i-1][j-1]==s||tu[i+1][j+1]==s&&tu[i+2][j+2]=='.'||tu[i+1][j+1]=='.'&&tu[i+2][j+2]==s||tu[i-2][j-2]==s&&tu[i-1][j-1]=='.'||tu[i-2][j-2]=='.'&&tu[i-1][j-1]==s)
						sum++;
					if(tu[i+1][j-1]==s&&tu[i-1][j+1]=='.'||tu[i+1][j-1]=='.'&&tu[i-1][j+1]==s||tu[i+1][j-1]==s&&tu[i+2][j-2]=='.'||tu[i+1][j-1]=='.'&&tu[i+2][j-2]==s||tu[i-2][j+2]==s&&tu[i-1][j+1]=='.'||tu[i-2][j+2]=='.'&&tu[i-1][j+1]==s)
						sum++;
				}
				if(sum>=2)
					flag=1;
			}
		}
		if(flag==1)
		{
			cout<<"Kim win!"<<endl;
		}
		else
		{
			cout<<"Cannot win!"<<endl;
		}

	}
}
