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

int a[100005];
int n,k,i,j,x,MAX;
LL sum;
map<int,int> tu;
int main()
{
	MAX=0;
	scanf("%d%d",&n,&k);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=tu[a[i] ^ k];
		tu[a[i]]++;
	}	
	cout<<sum<<endl;
}
