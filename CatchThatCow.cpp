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

/*start:2017/5/20 16:03*/
/*end:2017/5/20 16:14*/
struct point
{
	int k,ans;
}p,pp;
queue<point> qua;
bool a[100005];
int n,k;
void bfs()
{
	p.k=n;
	p.ans=0;
	qua.push(p);
	while(!qua.empty())
	{
		pp=qua.front();
		qua.pop();
		if(pp.k==k)
		{
			cout<<pp.ans<<endl;
			break;
		}
		for(int i=1;i<=3;i++)
		{
			if(i==1)
				p.k=pp.k+1;
			else if(i==2)
				p.k=pp.k-1;
			else
				p.k=pp.k*2;
			if(p.k<0||p.k>100000||a[p.k])
				continue;
			a[p.k]=true;
			p.ans=pp.ans+1;
			qua.push(p);
		}
	}
	//cout<<(pp.ans)<<endl;
	return;
}
int main()
{
	memset(a,0,sizeof(a));
	cin>>n>>k;
	if(n>=k)
	{
		cout<<n-k<<endl;
		return 0;
	}
	a[n]=true;
	bfs();
}
