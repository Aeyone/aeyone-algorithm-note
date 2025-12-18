#include <bits/stdc++.h>
#define int long long
#define ll long long
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()
#define Vector Point
using namespace std;
const double pi = acos(-1);
const int N = 5000 + 10;
const double dinf = 1e18, eps = 1e-8;
int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}


struct Point //int版本
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator+(Point B) { return Point(x + B.x, y + B.y); }                // 向量加法
    Point operator-(Point B) { return Point(x - B.x, y - B.y); }                // 向量减法
    Point operator*(int k) { return Point(x * k, y * k); }                   // 向量乘法
    Point operator/(int k) { return Point(x / k, y / k); }                   // 向量除法
    bool operator==(Point B) { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; } // 判断向量是否相等
};
double dot(Point a, Point b) // 点积
{
    return a.x * b.x + a.y * b.y;
}
double cross_1(Point a, Point b, Point c) // 点线关系( 负则ab在ac左边 正则ab在ac右边 )
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double cross(Point a, Point b) // 叉积( 有向平行四边形的面积可正可负 )
{
    return a.x * b.y - a.y * b.x;
}
double dis(Point a, Point b) // 两点间距离
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


bool Tubaocmp(Point a, Point b) // 排序
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool right(Point a, Point L, Point R) // 判断AL是否在AR右边
{
    return sgn(cross(L - a, R - a)) > 0; // 必须严格大于零
}

bool checkP(Point p, Point a, Point b) // 判断点P是否在线段AB上
{
    return !sgn(cross(p - a, b - a)) && sgn(dot(p - a, p - b)) <= 0;
    /*PA,AB共线且P在AB之间(其实也可以用len(p-a)+len(p-b)==len(a-b)判断，但是精度损失较大)*/
}

double len(Vector a) // 求模长
{
    return sqrtl(a.x * a.x + a.y * a.y);
}
double dis_PL(Point p, Point a, Point b) // p到线段AB的距离
{
    if (a == b)
        return len(p - a); // AB重合
    Vector x = p - a, y = p - b, z = b - a;
    if (sgn(dot(x, z)) < 0) // 离a近
        return len(x);
    if (sgn(dot(y, z)) > 0) // 离b近
        return len(y);
    return abs(cross(x, z) / len(z));
}

void solve()
{
    int n, r, top = 0;
    cin >> n >> r;
    vector<Point> p(n + 10), s(n + 10);
    int f = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
        if (i > 1)
        {
            if (p[i].x * p[i - 1].y != p[i].y * p[i - 1].x)
                f = 1;
        }
    }
    if (n <= 2 || (!f))
    {
        cout << (pi * r * r / 2.0) << "\n";
        return;
    }
    auto Andrew = [&](int n) -> void // Andrew 无法处理只有一个或两个点的情况(特判一下)
    {
        sort(p.begin() + 1, p.begin() + n + 1, Tubaocmp);
        for (int i = 1; i <= n; i++) // 下凸包
        {
            while (top > 1 && cross_1(s[top - 1], s[top], p[i]) <= 0)
                top--;
            s[++top] = p[i];
        }
        int t = top;
        for (int i = n - 1; i >= 1; i--) // 上凸包
        {
            while (top > t && cross_1(s[top - 1], s[top], p[i]) <= 0)
                top--;
            s[++top] = p[i];
        }
    };
    auto InTubao = [&](vector<Point> &P, int n, Point a) -> int // 二分判断点是否在凸包内或上
    {
        if (right(P[1], a, P[2]) || right(P[1], P[n], a))
            return 0; // 在P[1_2]或P[1_n]外
        if (checkP(a, P[1], P[2]) || checkP(a, P[1], P[n]))
            return 2; // 在P[1_2]或P[1_n]上
        int l = 2, r = n - 1;
        while (l < r) // 二分找到一个位置pos使得P[1]_A在P[1_pos],P[1_(pos+1)]之间
        {
            int mid = l + r + 1 >> 1;
            if (right(P[1], P[mid], a))
                l = mid;
            else
                r = mid - 1;
        }
        if (right(P[l], a, P[l + 1]))
            return 0; // 在P[pos_(pos+1)]外
        if (checkP(a, P[l], P[l + 1]))
            return 2; // 在P[pos_(pos+1)]上
        return 1;
    };
    Andrew(n);
    int ok = InTubao(s, top, Point(0, 0));
    if (ok == 0 || ok == 2)
    {
        cout << pi*r*r / 2.0 << "\n";
        return;
    }
    double ans = 0;
    for (int i = 2; i <= top; i++)
    {
        double d = dis_PL(Point(0, 0), s[i - 1], s[i]);
        double S = acosl(d / r) * r * r - d * (sqrtl(max((double)0.0, (double)r * r - d * d)));
        double s1 = pi * r * r - S;
        if (S > s1)
            swap(S, s1);
        ans = max(ans, S);
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(12);
    int _ = 1;
    //cin >> _ ;
    while (_--)
        solve();
    return 0;
}