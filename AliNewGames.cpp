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
	int x,y;
}b[50];
bool tu[50][50];
int ans,n,m,x,y,i;
//map<point,string> p[50];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		tu[x+3][y+3]=true;
	}
	for(i=1;i<=m;i++)
	{
		cin>>b[i].x>>b[i].y;
	}
	ans=0;
	if(tu[4][3])
	{
		if(tu[5][3]&&tu[6][3])
			ans++;
		if(tu[4][4]&&tu[4][2])
			ans++;
	}
	if(tu[2][3])
	{
		if(tu[1][3]&&tu[0][3])
			ans++;
		if(tu[2][4]&&tu[2][2])
			ans++;
	}
	if(tu[5][3])
		if(tu[5][5]&&tu[5][1])
			ans++;
	if(tu[1][3])
		if(tu[1][5]&&tu[1][1])
			ans++;
	if(tu[0][3])
		if(tu[0][6]&&tu[0][0])
			ans++;
	if(tu[6][3])
		if(tu[6][6]&&tu[6][0])
			ans++;
	if(tu[3][4])
	{
		if(tu[4][4]&&tu[2][4])
			ans++;
		if(tu[3][5]&&tu[3][6])
			ans++;
	}
	if(tu[3][2])
	{	
		if(tu[2][2]&&tu[4][2])
			ans++;
		if(tu[3][1]&&tu[3][0])
			ans++;
	}
	if(tu[3][5])
		if(tu[5][5]&&tu[1][5])
			ans++;
	if(tu[3][1])
		if(tu[1][5]&&tu[1][1])
			ans++;
	if(tu[3][6])
		if(tu[6][6]&&tu[6][0])
			ans++;
	if(tu[3][0])
		if(tu[0][0]&&tu[0][6])
			ans++;
	if(tu[4][4]&&tu[6][6]&&tu[5][5])
		ans++;
	if(tu[1][1]&&tu[2][2]&&tu[0][0])
		ans++;
	if(tu[4][2]&&tu[5][1]&&tu[6][0])
		ans++;
	if(tu[2][4]&&tu[1][5]&&tu[0][6])
		ans++;
	cout<<ans<<endl;
}
