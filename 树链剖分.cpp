#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+100;
struct edge
{
    int v,next;
} e[maxn*2];
struct Tree
{
    int sum,l,r,lazy;
} tree[maxn*4];

int top[maxn],tim,dfn[maxn],son[maxn],w[maxn],head[maxn],a[maxn],siz[maxn],deep[maxn],fa[maxn],mod,t;

void add(int u,int v)
{
    t++;
    e[t].v=v;
    e[t].next=head[u];
    head[u]=t;
}

void pushup(int rt)
{
    tree[rt].sum=(tree[rt<<1].sum+tree[rt<<1|1].sum)%mod;
}

void pushdown(int rt,int len)
{
    if (tree[rt].lazy==0)
        return;
    tree[rt<<1].lazy+=tree[rt].lazy;
    tree[rt<<1|1].lazy+=tree[rt].lazy;
    tree[rt<<1].sum=(tree[rt<<1].sum+tree[rt].lazy*(len-(len>>1)))%mod;
    tree[rt<<1|1].sum=(tree[rt<<1|1].sum+tree[rt].lazy*(len>>1))%mod;
    tree[rt].lazy=0;
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].sum=0;
    if (l==r)
    {
        tree[rt].sum=w[l];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build (rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int l,int r,int z)
{
    if (l<=tree[rt].l&&tree[rt].r<=r)
    {
        tree[rt].lazy+=z;
        tree[rt].sum+=z*(tree[rt].r-tree[rt].l+1);
        return;
    }
    pushdown(rt,tree[rt].r-tree[rt].l+1);
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if (l<=mid)
    {
        update(rt<<1,l,mid,z);
    }
    if (r>mid)
    {
        update(rt<<1|1,mid+1,r,z);
    }
    pushup(rt);
}
void dfs1(int u,int f)
{
    deep[u]=deep[f]+1;
    siz[u]=1;
    fa[u]=f;
    int maxsiz=-1;
    for (int i=head[u]; i; i=e[i].next)
    {
        int v=e[i].v;
        if (v==f)
        {
            continue;
        }
        dfs1(v,u);
        siz[u]+=siz[v];
        if (siz[v]>maxsiz)
        {
            maxsiz=siz[v];
            son[u]=v;
        }
    }
}

void dfs2(int u,int Top)
{
    dfn[u]=++tim;
    w[tim]=a[u];
    top[u]=Top;
    if (!son[u])
    {
        return;
    }
    dfs2(son[u],Top);
    for (int i=head[u]; i; i=e[i].next)
    {
        int v=e[i].v;
        if (v==fa[u]||v==son[u])
        {
            continue;
        }
        dfs2(v,v);
    }
}

void update1(int x,int y,int z)
{
    z=z%mod;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]])
        {
            swap(x,y);
        }
        update(1,dfn[top[x]],dfn[x],z);
        x=fa[top[x]];
    }
    if (deep[x]>deep[y])
    {
        swap(x,y);
    }
    update(1,dfn[x],dfn[y],z);
}

int query(int rt,int l,int r)
{
    if (l<=tree[rt].l&&tree[rt].r<=r)
    {
        return tree[rt].sum;
    }
    int ret=0;
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if (l<=mid)
        ret=(ret+query(rt<<1,l,mid))%mod;
    if (r>mid)
        ret=(ret+query(rt<<1|1,mid+1,r))%mod;
    return ret;
}

int query1(int x,int y)
{
    int ret=0;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]])
        {
            swap(x,y);
        }
        ret+=query(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if (deep[x]>deep[y])
    {
        swap(x,y);
    }
    ret+=query(1,dfn[x],dfn[y]);
    return ret%mod;
}

int main()
{
    int n,m,r;
    scanf("%d%d%d%d",&n,&m,&r,&mod);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1,u,v; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    while (m--)
    {
        int op;
        scanf("%d",&op);
        if (op==1)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            update1(x,y,z);
        }
        if (op==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query1(x,y));
        }
        if (op==3)
        {
            int x,z;
            scanf("%d%d",&x,&z);
            update(1,dfn[x],dfn[x]+siz[x]-1,z);
        }
        if (op==4)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",query(1,dfn[x],dfn[x]+siz[x]-1));
        }
    }
    return 0;
}
