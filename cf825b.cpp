#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

char tu[20][20];
bool digui1(int x,int y,int flag,int num)//ºá×Å
{
	if(x<1||x>10||y<1||y>10||flag>1||tu[x][y]=='O')
		return 0;
	if(flag+num==5)
		return 1;
	if(tu[x][y+1]=='.')
		return digui1(x,y+1,flag+1,num);
	else if(tu[x][y+1]=='X')
		return digui1(x,y+1,flag,num+1);
	return 0;
}
bool digui2(int x,int y,int flag,int num)//Êú×Å
{
	if(x<1||x>10||y<1||y>10||flag>1||tu[x][y]=='O')
		return 0;
	if(flag+num==5)
		return 1;	
	if(tu[x+1][y]=='.')
		return digui2(x+1,y,flag+1,num);
	else if(tu[x+1][y]=='X')
		return digui2(x+1,y,flag,num+1);
	return 0;
}
bool digui3(int x,int y,int flag,int num)//ÍùÓÒĞ±
{
	if(x<1||x>10||y<1||y>10||flag>1||tu[x][y]=='O')
		return 0;
	if(flag+num==5)
		return 1;
	if(tu[x+1][y+1]=='.')
		return digui3(x+1,y+1,flag+1,num);
	else if(tu[x+1][y+1]=='X')
		return digui3(x+1,y+1,flag,num+1);
	return 0;
}
bool digui4(int x,int y,int flag,int num)//Íù×óĞ±
{
	if(x<1||x>10||y<1||y>10||flag>1||tu[x][y]=='O')
		return 0;
	if(flag+num==5)
		return 1;
	if(tu[x+1][y-1]=='.')
		return digui4(x+1,y-1,flag+1,num);
	else if(tu[x+1][y-1]=='X')
		return digui4(x+1,y-1,flag,num+1);
	return 0;
}
int main()
{
	int i,j;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			cin>>tu[i][j];
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			if(tu[i][j]=='O')
				continue;
			if(tu[i][j]=='.')
			{
				if(digui1(i,j,1,0)||digui2(i,j,1,0)||digui3(i,j,1,0)||digui4(i,j,1,0))
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}
			else
			{
				if(digui1(i,j,0,1)||digui2(i,j,0,1)||digui3(i,j,0,1)||digui4(i,j,0,1))
				{
					cout<<"YES"<<endl;
					return 0;
				}	
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
