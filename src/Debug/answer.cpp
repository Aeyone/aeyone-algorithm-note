#include <bits/stdc++.h>

using namespace std;

string My_GetLine()
{
    char c = getchar();
    string s;
    s += c;
    while (c != '\n')
        c = getchar(), s += c;
    return s;
}

int Mod = 998244353;

int read()
{
    char c = getchar();
    int Sum = 0;
    for ( ; c < '0' || c > '9' ; c = getchar());
    for ( ; c >= '0' && c <= '9' ; c = getchar())
        Sum = (Sum * 10) + c - 48;
    return Sum;
}

void Put(int x)
{
    if (x == 0)
        return;
    Put(x / 10);
    putchar(x % 10 + 48);
}

int Add(int a, int b)
{
    return a + b >= Mod ? a + b - Mod : a + b;
}

int Sub(int a, int b)
{
    return a - b < 0 ? a - b + Mod : a - b;
}

int Mul(int a, int b)
{
    return 1ll * a * b % Mod;
}

int Pow(int a, long long k)
{
    int R = 1;
    while (k)
    {
        if (k & 1)
            R = Mul(R, a);
        k >>= 1;
        a = Mul(a, a);
    }
    return R;
}

struct EE
{
    int y, v;
};

vector < EE > E[1000005];

int Fac[2000005], Inv[2000005];

int C(int n, int m)
{
    return Mul(Fac[n], Mul(Inv[m], Inv[n - m]));
}

void Bit_Print(long long x)
{
    if (x == 0)
    {
        cout << 0;
        return;
    }
    stack < int > S;
    while (x)
        S.push(x & 1), x >>= 1;
    while (S.size())
        cout << S.top(), S.pop();
    return;
}

void Init()
{
    Fac[0] = 1;
    for (int i = 1 ; i <= 2000000 ; ++ i)
        Fac[i] = Mul(Fac[i - 1], i);
    Inv[2000000] = Pow(Fac[2000000], Mod - 2);
    for (int i = 1999999 ; ~i; -- i)
        Inv[i] = Mul(Inv[i + 1], i + 1);
    return;
}

struct Point
{
    double x, y, atan2;
    Point () {}
    Point (double a, double b) : x(a), y(b) {}
    Point operator + (const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator * (const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    bool operator == (const Point &b) const
    {
        return x == b.x && y == b.y;
    }
}P[100005];

double GetDis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Solve()
{
    int x, y;
    cin >> x >> y;
    int X = x, Y = y;
    int p = 0, q = 0;
    int Min = 2e9;
    int k;
    int P, Q;
    for (int i = 30 ; ~i ; -- i)
    {
        int a = x - p, b = y - q;
        if (a < (1 << i) && b < (1 << i))
        {
            if (a > b)
            {
                int r = (p + (1 << i)) - x;
                if (r < Min)
                {
                    Min = r;
                    k = i - 1;
                    P = p + (1 << i), Q = q;
                }
            }
            else
            {
                int r = (q + (1 << i)) - y;
                if (r < Min)
                {
                    Min = r;
                    k = i - 1;
                    Q = q + (1 << i), P = p;
                }
            }
        }
        else
            if (a > b)
                p += 1 << i;
            else
                q += 1 << i;
            //cout << i << " " << Min << " " << p << " " << q << endl;
    }

    int ans = 0, check = 0;
    if (x + y - p - q < Min)
    {
        ans += abs(X - p) + abs(Y - q);
        check = p & q;
    }
    else
    {   
        ans += abs(X - max(P, x)) + abs(Y - max(Q, y));
        check = max(P, x) & max(Q, y);

    }
    cout << ans << ' ' << check << '\n';
}

int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //Init();
    int T = 1;
    // cin >> T;
    while (T --)
        Solve();
    return 0;
}