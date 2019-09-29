#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=100010;
struct node
{
    int v,w;
    node(int _v,int _w):v(_v),w(_w) {};
};
vector<node>vec[maxn];
void dfs(int u,int fa)
{
    int id;
    for (int i=0; i<E[u].size(); i++)
    {
        int v=E[u][i];
        if (v==fa)
        {
            id=i;
            continue;
        }
        dfs(v,u);
        s[u]+=f[v];
    }
    
    
}

void dfs(int u,int fa)
{
    int id;
    for(int i=0; i<edge[u].size(); i++)
    {
        int v=edge[u][i];
        if(v==fa)
        {
            id=i;
            continue;
        }
        dfs(v,u);
        s[u]+=f[v];
    }
    if(vis[u])
    {
        g[u]=s[u];
        if(fa!=-1)
            f[u]=g[u]+weight[u][id];
    }
    else
    {
        ll mi=1e18;
        bool flag=false;
        for(int i=0; i<edge[u].size(); i++)
        {
            int v=edge[u][i];
            if(v==fa)
                continue;
            flag=true;
            mi=min(mi,s[u]-f[v]+g[v]);
        }
        if(flag)
            g[u]=mi;
        if(fa!=-1)
            f[u]=min(s[u],g[u]+weight[u][id]);
    }
}

int main()
{
    scanf("%d%d",&n,&k);

    for (int i=1,u,v,w; i<n; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u++;
        v++;
        E[u].push_back(node(v,w));
        E[v].push_back(node(u,w));
    }

    for (int i=1,x; i<=k; i++)
    {
        scanf("%d",&x);
        x++;
        vis[x]=1;
        root=x;
    }

    dfs(root,-1);
    ll ans=g[root];
    printf("%lld\n",ans);
    return 0;
}
