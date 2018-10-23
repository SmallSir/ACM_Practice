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

struct point
{
	LL value;
	int index;
	friend bool operator< (point n1, point n2)  
    {  
    	if(n1.value == n2.value)
    		return n1.index >n2.index;

        return n1.value> n2.value;  
    }  
}a[150005],x,y;
int n,i,k,flag;
priority_queue<point> qua;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].value;
		a[i].index = i;
		qua.push(a[i]);
	}
	k=0;
	while(!qua.empty())
	{
		x=qua.top();qua.pop();
		if(qua.size()==0)
			break;
		y=qua.top();qua.pop();
		if(x.value == y.value)
		{
			k++;
			y.value*=2;
			a[y.index].value*=2;
			x.value = 0;
			a[x.index].value=0;
		}
		qua.push(y);
	}
	cout<<n-k<<endl;
	for(i=1;i<=n;i++)
	{
		if(a[i].value!=0)
			cout<<a[i].value<<" ";
	}
	cout<<endl;
 return 0;
}
