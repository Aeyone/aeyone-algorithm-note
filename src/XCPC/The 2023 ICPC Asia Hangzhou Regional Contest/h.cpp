#include <bits/stdc++.h>

#define ft first
#define sd second

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort_all1(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse_all1(x) reverse(all1(x))

#define setp(x) fixed << setprecision(x)

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

static mt19937_64 rng (chrono::steady_clock::now ().time_since_epoch ().count ());
#define randInt(l, r) (uniform_int_distribution<int>((l),(r))(rng))

/*#####################################BEGIN#####################################*/

const int mod = 1e9 + 7;
bool test = 1;

vector<ll> fac, inv;

ll ksm (ll a, ll b, int p) {
    a %= p;
    ll res = 1;
    for (;b; b >>= 1, a = a * a % p) if (b & 1) {
        res = a * res % p;
    }
    return res;
}

void init () {
    int n = 5e5 + 10;
    fac.assign (n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv.assign (n + 1, 1);
    inv[n] = ksm (fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

void solve () {
    int n;
    cin >> n;
    vl a (n + 1), b (n + 1), w (n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    vi dep (n + 1);
    vi v;
    vvi g (n + 1);
    for (int i = 1;i <= n;i++) {
        if (a[i] < a[b[i]]) {
            dep[i] = 1;
            v.pb (i);
        }
        else if (a[i] >= a[b[i]] + w[b[i]]) {
            dep[i] = 0;
        }
        else {
            g[b[i]].pb (i);
        }
    }

    auto dfs = [&](auto&& self, int u)->void {
        for (auto v : g[u]) {
            dep[v] = dep[u] + 1;
            self (self, v);
        }
        };

    for (auto x : v) {
        dfs (dfs, x);
    }
    for (int i = 1;i <= n;i++) {
        if (dep[i] == 0) {
            cout << a[i] << " ";
        }
        else {
            ll ans = (a[i] + w[i] * ksm (fac[dep[i]], mod - 2, mod)) % mod;
            cout << ans << " ";
        }
    }
    cout << "\n";



}

signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int _ = 1;
    if (test) cin >> _;

    init ();
    while (_--) {
        solve ();
    }

    return 0;
}

/*######################################END######################################*/