#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define ls (o<<1)
#define rs (o<<1|1)
#define lson ls, L, M
#define rson rs, M+1 ,R
using namespace std;
const int N = 50010;

int n, m, q;
vector<int> G[N];

int deep[N], size[N], fa[N], id[N], son[N], top[N];
int dfs_clock;

void init(int n) {
    for(int i = 0; i <= n; i++)
        G[i].clear();
}

void addEdge(int u, int v) {
    G[u].pb(v);
}

void dfs1(int u, int pre, int de) {
    deep[u] = de;
    size[u] = 1;
    son[u] = 0;
    fa[u] = pre;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(pre == v) continue;
        dfs1(v, u, de+1);
        if(size[son[u]] < size[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp;
    id[u] = ++dfs_clock;
    if(son[u]) dfs2(son[u], tp);
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void init_chain(int root) {
    dfs_clock = 0;
    dfs1(root, 0, 1);
    dfs2(root, root);
}

int sumv[N<<2], addv[N<<2], value[N];
inline void pushUp(int o) {
    sumv[o] = sumv[ls] + sumv[rs];
}

inline void pushDown(int o, int L, int R) {
    int M = (L + R)/2;
    if(addv[o]) {
        addv[ls] += addv[o], addv[rs] += addv[o];
        sumv[ls] += (M - L + 1) * addv[o];
        sumv[rs] += (R - M) * addv[o];
        addv[o] = 0;
    }
}

void build(int o, int L, int R) {
    sumv[o] = addv[o] = 0;
    if(L == R) return ;
    int M = (L + R)/2;
    build(lson);
    build(rson);
    pushUp(o);
}

void modify(int o, int L, int R, int ql, int qr, int val) {
    if(ql <= L && R <= qr) {
        sumv[o] += (R - L + 1)*val;
        addv[o] += val;
        return ;
    }
    pushDown(o, L, R);
    int M = (L + R) / 2;
    if(ql <= M) modify(lson, ql, qr, val);
    if(qr > M) modify(rson, ql, qr, val);
    pushUp(o);
}

int query(int o, int L, int R, int pos) {
    if(L == R) return sumv[o];
    pushDown(o, L, R);
    int M = (L + R)/2, ret = 0;
    if(pos <= M) ret = query(lson, pos);
    else ret = query(rson, pos);
    return ret;
}

void update(int u, int v, int val) {
    int tp1 = top[u], tp2 = top[v];
    while(tp1 != tp2) {
        if(deep[tp1] < deep[tp2]) {
            swap(tp1, tp2);
            swap(u, v);
        }
        modify(1, 1, dfs_clock, id[tp1], id[u], val);
        u = fa[tp1], tp1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    modify(1, 1, dfs_clock, id[u], id[v], val);
}

int MAIN() {
    while(scanf("%d%d%d", &n, &m, &q) != EOF) {
        init(n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &value[i]);

        int u, v, val;
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        init_chain(1);
        build(1, 1, dfs_clock);

        for(int i = 1; i <= n; i++)
            modify(1, 1, dfs_clock, id[i], id[i], value[i]);

        char oper[10];
        while(q--) {
            scanf("%s", oper);
            if(oper[0] == 'I') {
                scanf("%d%d%d", &u, &v, &val);
                update(u, v, val);
            }else if(oper[0] == 'D') {
                scanf("%d%d%d", &u, &v, &val);
                update(u, v, -val);
            }else if(oper[0] == 'Q') {
                scanf("%d", &u);
                printf("%d\n", query(1, 1, dfs_clock, id[u]));  
            }
        }
    }
    return 0;
}

const int main_stack = 16;
char my_stack[128<<20];

int main() {
    __asm__("movl %%esp, (%%eax);\n"::"a"(my_stack):"memory");
    __asm__("movl %%eax, %%esp;\n"::"a"(my_stack + sizeof(my_stack) - main_stack):"%esp");
    MAIN();
    __asm__("movl (%%eax), %%esp;\n"::"a"(my_stack):"%esp");
    return 0;
}
