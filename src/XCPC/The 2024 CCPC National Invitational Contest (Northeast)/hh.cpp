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

void solve () {
    int n, m;
    cin >> n >> m;
    vvi g (n + 1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    vpii v (m);

    for (int i = 0;i < m;i++) {
        cin >> v[i].ft >> v[i].sd;
    }
	vector<int> dep(n + 1), siz(n + 1), son(n + 1, -1), f(n + 1);
	auto init = [&](this auto &&self, int u, int fa = -1)-> void {
		siz[u] = 1;
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			f[v] = u;
			self(v, u);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v] > siz[son[u]]) {
				son[u] = v;
			}
		}
	};
	init(1);

	vector<int> in(n + 1), out(n + 1), seg(n + 1), top(n + 1);
	int t = 1;
	auto dfs = [&](this auto &&self, int u, int fa, int ftop)-> void {
		in[u] = t, seg[t ++] = u;
		top[u] = ftop;
		if (son[u] != -1) {
			self(son[u], u, ftop);
		}
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			self(v, u, v);
		}
		out[u] = t;
	};
	dfs(1, -1, 1);

	auto lca = [&](int x, int y)-> int {
		int len = 0;
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) {
				swap(x, y);
			}
			len += (in[top[x]] - in[x]);
			x = f[top[x]];
		}
		len += abs(in[y] - in[x]);
		return (in[x] < in[y] ? x : y);
	};

	auto get = [&](int u, int k)-> int {
		if (dep[u] < k) {
			return -1;
		}
		int d = dep[u] - k;
		while (dep[top[u]] > d) {
			u = f[top[u]];
		}
		return seg[in[u] - (dep[u] - d)];
	};

    auto check = [&](int d)->bool {
        vi diff (n + 10);
        for (auto [x, y] : v) {
            int t = lca (x, y);
            int dx = dep[x] - dep[t], dy = dep[y] - dep[t];
            int len = dx + dy;

            //所有点都能选
            if (len <= d) {
                diff[in[1]] += 2;
                continue;
            }

            if (len > 2 * d) {
                return false;
            }

            if (dx > d) {
                int r = get (x, d);
                diff[in[r]]++;
                diff[out[r]]--;
            }
            else {
                diff[in[1]]++;
                int rr = get (y, len - d - 1);
                diff[in[rr]]--;
                diff[out[rr]]++;
            }

            if (dy > d) {
                int l = get (y, d);
                diff[in[l]]++;
                diff[out[l]]--;
            }
            else {
                diff[in[1]]++;
                int ll = get (x, len - d - 1);
                diff[in[ll]]--;
                diff[out[ll]]++;
            }
        }
        //恢复差分数组
        for (int i = 1; i <= n; i++) {
        	diff[i] += diff[i - 1];
            if (diff[i] == 2 * m) {
                return true;
            }
        }
        return false;
    };



    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check (mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";

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