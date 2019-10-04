#include <bits/stdc++.h>

using namespace std;
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
bool judge(int x)
{
    for(int i=2; 1; ++i)
    {
        int t=i*i;
        if(t>x)
            return 1;
        if(x%t==0)
            return 0;
    }
    return 1;
}
struct node
{
    int fz;
    int fm;
    node()
    {
        fz=0;
        fm=1;
    }

    void print()
    {
        printf("%d/%d\n",fz,fm);
    }
    void reverse()
    {
        swap(fz,fm);
    }
};
node min(node a,node b)
{
    int lcm2=lcm(a.fm,b.fm);
    int bei1=lcm2/a.fm;
    int bei2=lcm2/b.fm;
    int t1=a.fz*bei1;
    int t2=b.fz*bei2;
    if(t1<=t2)
        return a;
    return b;
}
void add(node& a,node b)
{
    int lcm2=lcm(a.fm,b.fm);//printf("%d\n",lcm2);
    int bei1=lcm2/a.fm;
    int bei2=lcm2/b.fm;
    a.fz=a.fz*bei1+b.fz*bei2;
    a.fm=lcm2;
    int t=__gcd(a.fz,a.fm);
    a.fz/=t;
    a.fm/=t;
}
int main()
{
    freopen("D:/123.txt","w",stdout);
    double ans=0;
    for(int n=1; n<=10000; ++n)
    {

        node oo;
        oo.fz=1000000;
        oo.fm=1;
        for(int i=1; i<=n; ++i)
        {
            node ans;
            for(int j=1; j<=i; ++j)
            {
                if(i%j)
                    continue;
                if(judge(j))
                {
                    //printf("i== %d  j== %d\n",i,j);
                    node t;
                    t.fz=1;
                    t.fm=j;
                    add(ans,t);

                    //ans.print();
                }
                //
            }
            ans.reverse();
            oo=min(oo,ans);
        }
        printf("i= %d   ",n);
        oo.print();
    }
    return 0;
}
