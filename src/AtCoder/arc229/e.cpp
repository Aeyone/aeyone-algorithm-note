#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

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

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	vector<DSU> d(3, DSU(n));
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --, w --;
		d[w].merge(u, v);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	map<array<int, 2>, int> mp;

	for (int i = 0; i < n; i ++) {
		int x = d[1].find(i);
		int y = d[2].find(i);
		if (mp.find({x, y}) != mp.end()) {
			d[0].merge(mp[{x, y}], i);
		}
		mp[{x, y}] = i;
	}

	int f = d[0].find(0);

	vector<int> ans;
	for (int i = 0; i < n; i ++) {
		if (d[0].find(i) == f) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << '\n';
	for (auto e : ans) cout << e << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}