#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> fa(n), d(n);
	auto dfs = [&](auto &&self, int u)->void{
		for (auto v : g[u]) {
			if (v == fa[u]) {
				continue;
			}
			fa[v] = u;
			d[v] = d[u] + 1;
			self(self, v);
		}
	};
	dfs(dfs, 0);
	vector<int> cnt(n);
	for (int i = 0; i < n; i ++) {
		cnt[d[i]] ++;
	}
	int mx = *max_element(cnt.begin(), cnt.end());
	int m = *max_element(d.begin(), d.end()) + 1;
	vector<multiset<pair<int, int>>> vv(m);
	bool ok = true;
	for (int i = 0; i < n; i ++) {
		vv[d[i]].insert({fa[i], i});
	}
	vector<vector<int>> ans;
	int tot = 0;
	// for (int i = 0; i < m; i ++) {
	// 	for (auto [x, y] : vv[i]) {
	// 		cout << "[" << x << ", " << y << "], ";
	// 	}
	// 	cout << '\n';
	// }
	while (tot != n) {
		vector<int> t;
		int la = -1;
		for (int i = 0; i < m; i ++) {
			if (vv[i].size() == 0) {
				la = -1;
				continue;
			}
			auto it1 = vv[i].lower_bound(pair<int, int>{la, -1});
			auto it2 = vv[i].upper_bound(pair<int, int>{la, INF});
			if (it1 != vv[i].begin()) {
				t.push_back((-- it1)->second);
				la = it1->second;
				vv[i].erase(it1);
			} else if (it2 != vv[i].end()) {
				t.push_back(it2->second);
				la = it2->second;
				vv[i].erase(it2);
			} else {
				la = -1;
			}
			tot += (la != -1);
		}
		if (t.size()) {
			ans.push_back(t);
		}
		cout << "t: ";
		for (auto e : t) {
			cout << e + 1 << ' ';
		}
		cout << '\n';
	}
	cout << ans.size() << '\n';
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