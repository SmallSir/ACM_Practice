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
void bubbleSort()
{
	int tmp;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void selectionSort()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		int check = i;
		int Max = a[i];
		for(j=i+1;j<=n;j++)
		{
			if(Max > a[j])
			{
				Max = a[j];
				check = j;
			}
		}
		int tmp = a[check];
		a[check] = a[i];
		a[i] = tmp;
	}
}

void insertionSort()
{
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		temp = a[i];
		for(j=i-1;j>=1;j--)
		{
			if(a[j] <= temp)
				break;
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
}


void mergeSort(int l,int r)
{
	int b[50];
	if(l == r)
		return ;
	int mid = (r + l) / 2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	int i = l;
	int j = mid+1;
	memset(b,0,sizeof(b));
	int tmp = l;
	for(;;)
	{
		if(i > mid||j > r)
			break;
		if(a[i] > a[j])
		{
			b[tmp++] = a[j];j++;
		}
		else
		{
			b[tmp++] = a[i];i++;
		}
	}
	if(i <= mid)
	{
		for(j = i ;j <= mid;j++)
			b[tmp++] = a[j];
	}
	else
	{
		for(i = j;i<=r;i++)
			b[tmp++] = a[i];
	}
	for(i=l;i<=r;i++)
	{
		a[i] = b[i];
	}
}

void quickSort(int l,int r)
{
	if(l >= r)
		return;
	int mid = a[(l+r)/2];
	int x = l;
	int y = r;
	while(x <= y)
	{
		while(a[x] < mid) x++;
		while(a[y] > mid) y--;
		if(x <= y)
		{
			int tmp;
			tmp = a[x];
			a[x] = a[y];
			a[y] = tmp;
			x++;
			y--;
		}
	}
	quickSort(l,y);
	quickSort(x,r);
}


void heapify(int x,int len)//µ˜’˚∂—
{
	int left = x * 2;
	int right = left + 1;
	int Max = x;
	
	if(left <= len && a[left] > a[Max])
		Max = left;
	if(right <= len && a[right] > a[Max])
		Max = right;
	if(Max != x)
	{
		int temp = a[x];
		a[x] = a[Max];
		a[Max] = temp;
		heapify(Max,len);
	}
}
void buildheap(int x)//¥¥Ω®∂—
{
	for(int i = (x / 2);i>=1;i--)
	{
		heapify(i,x);
	}
}
void heapSort()
{
	int k = n;
	buildheap(k);
	for(int i = n;i >=1;i--)
	{
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		k--;
		heapify(1,k);
	}
}




int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	//√∞≈›
	//bubbleSort();
	//—°‘Ò≈≈–Ú
	//selectionSort();
	//≤Â»Î≈≈–Ú
	//insertionSort();
	//πÈ≤¢≈≈–Ú
	//mergeSort(1,n);
	//øÏ≈≈
	//quickSort(1,n);
	//∂—≈≈–Ú
	//heapSort();
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
