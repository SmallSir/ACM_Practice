  #include <iostream>
  #include <algorithm>
  #include <cstdio>
  #include <cstring>
  #define maxn 1000
  #define MIN(a, b) (a<b?a:b)
  #define INF 0x6ffffff
  using namespace std;
  int ans;
 int k, a;
 struct ST
 {
     int l, r, val;
 };
 int arr[maxn];
 ST st[maxn*4];
 int n, kk;
 void build(int ll, int rr, int n)
 {
     st[n].l = ll;
     st[n].r = rr;
     if(ll == rr)
     {
         st[n].val = arr[ll];
         return;
     }
     int mid = (ll + rr) / 2;
     build(ll, mid, 2*n);
    build(mid+1, rr, 2*n+1);
    st[n].val = MIN(st[2*n].val,st[2*n+1].val);
 }
 void query(int ll, int rr, int n)
 {
     if(st[n].l == ll && st[n].r == rr)
     {
         ans = MIN(ans, st[n].val);
         return;
     }
     int mid = (ll + rr) / 2;
     if(mid >= rr)
         query(ll, rr, 2*n);
     else if(mid+1 <= ll)
         query(ll, rr, 2*n+1);
     else
     {
         query(ll, mid, 2*n);
         query(mid+1, rr, 2*n+1);
     }
 }
 void update(int n)
 {
     if(st[n].l == k && st[n].r == k)
     {
         st[n].val = a;
         return;
     }
     int mid = (st[n].l + st[n].r) / 2;
     if(mid >= k)
     {
         update(2*n);
     }
     else
     {
        update(2*n+1);
     }
     st[n].val = MIN(st[2*n].val, st[2*n+1].val);
 }
 int main()
 {
 //    freopen("nice.in","r",stdin);
//	freopen("nice.out","w",stdout);

     while(~scanf("%d %d", &n, &kk))
     {
         for(int i = 1 ; i <= n; i++)
             cin >> arr[i];
         build(1, nn + 1, 1);
         int cl, cr;
         cin >> cl >> cr;
         ans = INF;
         query(cl, cr, 1);
         cout << ans << endl;
         cin >> k >> a;
         update(1);
         for(int i = 1; i <= 15; i++)
             cout << st[i].l << " " << st[i].r << " " << st[i].val << endl;
         ans = INF;
         query(cl, cr, 1);
         cout << ans << endl;
 
 
     }
     return 0;
}
