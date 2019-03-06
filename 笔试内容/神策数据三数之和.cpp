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

int b[5];
int a[20005];
int i,j,u,n,x,k;
map<int,int> check;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for(i = 0;i < n;i++)
    {
        cin >> a[i];
        if(check[a[i]] == 0)
        {
            check[a[i]] = 1;
        }
        else
        {
            check[a[i]]++;
        }
    }
    int flag = 0;
    for(i = 0;i < n;i++)
    {
        for(j = i + 1;j < n;j++)
        {
            x = a[i] + a[j];
            if(check[k - x]!=0)
            {
                if(k - x == a[i])
                {
                    if(check[a[i]] > 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(k - x == a[j])
                {
                    if(check[a[j]] > 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
                
            }
        }
        if(flag == 1)
            break;
    }
    if(flag == 1)
    {
        for(u = 0;u < n;u++)
        {
            if(a[u] == k - x&& u != i && u != j)
            {
                break;
            }
        }
        b[0] = u,b[1] = i, b[2] = j;
        sort(b,b+3);
        cout << b[0] << " " << b[1] << " " << b[2]<<endl;
    }
    if(flag == 0)
        cout << -1 << " " << -1 << " " << -1 <<endl;
    return 0;
}