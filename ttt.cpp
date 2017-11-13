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

char a[2][55];
int n,ans,cnt,ans1;
LL sum;
LL pt =1e9+7;
long long int fast_pow(long long int x,long long int y)  
{  
    long long int res;  
    res=1;  
    while(y!=0)  
    {  
        if(y&1) res=(res*x)%pt;  
        y>>=1;  
        x=(x*x)%pt;  
    }  
    return res;  
} 
int main()
{
	int i;
	string str;
	string str1;
	cin>>n;
	cin>>str;
	cin>>str1;
	for(i=0;i<n;i++)
	{
		if(i==n)
			break;
		a[1][i+1]=str[i];
		a[2][i+1]=str1[i];
	}
	ans=0;
	cnt = 0;
	for(i=1;i<=n;i++)
	{
		if(i!=1&&a[1][i]==a[2][i])
		{
			if(a[1][i-1]!=a[2][i-1])
				cnt++;
			ans1++;
		}
		else
			ans+=2;
	}
	if(ans1!=0&&cnt==0)
		cnt++;
	sum = fast_pow(2,ans-cnt-1)*3%pt;
	cout<<sum<<endl;
	return 0;
}
