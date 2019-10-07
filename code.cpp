
const int maxn=50010;
const int DIM=10;
inline double sqr(double)
{
    return x*x;
}
namespace KDTtree
{
int k;
struct Point
{
    int x[DIM];
    double distance(const Point &b)const
    {
        double ret=0;
        for (int i=0; i<k; i++)
            ret+=sqr(x[i]-b.x[i]);
        return ret;
    }
    void input()
    {
        for (int i=0; i<k; i++)
            scanf("%d",&x[i]);
    }
    void output()
    {
        for (int i=0; i<k; i++)
        {
            printf("%d",x[i]);
            if (i==k-1)
                printf("\n");
            else
                printf(" ");
        }
    }
    struct qnode
    {
        Point p;
        double dis;
        qonde(){};
        qonde(Point _p,double _dis):p(_p),dis(_dis){}
        bool operator <(const qonde &b) const{
            return dis<b.dis;
        }
    };
    priority_queue<qnode>q;
    struct cmpx{
        int div;
        cmpx()
    };
