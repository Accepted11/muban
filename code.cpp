#include <bits/stdc++.h>

using namespace std;

const int maxn=200010;
int t1[maxn],t2[maxn],c[maxn];
typedef long long ll;
bool cmp(int *r,int a,int b,int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m) {
    n++;
    int i, j, p, *x = t1, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = str[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int j = 1; j <= n; j <<= 1) {
        p = 0;
        for (int i = n - j; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    int k = 0;
    n--;
    for (int i = 0; i <= n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k]) k++;
        height[rank[i]] = k;
    }
}
int len;
char str[maxn];
int k,a[maxn],sa[maxn];
int Rank[maxn],height[maxn],RMQ[maxn];
int best[20][maxn];
void initRMQ(int n) {
    k=log2(n);
    for (int i = 0; i <= n; i++)
        best[0][i] = a[i];
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + (1 << i) - 1 <= n; j++) {
            best[i][j]=min(best[i - 1][j],best[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int askRMQ(int a,int b) {
    int t;
    t = log2(b - a + 1);
    b -= (1 << t) - 1;
    return min(best[t][a],best[t][b]);
}

int ask(int l,int r){
    if (l==r) return len-sa[r];
    return askRMQ(l+1,r);
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &k);
        scanf("%s", str);
        len = strlen(str);
        for (int i = 0; i < len; i++) {
            a[i] = str[i] - 'a' + 1;
        }
        a[len] = 0;
        da(a, sa, Rank, height, len, 30);
        initRMQ(len);
        ll ans = 0;
        for (int i = 1; i + k - 1 <= len; i++) {
            ans += ask(i, i + k - 1);
            if (i - 1 > 0) ans -= ask(i - 1, i + k - 1);
            if (i + k <= len) ans -= ask(i, i + k);
            if (i - 1 > 0 && i + k <= len) ans += ask(i - 1, i + k);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
