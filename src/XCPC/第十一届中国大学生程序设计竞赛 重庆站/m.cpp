#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 0;
#endif

const int MOD = 998244353;

vector<int> minp, p, rk;
 
void sieve(int n) {
	minp.assign(n + 1, 0);
	rk.assign(n + 1, 0);
	p.clear();
	for (int i = 2; i <= n; i++) {
		if (minp[i] == 0) {
			minp[i] = i;
			p.push_back(i);
		}
		for (auto e : p) {
			if (1ll * i * e > n) {
				break;
			}
			minp[i * e] = e;
			if (e == minp[i]) {
				break;
			}
		}
	}
    for (int i = 0; i < p.size(); i ++) {
        rk[p[i]] = i + 1;
    }
}

template<class T>
struct SegmentTree {
	struct Info {
		T val = 0;
        int ls = 0, rs = 0;
	};

	int n, idx = 0;
	vector<Info> info;

	SegmentTree(int n = 0) { init(n); }

	void init(int n) {
		this->n = n;
		info.assign(n * 30 * 8, Info());
	}

	int build(int l, int r, const vector<T>& a) {
        int rt = ++ idx;
		if (l == r) {
			info[rt].val = a[l];
		} else {
            int mid = (l + r) / 2;
            info[rt].ls = build(l, mid, a);
            info[rt].rs = build(mid + 1, r, a);
        }
        return rt;
	}

	int modify(int p, int l, int r, int qi, T val) {
        int rt = ++ idx;
        info[rt] = info[p];
		if (l == r) {
            info[rt].val += val;
		} else {
            int mid = (l + r) / 2;
            if (qi <= mid) info[rt].ls = modify(info[rt].ls, l, mid, qi, val);
            if (qi > mid) info[rt].rs = modify(info[rt].rs, mid + 1, r, qi, val);
        }
        return rt;
	}

	Info query(int p, int l, int r, int qi) {
		if (l == r) {
			return info[p];
		}
		int mid = (l + r) / 2;
		if (qi <= mid) return query(info[p].ls, l, mid, qi);
		if (qi > mid) return query(info[p].rs, mid + 1, r, qi);
	}

	int build(const vector<T>& a) {
		return build(1, n, a);
	}

    // p为要修改的版本的头编号，返回更改后版本的头编号
	int modify(int p, int qi, T val) { 
		return modify(p, 1, n, qi, val);
	}

	Info query(int p, int qi) {
		return query(p, 1, n, qi);
	}
};


void solve() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> g(n);
    vector<array<int, 3>> a(n);
    for (int i = 1; i < n; i ++) {
        auto &[w, u, v] = a[i];
        cin >> w >> u >> v;
        u --, v--;
        g[v].push_back(i);
        g[i].push_back(v);
    }

    const int pow = 21;
	vector<array<int, pow + 1>> up(n);
	vector<int> dep(n);

	auto init = [&](this auto &&self, int u, int fa)->void {
		up[u][0] = fa;
		for (int p = 1; dep[u] >> p > 0; p ++) {
			int la = up[u][p - 1];
			up[u][p] = up[la][p - 1];
		}
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(v, u);
		}
	};
	init(0, -1);

	auto lca = [&](int x, int y)-> int {
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		for (int p = 20; p >= 0; p --) { // 使x, y跳到同一树高
			if (dep[x] - (1 << p) >= dep[y]) {
				x = up[x][p];
			}
		}
		if (x == y) { // 已经相等说明y就是x的祖先
			return x;
		}
		for (int p = 20; p >= 0; p --) { // 一起上跳至差一格到lca
			if (up[x][p] != up[y][p]) {
				x = up[x][p];
				y = up[y][p];
			}
		}
		return up[x][0]; // 最后不要忘记再跳一次 x, y随意，注意区间操作时两个都需要取
	};

    int m = p.size();
    vector<int> root(n), ans(n, 1);
    SegmentTree<int> st(m);

    root[0] = 0, ans[0] = c;

    for (int i = 0; i < m && p[i] <= c / p[i]; i ++) {
        int cnt = 0;
        while (c % p[i] == 0) {
            c /= p[i], cnt ++;
        }
        if (cnt > 0) {
            int id = rk[p[i]];
            root[0] = st.modify(root[0], id, cnt);
        }
    }
    if (c > 1) root[0] = st.modify(root[0], rk[c], 1);

    
    for (int i = 1; i < n; i ++) {
        auto [w, u, v] = a[i];
        int fa = lca(u, v), ffa = up[fa][0];
        root[i] = root[v];

        auto calc = [&](int p, int cnt)-> void {
            int id = rk[p];
            int la = st.query(root[u], id).val + st.query(root[v], id).val - st.query(root[fa], id).val;
            if (ffa != -1) la -= st.query(root[ffa], id).val;

            cnt = max(0, cnt - la);
            root[i] = st.modify(root[i], id, cnt);
            while (cnt --) ans[i] *= p;
        };

        for (int j = 0; j < m && p[j] <= w / p[j]; j ++) {
            int cnt = 0;
            while (w % p[j] == 0) {
                w /= p[j], cnt ++;
            }
            if (cnt > 0) calc(p[j], cnt);
        }
        if (w > 1) calc(w, 1);
    }
    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    sieve(1e6);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}