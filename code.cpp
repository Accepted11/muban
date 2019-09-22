#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int maxn = 100000;
struct node{
    ll sun,ni;
}f[maxn];
bool cmp(node x,node y){return x.sun<y.sun;}
ll sth,stm,sts;
int main() {
    int n;
    scanf("%d%lld%lld%lld",&n,&sth,&stm,&sts);
    ll h,m,s,tmp;
    if(sth>=12)sth-=12;
    ll p=sth*3600+stm*60+sts;
    for(int i=1;i<=n;++i){
        scanf("%lld%lld%lld",&h,&m,&s);
        if(h>=12) h-=12;
        tmp=h*3600+m*60+s;
        tmp-=p;
        if(tmp<0) tmp+=12*3600;
        f[i].sun=tmp;
        f[i].ni=12*3600-tmp;
    }
    sort(f+1,f+1+n,cmp);
    ll ans=min(f[n].sun,f[1].ni);
    for(int i=1;i<=n;++i){
        if(i<n)
        ans=min(ans,2*f[i].sun+f[i+1].ni);
        if(i>1)
        ans=min(ans,2*f[i].ni+f[i-1].sun);
    }
    printf("%.2f\n",(ans*6.0));
    return 0;
}
