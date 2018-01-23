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
int n , a , b , c , d;
int main()
{
	cin >> n >> a >> b >>c >>d;
	int t1 = 0 , t2 = 0;
	if(a == 0) t1 = b;
	else if(a == n) t1 = 3 * n - b;
	else if(b == 0) t1 = 4 * n - a;
	else t1 = n + a;
	if(c == 0) t2 = b;
	else if(c == n) t2 = 3 * n - d;
	else if(d == 0) t2 = 4 * n - c;
	else t2 = n + c;
	printf("%d\n" , min(abs(t1 - t2) , 4 * n - abs(t1 - t2)));

}
