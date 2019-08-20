
#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
int n,m,tim,dfn[maxn],repos[maxn],idom[maxn],fa[maxn],mi[maxn],f[maxn],semi[maxn],id[maxn],ans[maxn];
int d[maxn],lc[maxn][25],w[maxn],T=24;

struct edge {
    int tot, head[maxn], next[maxn], to[maxn];

    void clear() {
        tot = 0;
        for (int i = 0; i <= n; i++)
            head[i] = 0;
    }

    void add(int u, int v) {
        ++tot;
        to[tot] = v;
        next[tot] = head[u];
        head[u] = tot;
    }
}G,RG,NG,TR;

void init(){
    tim=0;
    G.clear();RG.clear();NG.clear();TR.clear();
    memset(lc,-1, sizeof(lc));
    for (int i=1;i<=n;i++){
        repos[i]=dfn[i]=idom[i]=fa[i]=ans[i]=0;
        mi[i]=semi[i]=f[i]=i;
        w[i]=0;
    }
}
void tarjan(int x) {
    dfn[x] = ++tim;
    repos[tim] = x;
    for (int i = G.head[x]; i; i = G.next[i])
        if (!dfn[G.to[i]]) {
            fa[G.to[i]] = x;
            tarjan(G.to[i]);
        }
}

int find(int x) {
    if (x == f[x]) return x;
    int tmp = f[x];
    f[x] = find(f[x]);
    if (dfn[semi[mi[tmp]]] < dfn[semi[mi[x]]])
        mi[x] = mi[tmp];
    return f[x];
}

void dfs(int x) {
    for (int i = TR.head[x]; i; i = TR.next[i]) {
        int to = TR.to[i];
        d[to] = d[x] + 1;
        lc[to][0] = x;
        ans[to] += ans[x] + 1;//记录虚点到该点的支配点个数
        for (int j = 1; ~lc[to][j - 1] && ~lc[lc[to][j - 1]][j - 1]; j++)
            lc[to][j] = lc[lc[to][j - 1]][j - 1];
        dfs(to);
    }
}

int lca(int x,int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = T; i >= 0; i--) {
        if (d[lc[y][i]] >= d[x])
            y = lc[y][i];
    }
    if (x == y) return x;
    for (int i = T; i >= 0; i--) {
        if (lc[x][i] != lc[y][i]) {
            x = lc[x][i];
            y = lc[y][i];
        }
    }
    return lc[x][0];
}

void work() {
    for (int i = n; i >= 2; i--) {
        int x = repos[i], tmp = n;
        for (int j = RG.head[x]; j; j = RG.next[j]) {
            if (!dfn[RG.to[j]]) continue;
            if (dfn[RG.to[j]] < dfn[x]) tmp = min(tmp, dfn[RG.to[j]]);
            else {
                find(RG.to[j]);
                tmp = min(tmp, dfn[semi[mi[RG.to[j]]]]);
            }
        }
        semi[x] = repos[tmp];
        f[x] = fa[x];
        NG.add(semi[x], x);
        x = repos[i - 1];
        for (int j = NG.head[x]; j; j = NG.next[j]) {
            int y = NG.to[j];
            find(y);
            if (semi[mi[y]] == semi[y]) idom[y] = semi[y]; else idom[y] = mi[y];
        }
    }
    for (int i = 2; i <= n; i++) {
        int x = repos[i];
        if (idom[x] != semi[x]) idom[x] = idom[idom[x]];
        TR.add(idom[x], x);
    }
    d[1]=1;
    dfs(1);
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        n++;
        init();
        for (int i = 1, v, u; i <= m; i++) {
            scanf("%d%d",&u, &v);
            u++;
            v++;
            swap(u, v);
            w[v]++;
            G.add(u, v);
            RG.add(v, u);
        }
        for (int i = 2; i <= n; i++) {
            if (!w[i]) {
                G.add(1, i);
                TR.add(i, 1);
            }
        }
        tarjan(1);
        work();
        int q, x, y;
        for (int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &x, &y);
            x++;
            y++;
            printf("%d\n", ans[x] + ans[y] - ans[lca(x, y)]);
        }
    }
    return 0;
}
