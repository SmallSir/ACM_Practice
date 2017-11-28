#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MaxN = 20000;
int T,n,m,prime[MaxN + 5],tot;
bool flag[MaxN + 5];

int lalala(int x){
	int kkk = sqrt(x);
	if(kkk != sqrt(x)) kkk += 1;
	for(int i = 0; i <= kkk ; i++){
		for(int j = 0; j <= kkk; j++){
			if(i * i + j * j == x)  return true;
		}
	}
	return false;
}

int solve(int s){
	for(int i = 1; i <= tot;i++){
		if(s == prime[i]) return true;
	}
	return false;
}

int main()
{
	flag[1] = 1; tot = 0;
	for(int i = 2; i <= 20000; i++){
		if(flag[i] == 0) prime[++tot] = i;
		for(int j = 1; j <= tot; j++)
		{
			if(prime[j] * i > 20000) break;
			flag[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&m,&n);
		int k = m * m + n * n;
		if(solve(k)) printf("P\n");
		else{
			int kk = sqrt(k),ok = 0;
			if(kk != sqrt(k)) kk += 1;
			for(int x1 = 2; x1 <= kk; x1++){
				if(k % x1) continue;
				int x2 = k / x1;
				if(lalala(x1) && lalala(x2)){ printf("C\n");ok = 1; break;}
			}
			if(ok == 0) printf("P\n");
		}
	}
	return 0;
}
