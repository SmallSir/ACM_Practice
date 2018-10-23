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

int a[50],n;
void swap(int x,int y)
{
	int tmp;
	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

//¿ìÅÅ
/*void quick(int left,int right)
{
	if(left >= right)
		return;
	int i,tmp;
	int k = a[right];
	int t = left - 1;
	for(int i = left;i < right;i++)
	{
		if(a[i] <= k)
		{
			swap(i,++t);
		}
	}
	swap(right,t+1);
	quick(left,t);
	quick(t+1,right);
}*/
//²åÈëÅÅÐò
/*
void quick(int left,int right)
{
	int i,j,k;
	for(i=left;i<=right;i++)
	{
		k = a[i];
		j = i -1;
		while(j >=0 &&a[j] >k)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = k;
	}
}*/
void quick(int left,int right)
{
	int i,j,k;
	for(i=left;i<=right;i++)
	{
	    int k = a[i];
		int l = 0,r = i-1;
		while(l<=r)
		{
			int mid = (l+r)/2;
			if(a[mid] > k)
				l = mid - 1;
			else
				r = mid + 1;
			cout<<l<<" "<<r<<endl;
		}
		for(j = i-1;j>=l;j--)
		{
			a[j+1] = a[j];
		}
		a[left] = k;
	}
}
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quick(0,n-1);
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
