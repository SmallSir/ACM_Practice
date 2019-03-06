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

int a[30],check[30];
vector<int> tu[30];
int best[30],n,m,sum;
int dfs(int x)
{
    check[x] = 1;
    if(a[x]!= 0)
        return a[x];
    a[x]+=tu[x].size();
    for(int i = 0;i < tu[x].size();i++)
    {
        int k = tu[x][i];
        if(check[k] == 1)
            a[x]+=a[k];
        else
            a[x]+=dfs(k);        
    }
    if(a[x] >= m)
    {
        best[++sum] = x;
    }
    return a[x];
}
int main(int argc, char const *argv[])
{
    char x,y,z;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {   
        getchar();
        scanf("%c %c %c",&x,&y,&z);
        if(y!='*')
            tu[x-'A'].push_back(y-'A');
        if(z!='*')
            tu[x-'A'].push_back(z-'A');
    }
    dfs(0);
    if(sum == 0)
    {
        cout << "None" << endl;
        return 0;
    }
    for(int i = 1;i <= sum;i++)
    {
        if(i == sum)
            cout << char('A' + best[i]) << endl;
        else
        {
            cout << char('A' + best[i]) << " ";
        }
    }
    return 0;
}