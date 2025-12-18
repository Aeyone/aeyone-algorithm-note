#include <bits/stdc++.h>

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<ll, int> pli;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpll;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

std::mt19937_64 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

template <typename T>
inline T read () {
    T x = 0;
    int y = 1;
    char ch = getchar ();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            y = -1;
        ch = getchar ();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar ();
    }
    return x * y;
}

template <typename T>
inline void write (T x) {
    if (x < 0) {
        putchar ('-');
        x = -x;
    }
    if (x >= 10) {
        write (x / 10);
    }
    putchar (x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
bool test = 0;
void init () {}



void solve () {
    int n;cin >> n;
    vvi g (n + 1);
    for (int i = 1; i <= n; i++) {
        int m;cin >> m;
        for (int j = 0; j < m; j++) {
            int x;cin >> x;
            g[i].pb (x);
        }
    }
    for (int i = 1;i <= n;i++) {
        map<pii, int> vis, ans;

        auto dfs = [&](auto&& self, int u, int fa) ->void {
            int idx = 0;
            for(int i = 0; i < g[u].size(); i ++)
                if(g[u][i] == fa)
                    idx = i;

            int v = g[u][(idx + 1) % g[u].size ()];
            if (vis.count ({ u, v }) != 0){
                // cout << ans.size ();
                for(auto [e, _] : ans)
                    cout << e.first << ' ' << e.second << '\n';

            }else {
                vis[{ u, v }] = 1;
                if (u > v)
                    ans[{v, u}] = 1;
                else
                    ans[{u, v}] = 1;

                self (self, v, u);
            }
        };
        dfs (dfs, i, -1);
        cout << endl;
    }
}


int main () {
    ios::sync_with_stdio (false), std::cin.tie (0), std::cout.tie (0);
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    int _ = 1;
    if (test)cin >> _;
    init ();
    while (_--) {
        solve ();
    }

    return 0;
}

/*######################################END######################################*/
// 链接：