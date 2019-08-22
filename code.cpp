#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn],b[maxn],f[maxn][maxn],n,m,ans;
int main() {
    while (scanf("%d%d", &n, &m)) {
        ans = 0x3f3f3f3f;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            b[i]--;
            a[i] = (b[i] - a[i] + m) % m;
        }
        memset(f, 0x3f, sizeof(f));
        f[1][0] = a[1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                if (a[i] >= a[i + 1]) {
                    f[i + 1][j] = min(f[i + 1][j], f[i][j]);
                    if (j + 1 <= n)
                        f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + (a[i + 1] + (j + 1) * m) - (a[i] + j * m));
                } else {
                    if (j) f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j]);
                    f[i + 1][j] = min(f[i + 1][j], f[i][j] + (a[i + 1] + j * m) - (a[i] + j * m));
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            ans = min(ans, f[n][i]);
        }
        printf("%d\n", ans);
    }
}
