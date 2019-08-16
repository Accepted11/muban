#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e7+10;
int n;
string s;
string t;
map<string,int> m;
int a[20];
int b[maxn];
inline bool add(int x,int j,int i)
{
    int flag=0;
    if (x==0||x==2||x==4||x==5||x==7||x==9||x==11)
    {
        a[1]++;
        if (a[1]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==1||x==3||x==5||x==6||x==8||x==10||x==0)
    {
        a[2]++;
        if (a[2]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==2||x==4||x==6||x==7||x==9||x==11||x==1)
    {
        a[3]++;
        if (a[3]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==3||x==5||x==7||x==8||x==10||x==0||x==2)
    {
        a[4]++;
        if (a[4]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==4||x==6||x==8||x==9||x==11||x==1||x==3)
    {
        a[5]++;
        if (a[5]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==5||x==7||x==9||x==10||x==0||x==2||x==4)
    {
        a[6]++;
        if (a[6]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==6||x==8||x==10||x==11||x==1||x==3||x==5)
    {
        a[7]++;
        if (a[7]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==7||x==9||x==11||x==0||x==2||x==4||x==6)
    {
        a[8]++;
        if (a[8]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==8||x==10||x==0||x==1||x==3||x==5||x==7)
    {
        a[9]++;
        if (a[9]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==9||x==11||x==1||x==2||x==4||x==6||x==8)
    {
        a[10]++;
        if (a[10]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==10||x==0||x==2||x==3||x==5||x==7||x==9)
    {
        a[11]++;
        if (a[11]==j-i+1)
        {
            flag=1;
        }
    }
    if (x==11||x==1||x==3||x==4||x==6||x==8||x==10)
    {
        a[12]++;
        if (a[12]==j-i+1)
        {
            flag=1;
        }
    }
    return flag;
}

int main()
{
    freopen("4.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    m["Do"]=0;
    m["Do#"]=1;
    m["Re"]=2;
    m["Re#"]=3;
    m["Mi"]=4;
    m["Fa"]=5;
    m["Fa#"]=6;
    m["Sol"]=7;
    m["Sol#"]=8;
    m["La"]=9;
    m["La#"]=10;
    m["Si"]=11;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        b[i]=m[s];
    }
    int r=1;
    add(b[1],1,1);
    for (int i=n; i>=1; i--)
    {
        if (add(b[i],n+1,i))
        {
        }
        else
        {
            r=i;
            break;
        }
    }
    int l=n;
    for (int i=2; i<=n; i++)
    {
        if (add(b[i],n+r+1+i-2,0))
        {
        }
        else
        {
            l=i;
            break;
        }
    }
    int ans=1,f;
    int last=l;
    for (int i=1; i<=12; i++)
    {
        a[i]=0;
    }
    for (int i=l; i<=r; i++)
    {
        f=0;
        if (add(b[i],i,last))
        {
            f=1;
        }
        else
        {
            ans++;
            last=i;
            if (i==r)
            {
                ans++;
                break;
            }
            for (int j=1; j<=12; j++)
            {
                a[j]=0;
            }
            add(b[i],1,1);
        }
        if (f==1&&i==r)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


