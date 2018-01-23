#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a,b,c,T;
int s[55][10000];

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c,&T);
	for(int i = 1; i <= n; i++) scanf("%d",&s[i][0]);
	for(int i = 0; i <= T; i++) s[0][i] = 0;
	for(int i = 1; i <= T; i++){
		for(int j = 1; j <= n; j++){
			s[j][i] = (a * s[j - 1][i-1] + b * s[j][i-1] + c * s[j + 1][i-1]) % m;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ",s[i][T]); 
	printf ("\n");
	return 0;
}
