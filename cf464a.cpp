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
const int maxn=1000005,inf=0x3f3f3f3f;   
int a[maxn];   
  
int main() {  
    int n,i,j,k,ans;  
    ans=0;  
    scanf("%d",&n);  
    for (i=1;i<=n;i++) scanf("%d",&a[i]);  
    for (i=1;i<=n;i++) {  
        j=a[i];k=a[j];  
        if (a[k]==i&&i!=j&&j!=k&&i!=k) ans++;  
    }  
    if (ans>0) cout << "YES"; else cout << "NO";  
    return 0;  
}  
