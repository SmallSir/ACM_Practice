#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
bool fun(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n%10;
        if(cnt>10)
            return false;
        n/=10;
    }
    if(cnt==10)
        return true;
    return false;
}
int main()
{
    int cnt=0;
        for(int i=1;i<2e7;i++)
        {
            if(fun(i))
            {
                a[cnt++]=i;
            }
        }
        int n;
        cin>>n;
        cout<<a[n-1]<<endl;
    return 0;
}
