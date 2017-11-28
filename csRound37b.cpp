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



 const int N=2e5+10;
 int n,m;
 int a[N],ct[N];
 int pos[N],l[N],r[N],ans[N];
 vector<int>ll[N],rr[N];
 void init(){
   memset(a,0,sizeof(a));
   memset(ct,0,sizeof(ct));
    memset(pos,0,sizeof(pos));
}
 int lowbit(int x){
   return x&(-x);
 }
 void add(int x){
  while(x<=n){
    ct[x]++;
     x+=lowbit(x);
  }
 }
int getsum(int x){
    int ans=0;
    while(x>0){
        ans+=ct[x];
        x-=lowbit(x);
    }
    return ans;
 }
int main(){
   while(~scanf("%d%d",&n,&m)){
      init();
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
        pos[a[i]]=i;
     }
     for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
        ll[l[i]].push_back(i);
         rr[r[i]].push_back(i);
     }
     for(int i=1;i<=n;i++){
     for(int j=0;j<ll[i].size();j++){
         ans[ll[i][j]]-=getsum(r[ll[i][j]])-getsum(i-1);
     }
     for(int j=1;j*a[i]<=n;j++){
         add(pos[j*a[i]]);
    }
      for(int j=0;j<rr[i].size();j++){
         ans[rr[i][j]]+=getsum(i)-getsum(l[rr[i][j]]-1);
      }
     }
  }
 }
