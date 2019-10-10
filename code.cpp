#include <bits/stdc++.h>

using namespace std;
const int maxn=5e5+10;
string outx,outy,userx,usery;
struct Point
{
    int x,y;
} a[maxn];
int n,r;
int main(int argc,char *args[])
{
    ifstream user,in,out;
    in.open(args[1]);
    out.open(args[2]);
    user.open(args[3]);
    in>>n;
    in>>r;
    for (int i=1; i<=n; i++)
    {
        in>>a[i].x>>a[i].y;
    }
    out>>outx;
    if (outx=="-1")
    {
        user>>userx;
        if (userx=="-1")
            return 1;
        else
            return 0;
    }
    out>>outy;
    user>>userx>>usery;
    int len1=outx.length();
    int len2=outy.length();
    int len3=userx.length();
    int len4=usery.length();
    if (len1>100||len2>100||len3>100||len4>100)
        return 0;
    for (int i=0;i<len1;i++){
        if (outx[i]=='.') return 0;
    }
    for (int i=0;i<len2;i++){
        if (outy[i]=='.') return 0;
    }
    for (int i=0;i<len1;i++){
        if (outx[i]=='.') return 0;
    }

    in.close();
    out.close();
    user.close();
}
