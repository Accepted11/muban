#include <bits/stdc++.h>

using namespace std;
const int maxm=50100;
const int maxn=500;
char ch[200];
int t,to[maxm],head[maxn],nex[maxm],tot;



struct Blossom {
    int p[maxn], vi[maxn], tag, fl[maxn], c[maxn], pr[maxn], q[maxn], r;
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void add(int u, int v) {
        t++;
        to[t] = v;
        nex[t] = head[u];
        head[u] = t;
    }
    int lca(int u, int v) {
        ++tag;
        u = find(u);
        v = find(v);
        for (;; swap(u, v))
            if (u) {
                if (fl[u] == tag) return u;
                fl[u] = tag;
                u = find(pr[c[u]]);
            }
    }
    void blo(int u, int v, int l) {
        for (; find(u) != l; v = c[u], u = pr[v]) {
            pr[u] = v;
            if (vi[c[u]] == 1)
                vi[q[++r] = c[u]] = 0;
            if (find(u) == u) p[u] = l;
            if (find(c[u]) == c[u]) p[c[u]] = l;
        }

    }
    bool aug(int s) {
        for (int i = 1; i <= tot; i++) {
            p[i] = i;
            vi[i] = -1;
        }
        vi[q[r = 1] = s] = 0;
        int x, y;
        for (int i = 1; i <= r; i++)
            for (int j = head[x = q[i]]; j; j = nex[j])
                if (vi[y = to[j]] == -1) {
                    pr[y] = x;
                    vi[y] = 1;
                    if (!c[y]) {
                        for (int u = x, v = y, t; u; v = t, u = pr[v]) {
                            t = c[u];
                            c[u] = v;
                            c[v] = u;
                        }
                        return 1;
                    }
                    vi[q[++r] = c[y]] = 0;
                } else if (!vi[y] && find(x) != find(y)) {
                    int l = lca(x, y);
                    blo(x, y, l);
                    blo(y, x, l);
                }
        return 0;
    }
    void init() {
        t = 0;
        memset(head, 0, sizeof(head));
        memset(c, 0, sizeof(c));
        memset(pr, 0, sizeof(pr));
    }
};
int main() {
    int _, n, m;
    scanf("%d", &_);
    while (_--) {
        Blossom blossom;
        blossom.init();
        scanf("%d%d", &n, &m);
        tot = n * 2 + m;
        for (int i = 1; i <= n; i++) {
            scanf("%s", ch + 1);
            blossom.add(i + m, i + m + n);
            blossom.add(i + m + n, i + m);
            for (int j = 1; j <= m; j++)
                if (ch[j] - '0') {
                    blossom.add(j, i + m);
                    blossom.add(i + m, j);
                    blossom.add(j, i + m + n);
                    blossom.add(i + m + n, j);
                }
        }
        int ans = 0;
        for (int i = 1; i <= tot; i++) {
            if (!blossom.c[i]) ans += blossom.aug(i);
        }
        printf("%d\n", ans - n);
    }
    return 0;
}
