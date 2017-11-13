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

int deep[20][100005];
int sorted[100005];
int son[20][100005];
void build(int l,int r,int de)
{
	if(l == r)
		return;
	int mid = (l + r)/2;
	int pos = mid - l + 1;
	for(int i = l;i <= r;i++)
		if(deep[de][i] < sorted[mid])
			pos--;
	int lpos = l;
	int rpos = mid + 1;
	for(int i=l;i<=r;i++)
	{
		if(deep[de][i]<sorted[mid])
			deep[de+1][lpos++]=deep[de][i];
		else if(deep[de][i] == sorted[mid]&&pos>0)
		{
			pos--;
			deep[de+1][lpos++]=deep[de][i];
		}
		else
			deep[de+1][rpos++]=deep[de][i];
		son[de][i]=son[de][l-1] + lpos-l;
	}
	build(l,mid,de+1);
	build(mid+1,r,de+1);
}
int query(int L,int R,int l,int r,int de,int K)
{
	int newl,newr;
	if(l == r)
		return deep[de][l];
	int mid = (L + R) / 2;
	int cnt = son[de][r] - son[de][l-1];
	if(cnt >= K)
	{
		newl = L + son[de][l-1] - son[de][L-1];//左边不在所查询区间的个数+L
		newr = newl + cnt - 1;
		return query(L,mid,newl,newr,de+1,K);//每层的操作是一半一半进行的，所以在大区间[L,R]时候根据cnt的大小边界取mid
	}
	else
	{
		newr = r + son[de][R] - son[de][r];
		newl = newr - (r - l - cnt);
		return query(mid+1,R,newl,newr,de+1,K-cnt);
	}
}
int main()
{
	int T,n,q,i,l,r,cnt;
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		memset(sorted,0,sizeof(sorted));
		memset(deep,0,sizeof(deep));
		memset(son,0,sizeof(son));
		for(i=1;i<=n;i++)
		{
			cin>>deep[0][i];
			sorted[i]=deep[0][i];
		}
		sort(sorted+1,sorted+1+n);
		build(1,n,0);
		while(q--)
		{
			cin>>l>>r>>cnt;
			cout<<query(1,n,l,r,0,cnt)<<endl;//表示长度，区间，层数，第几大
		}
	}
	return 0;
}
