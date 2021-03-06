#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node{
    int l,r;
}a[maxn];
map<int,int>ma;
bool cmp1(node a,node b) {
    return a.r < b.r;
}
bool cmp2(node a,node b) {
    return a.l < b.l;
}
int n, m;
int solve() {
    int res = 1;
    int en = a[1].r;
    for (int i = 2; i <= n; i++) {
        if (a[i].l > en) {
            res++;
            en = a[i].r;
        }
    }
    return res;
}
int main(int argc,char *args[]) {
    FILE *f_in = fopen(args[1], "r");//测试输入
    FILE *f_out = fopen(args[2], "r");//测试输出
    FILE *f_user = fopen(args[3], "r");//用户输出
    int ret = 0;
    fscanf(f_in, "%d%d", &n, &m);
    int ans1, ans2;
    fscanf(f_out, "%d", &ans1);
    if (ans1 == -1) {
        fscanf(f_user, "%d", &ans2);
        if (ans2 != -1) ret = 1;
        fclose(f_in);
        fclose(f_out);
        fclose(f_user);
        return ret;
    }
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}
