#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10010;
struct node{
    ll x,y1,y2,val;
    bool operator<(const node &b)const {
        if (x!=b.x) return x<b.x;else return val>b.val;
    }
}a[maxn*2];
vector<int>v;

struct node1{
    ll l,r,sum,laz;
}tree[maxn<<2];

void build(ll rt,ll l,ll r) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = tree[rt].laz = 0;
    if (l == r) return;
    ll mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void push(int rt) {
    tree[rt << 1].sum += tree[rt].laz;
    tree[rt << 1 | 1].sum += tree[rt].laz;
    tree[rt << 1].laz += tree[rt].laz;
    tree[rt << 1 | 1].laz += tree[rt].laz;
    tree[rt].laz = 0;
}
void update(ll rt,ll l,ll r,ll k) {
    if (l == tree[rt].l && tree[rt].r == r) {
        tree[rt].laz += k;
        tree[rt].sum += k;
        return;
    }
    if (tree[rt].l == tree[rt].r) return;
    if (tree[rt].laz) push(rt);
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) update(rt << 1, l, mid, k);
    else if (l > mid) update(rt << 1 | 1, mid + 1, r, k);
    else {
        update(rt << 1, l, mid, k);
        update(rt << 1 | 1, mid + 1, r, k);
    }
    tree[rt].sum = max(tree[rt << 1].sum, tree[rt << 1 | 1].sum);
}
int main() {
    int n, w, h;
    while (~scanf("%d%d%d", &n, &w, &h)) {
        v.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y1, &a[i].val);
            v.push_back(a[i].y1);
            v.push_back(a[i].y1+h-1);
            a[i].y2 = a[i].y1 + h - 1;
            a[i + n] = a[i];
            a[i + n].x = a[i].x + w - 1;
            a[i + n].val = -a[i].val;
        }
        sort(v.begin(),v.end());
        sort(a, a + n * 2);
        int cnt=unique(v.begin(),v.end())-v.begin();
        v.erase(v.begin()+cnt,v.end());
        build(1, 1, cnt);
        ll ans = 0;
        for (int i = 0; i < n * 2; i++) {
            int l=lower_bound(v.begin(),v.end(),a[i].y1)-v.begin()+1;
            int r=lower_bound(v.begin(),v.end(),a[i].y2)-v.begin()+1;
            update(1, l, r, a[i].val);
            ans = max(ans, tree[1].sum);
        }
        printf("%lld\n", ans);
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10010;
struct node{
    ll x,y1,y2,val;
    bool operator<(const node &b)const {
        if (x!=b.x) return x<b.x;else return val>b.val;
    }
}a[maxn*2];
vector<int>v;

struct node1{
    ll l,r,sum,laz;
}tree[maxn<<2];

void build(ll rt,ll l,ll r) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = tree[rt].laz = 0;
    if (l == r) return;
    ll mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void push(int rt) {
    tree[rt << 1].sum += tree[rt].laz;
    tree[rt << 1 | 1].sum += tree[rt].laz;
    tree[rt << 1].laz += tree[rt].laz;
    tree[rt << 1 | 1].laz += tree[rt].laz;
    tree[rt].laz = 0;
}
void update(ll rt,ll l,ll r,ll k) {
    if (l == tree[rt].l && tree[rt].r == r) {
        tree[rt].laz += k;
        tree[rt].sum += k;
        return;
    }
    if (tree[rt].l == tree[rt].r) return;
    if (tree[rt].laz) push(rt);
    ll mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) update(rt << 1, l, mid, k);
    else if (l > mid) update(rt << 1 | 1, mid + 1, r, k);
    else {
        update(rt << 1, l, mid, k);
        update(rt << 1 | 1, mid + 1, r, k);
    }
    tree[rt].sum = max(tree[rt << 1].sum, tree[rt << 1 | 1].sum);
}
int main() {
    int n, w, h;
    while (~scanf("%d%d%d", &n, &w, &h)) {
        v.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y1, &a[i].val);
            v.push_back(a[i].y1);
            v.push_back(a[i].y1+h-1);
            a[i].y2 = a[i].y1 + h - 1;
            a[i + n] = a[i];
            a[i + n].x = a[i].x + w - 1;
            a[i + n].val = -a[i].val;
        }
        sort(v.begin(),v.end());
        sort(a, a + n * 2);
        int cnt=unique(v.begin(),v.end())-v.begin();
        v.erase(v.begin()+cnt,v.end());
        build(1, 1, cnt);
        ll ans = 0;
        for (int i = 0; i < n * 2; i++) {
            int l=lower_bound(v.begin(),v.end(),a[i].y1)-v.begin()+1;
            int r=lower_bound(v.begin(),v.end(),a[i].y2)-v.begin()+1;
            update(1, l, r, a[i].val);
            ans = max(ans, tree[1].sum);
        }
        printf("%lld\n", ans);
    }
}
