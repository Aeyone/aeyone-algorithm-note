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
	for(int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> len(n), la(n);
	auto dfs1 = [&](auto &&self, int u, int fa)->void{
		len[u] = 1;
		for(auto v : g[u]) if(v != fa) {
			self(self, v, u);
			len[u] = max(len[u], len[v] + 1);
		}
	};
	dfs1(dfs1, 0, -1);
	auto dfs2 = [&](auto &&self, int u, int fa)->void{
		multiset<int> st;
		for(auto v : g[u]) if(v != fa) {
			st.insert(len[v]);
		}
		st.insert(la[u]);
		for(auto v : g[u]) if(v != fa) {
			if(st.size() >= 2) {
				int tmp = len[v];
				st.erase(st.find(tmp));
				la[v] = *(--st.end()) + 1;
				st.insert(tmp);
			}
			self(self, v, u);
		}
	};
	dfs2(dfs2, 0, -1);
	for(int i = 0; i < n; i ++) {
		len[i] = max(len[i], la[i] + 1);
	}
	vector<int> ans(n + 1);
	for(int i = 0; i < n; i ++) {
		// cout << len[i] << ' ';
		ans[len[i]] ++;
	}
	for(int i = 1; i <= n; i ++) {
		ans[i] += ans[i - 1];
		cout << ans[i] + (ans[i] != n) << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}