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

void init () {}

void solve () {
    int n;
    cin >> n;
    vi color (4), a;
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        if (s[1] == 'D')color[0]++;
        if (s[1] == 'C')color[1]++;
        if (s[1] == 'H')color[2]++;
        if (s[1] == 'S')color[3]++;
    }

    vi p (6);
    for (int i = 0;i < 6;i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0;i < 4;i++) {
        ans += color[i] / 5;
        color[i] %= 5;
    }

    for (int i = 0; i < 4; i ++) {
        int x = color[i];
        while (x --) a.push_back(i);
    }

    int m = a.size();
    auto dfs = [&](this auto &&self, int op, int idx, int cnt) -> void {
        if (!p[op]) self(op + 1, idx, cnt);
        
        if (op <= 3) {
            for (int i = 0; i < m; i ++) {
                self (op + 1, i, 0);
                int t = a[i];
                a[i] = op;
                if (cnt < 3) self(op, i + 1, cnt + 1);
                else break;
                a[i] = t;
            }
        } else if (op <= 5) {
            for (int i = 0; i < m; i ++) {
                int t = a[i];
                a[i] = 0;
                self(op + 1, 0, 0);
                a[i] = 1;
                self(op + 1, 0, 0);
                a[i] = 2;
                self(op + 1, 0, 0);
                a[i] = 3;
                self(op + 1, 0, 0);
                a[i] = t;
            }
        } else {
            int cnt[4] = {};
            for (auto e : a) cnt[e] ++;

            for (auto e : a) cerr << e << ' ';
            cerr << '\n';

            int tot = 0;
            for (int i = 0; i < 4; i ++) {
                tot += (cnt[i] >= 5);
            }
            ans = max(ans, ans + tot);
        }
    };
    cout << ans << '\n';

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