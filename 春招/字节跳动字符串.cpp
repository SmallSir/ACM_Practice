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

int T,n;
string s,str;
int main(int argc, char const *argv[])
{
    cin >> T;
    while(T--)
    {
        int sum=0;
        cin >> str;
        n = str.length();
        s = "";
        s+=str[0];
        sum = 1;
        for(int i=1;i < n;i++)
        {
            if(str[i]== str[i-1])
                sum++;
            else
            {
                if(sum >= 2)
                    s+=str[i-1];
                sum=1;
                s+=str[i];
            }
        }
        if(sum >= 2)
            s+=str[n-1];
        str = "";
        n = s.length();
        str+= s[0];
        sum = 1;
        int cnt;
        for(int i = 1;i < n;i++)
        {
            if(s[i]== s[i-1])
                sum++;
            else
            {
                if(sum == 2)
                {
                    if(cnt == 1)
                    {
                        cnt = 0;
                    }
                    else
                    {
                        cnt++;
                        str+=s[i-1];
                    }
                    sum = 1;
                }
                else
                {
                    sum = 1;
                    cnt = 0;
                }
                str+=s[i];
            }
            
        }
        if(sum == 2)
        {
            if(cnt != 1)
                str+=s[n-1];
        }
        /*
        if(sum == 2 && cnt == 1)
            cnt = 0;
        else
        {
            str+=s[n-1];
        }*/
        cout << str << endl;
    }
    return 0;
}