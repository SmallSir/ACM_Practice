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
const int inf = -32768;
const int INF = 32767;
//strattime:2017/10/9 21:00
//endtime:2017/10/9 21:07
char sss[50];

struct youzi{
	int l;
	int r;
}t[1500],ee[1500];

bool lizi(int x, int y, int xx, int yy){
	if((x <= yy + 1 && x >= xx - 1) || (y <= yy + 1 && y >= xx - 1)){
		return true;
	}
	return false;
}

bool cmp(youzi p, youzi q){
	if(p.l == q.l) return p.r < q.r;
	return p.l < q.l;
}

int main()
{
	freopen("hard.in","r",stdin);
	freopen("hard.out","w",stdout);
	int k,kk,x,y,T = 1,tt = 0,cnt = 0;
	while(T){
		k = 0,kk = 0;
		gets(sss);
		int str = strlen(sss);
		if(sss[str - 1] != '|') T = 0;
		x = inf, y = INF;
		int xx, yy;
		for(int i = 0; i < str; i++){
			int num = 0;
			if(sss[i] == '>')
				k = 1;
			else if(sss[i] == '<')
				kk = 1;
			else continue;
			int pos, q = 1;
			for(int j = i + 3; sss[j] != ' ' && j < str ; j++)
			{
				pos = j;
			}
			for(int j = pos; j > i + 3; j--)
			{
				int num_ = (sss[j] - '0') * q;
				num += num_;
				q *= 10;
			}
			if(sss[i + 3] == '-') num = (-num);
			else num += (sss[i + 3] - '0') * q;
		//	printf("num = %d\n", num);
			if(num >= inf && num <= INF){
				if(k){
					x = num; 
					k = 0;
				}
				if(kk){
					y = num;
					kk = 0;
				}
			}
		}
		if(x > y) {
			tt = 1;
			continue;
		}
		bool ok = 0;
		for(int i = 1;i <= cnt; i++){
			if(lizi(x,y,t[i].l, t[i].r)){
				x = min(x, t[i].l);
				y = max(y, t[i].r);
				t[i].l = x;
				t[i].r = y;
				ok = 1;
			}
		}
		if(!ok){ 
			t[++cnt].l = x;
			t[cnt].r = y;
		}
	}
//	printf("cnt = %d\n", cnt);
	if(cnt == 0){
	printf("false\n");
		return 0;
	}
	sort(t + 1, t + cnt + 1,cmp);
	ee[1].l = t[1].l;
	ee[1].r = t[1].r;
	int eee = 1;
	for(int i = 2; i <= cnt; i++){
		bool flag = 0;
		for(int j = 1; j <= eee; j++){
			if(lizi(t[i].l, t[i].r, ee[j].l,ee[j].r)){
				ee[j].l = min(ee[j].l, t[i].l);
				ee[j].r = max(ee[j].r, t[i].r);
				flag = 0;
			}
			else{
				flag = 1;
			}
		}
		if(flag){
			//printf("i = %d", i);
			ee[++eee].l = t[i].l;
			ee[eee].r = t[i].r;
		}
	}
	//	printf("eee = %d\n", eee);
	for(int i = 1; i <= eee; i++){
		if(ee[1].l <= inf && ee[1].r >= INF){
			printf("true\n");
			return 0;
		}
		else if(ee[i].l <= inf){
			if( i != eee)printf("x <= %d ||\n",ee[i].r);
			else  printf("x <= %d \n",ee[i].r);
		}
		else if(ee[i].r >= INF){
			if( i != eee)printf("x >= %d ||\n",ee[i].l);
			else  printf("x >= %d \n",ee[i].l);
		}
		else{
			if( i != eee)printf("x >= %d && x <= %d ||\n",ee[i].l,ee[i].r);
			else  printf("x >= %d && x <= %d\n",ee[i].l,ee[i].r);
		}
	}
	return 0;
}
