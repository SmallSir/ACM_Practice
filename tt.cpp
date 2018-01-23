#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int i,k,j,m,p,q,sum=0;
	char n[100];
	scanf("%s",n);
	k=strlen(n);
	for(i=0;i<k-4;i++){
		if(n[i]='D'&&n[i+1]=='a'&&n[i+2]=='n'&&n[i+3]=='i'&&n[i+4]=='l') sum++;
	}

	for(j=0;j<k-4;j++){
		if(n[j]='S'&&n[j+1]=='l'&&n[j+2]=='a'&&n[j+3]=='v'&&n[j+4]=='a') sum++;
	}

	for(m=0;m<k-5;m++){
		if(n[m]='N'&&n[m+1]=='i'&&n[m+2]=='k'&&n[i+3]=='i'&&n[m+4]=='t'&&n[m+5]=='a') sum++;
	}
	for(p=0;p<k-3;p++){
		if(n[p]='O'&&n[p+1]=='l'&&n[p+2]=='y'&&n[p+3]=='a') sum++;
	}

	for(q=0;q<k-2;q++){
		if(n[q]='A'&&n[q+1]=='n'&&n[q+2]=='n') sum++;
	}
	if(sum==1)printf("Yes\n");
	else printf("No\n");
}

