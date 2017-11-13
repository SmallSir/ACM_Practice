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
int n, all;
int check[200005], a[200005], b[200005];
int cnt[200005];
vector<int> tu[200005];
int gcd(int x, int y){
	if(y == 0) return x;
	else return gcd(y, x % y);
}
void dfs(int x, int fa, int d){
	b[x] = gcd(b[fa], a[x]);
	check[x] = b[fa];
	for (int i = 1; i * i <= a[x]; i++){
		if (a[x] % i == 0) {
			int now = i;
			if (cnt[now] >= d - 2) check[x] = max(check[x], now);
			now = a[x] / i;
			if (cnt[now] >= d - 2) check[x] = max(check[x], now);
			if (i * i == a[x]) cnt[i]++;
			else cnt[i]++, cnt[a[x] / i]++;
		}
	}
	for(int i=0;i<tu[x].size();i++)
	{
		int k=tu[x][i];
		if(k==fa)
			continue;
		else
			dfs(k,x,d+1);
	}
	for (int i = 1; i * i <= a[x]; i++){
		if (a[x] % i == 0) {
			if (i * i == a[x]) cnt[i]--;
			else cnt[i]--, cnt[a[x] / i]--;
		}
	}
}
int main()
{
	cin>>n;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1;i <= n;i++) 
			cin>>a[i];
		for(int i = 1;i <= n - 1;i++){
			int x,y;
			cin>>x>>y;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		dfs(1, 0, 1);
		for(int i = 1;i <= n;i++)
			cout<<check[i]<<" ";
		cout<<endl;
}
