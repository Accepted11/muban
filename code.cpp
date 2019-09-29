#include <bits/stdc++.h>

using namespace std;
const double pi=acos(-1);
const double esp=1e-6;
double h;
int main()
{
    int _;
    scanf("%d",&_);
    while (_--)
    {
        scanf("%lf",&h);
        if (h<esp)
        {
            printf("%.5f\n",0.0);
            continue;
        }
        if (h>=1)
        {
            printf("%.5f\n",pi/cos(atan(2-h)));
            continue;
        }
        double l=0,r=pi/2;
        for (int i=1;i<=50;i++){
            
        }
    }
}
