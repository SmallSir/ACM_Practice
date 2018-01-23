#include <bits/stdc++.h>
using namespace std;

	int  b[27];
int main()
{
	char a[120];
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		b[a[i]-'a']++;
		cout<<a[i]-'a'<<endl;
	}
	cout<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
