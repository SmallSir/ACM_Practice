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
typedef long long LL;

int b[30],L;
bool check[30];
LL a[30][100010];
LL pt=1e9+7;
LL pows[100010];
LL sum[100010],ans;
bool cmp(int x,int y)
{
	for(int i=L-1;i>=0;i--)
	{
		if(a[x][i]!=a[y][i])
			return a[x][i]<a[y][i];
	}
	return 0;
}

int main()
{
	int i,j,len,n;
	int k=0;
	string str;
	pows[0]=1;
	for(i=1;i<100005;i++)
	{
		pows[i]=pows[i-1]*26%pt;
	}
	while(cin>>n)
	{
	//	int L;
		L=0;
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(check,0,sizeof(check));
		for(i=1;i<=n;i++)
		{
			cin>>str;
			len=str.length();
			for(j=0;j<len;j++)
			{
				if(len>1)
					check[str[0]-'a']=1;
				a[str[j]-'a'][len-j-1]++;
				//cout<<pows[len-j-1]<<endl;
				sum[str[j]-'a']=(sum[str[j]-'a']+pows[len-j-1])%pt;
			}
			L=max(L,len);
		}
		for(i=0;i<26;i++)
		{
			for(j=0;j<L;j++)
			{
				a[i][j+1]+=a[i][j]/26;
				a[i][j]%=26;
			}
			while(a[i][L])//这是个坑考虑到最高位置满26后要上进一位
			{
				a[i][L+1]+=a[i][L]/26;
				a[i][L++]%=26;//这里L++的原因是这个位置由于原先L的位置满26进位，所以要考虑进去，同理在sort中也是
			}
			b[i]=i;
		}
		sort(b,b+26,cmp);
		int cnt=-1;
		for(i=0;i<26;i++)
		{
			if(check[b[i]]==0)
			{
				cnt=b[i];
				break;
			}
		}
		ans=0;
		int x=25;
		for(i=25;i>=0;i--)
		{
			if(b[i]!=cnt)
			{
				ans=(ans+(x--)*sum[b[i]])%pt;
			}
		}
		cout<<"Case #"<<++k<<": "<<ans<<endl;
	}
}
