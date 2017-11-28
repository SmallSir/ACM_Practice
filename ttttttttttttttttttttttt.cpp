#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int VM=120;
const int EM=10010;
struct Edge{
    int u,v,cap;
    bool operator < (const Edge& a)const {
        return cap<a.cap;
    }
}edge[EM<<1];
int n,m,flag,ans,father[VM];
void makeSet(){
    for(int i=1;i<=n;i++)
        father[i]=i;
}
int findSet(int x){
    if(x==father[x]) return x;
    else return  father[x]=findSet(father[x]);
}
void Kruskal(){
    makeSet();
    sort(edge,edge+m);
    int path[EM],cnt=0;
    ans=0;
    for(int i=0;i<m;i++){
        int u=findSet(edge[i].u);
        int v=findSet(edge[i].v);
        if(u!=v){
            father[v]=u; ans+=edge[i].cap;
            path[cnt++]=i;      //记录路径
        }
    }
    cout<<ans<<endl;
    for(int k=0;k<cnt;k++){     //枚举去掉每一条边
        makeSet();
        int sum=0,j=0;
        for(int i=0;i<m;i++){
            if(i==path[k]) continue;
            int u=findSet(edge[i].u),v=findSet(edge[i].v);
            if(u!=v){
                father[v]=u;
                sum+=edge[i].cap;
                j++;
            }
        }
        if(j==n-1 && sum==ans){     //判断是否能构成树 且 是否与最小生成树相等
            flag=0;return ;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].cap);
        flag=1;
        Kruskal();
        if(flag) printf("%d\n",ans);
        else printf("Not Unique!\n");
    }
    return 0;
}
