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
bool test = 0;

void init () {}


int query (int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    int op;
    cin >> op;
    return op;
}

void answer (int x) {
    cout << "! " << x << endl;
}

#define U dfs (lx, midx, ly, ry, q)
#define D dfs (midx + 1, rx, ly, ry, q)
#define L dfs (lx, rx, ly, midy, q)
#define R dfs (lx, rx, midy + 1, ry, q)
#define RU dfs (lx, midx, midy + 1, ry, q)
#define RD dfs(midx + 1, rx, midy + 1, ry, q)


int dfs (int lx, int rx, int ly, int ry, int q) {
    if (lx > rx || ly > ry) {
        return 0;
    }
    if (lx == rx && ly == ry) {
        return !query (lx, ly, q);
    }
    int midx = (lx + rx) / 2, midy = (ly + ry) / 2;

    if (lx == rx) {
        if (!query (lx, midy + 1, q)) {
            return (ry - midy) + L;
        }
        else {
            return R;
        }
    }

    if (ly == ry) {
        if (!query (midx + 1, ly, q)) {
            return (rx - midx) + U;
        }
        else {
            return D;
        }
    }

    //下半部分
    if (!query (midx + 1, ly, q)) {
        return (rx - midx) * (ry - ly + 1) + U;
    }

    //右半部分
    if (!query (lx, midy + 1, q)) {
        return (ry - midy) * (rx - lx + 1) + L;
    }

    //右下角
    if (!query (midx + 1, midy + 1, q)) {
        return (rx - midx) * (ry - midy) + L + RU;
    }

    return D + RU;
}

void solve () {
    int n, k;
    cin >> n >> k;

    int l = 1, r = n * n, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(1, 1, mid)) {
            ans = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 1, r = n * n;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (dfs (1, n, 1, n, mid) >= k) {
            ans = mid + 1;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    answer (ans);
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