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
//数组定义，初始化
//讲字符，长度，比较，复制，连接
//gets，puts，getchar
//getchar()用在scanf和gets之间，因为scanf不读取换行符，gets读换行符，getchar()目的是消去换行符，puts()printf()无区别
//数组太大开到局部内，会爆栈，程序不会给你那么多内存
/*char a[50],b[50];
int main()
{
	int i;
	scanf("%s",a);
	scanf("%s",b);
	int n = strlen(a);
	printf("%d\n",n);
	strcpy(b,a);
	把字符串a赋值给b;
	for(i=0;i<n;i++)
		b[i]=a[i];
	*/
	//printf("%d\n",a[n]);
	/*if(strcmp(a,b)==1)
	{
		printf("%s",a);
	}
	else
		printf("%s",b);
	当a大于b，返回值大于0
	当a等于b，返回值等于0
	当a小于b，返回值小于0
	*/
	/*
		strcat(a,b);
		把b连接到a的后面

	*/
	//return 0;
