#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<int,int>mp;
int n,m,s,t,k;
struct node {
    int a[205][205];
    node operator*(const node &b) const {
        node res;
        memset(res.a,0x3f, sizeof(res.a));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    res.a[i][j] = min(res.a[i][j],a[i][k] + b.a[k][j]);
                }
            }
        }
        return res;
    }
}st;
node pow(node b,int c){
    node res;
    for (int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            res.a[i][i] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        res.a[i][i]=1;
    }
    while (c) {
        if (c & 1) {
            res = res * b;
        }
        c >>= 1;
        b = b * b;
    }
    return res;
}
int main() {
    scanf("%d%d%d%d", &k, &m, &s, &t);
    memset(st.a, 0x3f, sizeof(st.a));
    while (m--) {
        int x, y, z;
        scanf("%d%d%d", &z, &x, &y);
        if (mp[x]) x = mp[x]; else x = mp[x] = ++n;
        if (mp[y]) y = mp[y]; else y = mp[y] = ++n;
        st.a[x][y] = z;
    }
    node ans = pow(st, k);
    printf("%d\n", ans.a[mp[s]][mp[t]]);
}
