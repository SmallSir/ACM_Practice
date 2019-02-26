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

int check[50000];
int a[50000],b[50000];
vector<int> tu[50000];
int n,m,number;

int main(int argc, char const *argv[])
{
    int x,y;
    cin >> n >> m;
    if(m == 0)
    {
        for(int i = 0;i < n;i++)
        {
            if(i == n-1)
                cout << i << endl;
            else
            {
                cout << i << ",";
            }
            
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cin >> x >> y;
        tu[y].push_back(x);
        a[x]++;
    }
    queue<int> qua;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == 0)
            qua.push(i);
    }
    while(!qua.empty())
    {
        int u = qua.front();
        qua.pop();
        b[++number] = u;
        for(int i = 0;i < tu[u].size();i++)
        {
            int k = tu[u][i];
            a[k]--;//通过u这个入度为0的点解锁下面的点
            if(a[k] == 0)//如果这个点通过解锁入度为0则放到队列中
            {
                qua.push(k);
            }
        }
    }
    if(number != n)
    {
        cout << "None" << endl;
        return 0;
    }
    for(int i = 1;i <= number;i++)
    {
        if(i == n)
            cout << b[i] << endl;
        else
        {
            cout << b[i] << ",";
        }
    }
    return 0;
}