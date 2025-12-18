#include <bits/stdc++.h>
#define int long long
#define ll long long
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()


const int N = 1 << 12;
using namespace std;

// for(int S1=S;S1!=0;S1=(S1-1)&S)
// {
//     S2=S^S1;
// }

struct DSU
{
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};


void solve()
{
    int n, q;
    cin >> n >> q;
    int ans = 0;
    vector<DSU> dsu(N + 1);
    for (int i = 0; i <= N; i++)
        dsu[i].init(n + 1);
    auto dfs = [&](auto && dfs, int u, int v, int b)->void{
        if (!dsu[b].merge(u, v) || !b)
            return;
        int x = b;
        while (x)
        {
            dfs(dfs, u, v, b ^ x & -x);
            x -= (x & -x);
        }
    };
    while (q--)
    {
        char op;
        cin >> op;
        if (op == '+')
        {
            int u, v, w;
            cin >> u >> v >> w;
            dfs(dfs, u, v, w);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            int B = 0;
            for (int b = 11; b >= 0; b--)
            {
                if (dsu[1 << b | B].same(u, v))
                    B |= 1 << b;
            }
            if (dsu[B].same(u, v))
                ans += B;
            else
                ans--;
        }
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(10);
    int _ = 1;
    cin >> _ ;
    while (_--)
        solve();
    return 0;
}