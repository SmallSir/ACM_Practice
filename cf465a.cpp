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

int n,sum,i;
int main()
{
	cin>>n;
	sum=0;
	for(i=1;i<n;i++)
	{
		if((n-i)%i==0)
			sum++;
	}
	cout<<sum<<endl;
 return 0;
}
