#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct DSU {
	vector<int> f, siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool cmp(int x, int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x, int y) {//将y合并至x中
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

// static mt19937_64 rng (
//     chrono::steady_clock::now().time_since_epoch().count()
// );
// #define rand(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

void solve() {
	int n;
	cin >> n;
	// n = rand(20, 10);
	vector<int> a(2 * n + 1), e(2 * n + 1), idx(n + 1);
	// vector<vector<int>> g(2 * n + 1);
	DSU dsu(2 * n + 1);
	// for (int i = 1; i <= 2 * n; i ++) {
	// 	a[i] = (i + 1) / 2;
	// }
	// shuffle(a.begin() + 1, a.end(), rng);
	for (int i = 1; i <= 2 * n; i ++) {
		// cerr << a[i] << ' ';
		cin >> a[i];
		if (idx[a[i]] != 0) {
			e[i] = idx[a[i]];
			e[idx[a[i]]] = i;
			// g[i].push_back(idx[a[i]]);
			// g[idx[a[i]]].push_back(i);
			dsu.merge(i, e[i]);
		} else {
			idx[a[i]] = i;
		}
	}
	// cerr << '\n';

	string s = string(2 * n + 1, '0');

	for (int l = 1, r = 2 * n; l < r; ) {
		if (dsu.cmp(l, r)) {
			s[r - 1] = '(';
			s[r] = ')';
			dsu.merge(r, r - 1);
			r -= 2;
		} else {
			s[l] = '(';
			s[r] = ')';
			dsu.merge(r, l);
			l ++, r --;
		}
	}
	cout << s.substr(1) << '\n';

	// vector<int> stk;
	// for (int i = 1; i <= 2 * n; i ++) {
	// 	if (s[i] == '(') {
	// 		stk.push_back(i);
	// 	} else {
	// 		if (!stk.size()) {
	// 			cout << "NO1" << '\n';
	// 			return;
	// 		}
	// 		g[i].push_back(stk.back());
	// 		g[stk.back()].push_back(i);
	// 		stk.pop_back();
	// 	}
	// }

	// vector<int> vis(2 * n + 1);

	// auto dfs = [&](auto &&self, int u, int fa)-> void {
	// 	vis[u] = 1;
	// 	if (u == 1 && fa != -1) return;
	// 	for (auto v : g[u]) if (v != fa) {
	// 		self(self, v, u);
	// 	}
	// };
	// dfs(dfs, 1, -1);

	// bool ok = true;
	// for (int i = 1; i <= 2 * n; i ++) {
	// 	cerr << vis[i] << ' ';
	// 	ok &= (vis[i] && g[i].size() == 2);
	// }
	// cerr << '\n';
	// if (ok) {
	// 	cout << "OK" << '\n';
	// } else {
	// 	cout << "NO2" << '\n';
	// }

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}