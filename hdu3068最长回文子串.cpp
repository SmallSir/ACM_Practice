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

string str,s;
int len[500005];
int n;
void init()
{
    memset(len,0,sizeof(len));
    str = "";
    n = 1;
    str+='~';
    for(int i = 0;i < s.length();i++)
    {
        n+=2;
        str+='#';
        str+=s[i];
    }
    str+='#';
    str+="@";
    n+=2;
}
int Manacher(){
    len[0] = 0;
    int k = 0;//中间节点
    int sum = 0;
    int r = 0;//以k为中间点的右边界r
    for(int i = 0;i < n;i++)
    {
        if(i < r)
            len[i] = min(r - i,len[2*k - i]);
        else
            len[i] = 1;
        while(str[i - len[i]] == str[i + len[i]])
            len[i]++;
        if(len[i] + i > r) //以i为中心节点的回文子串比目前k为中间节点的右边界r大
        {
            k = i;
            r = len[i] + i;
            sum = max(sum,len[i]);
        }   
    }
    return sum - 1;
}
int main(int argc, char const *argv[])
{
    while(cin >> s)
    {
        init();
        printf("%d\n",Manacher());
    }
    return 0;
}