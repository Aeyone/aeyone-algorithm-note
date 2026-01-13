#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	set<array<int, 2>> st;
	for(int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		if(u > v) {
			swap(u, v);
		}
		st.insert({u, v});
	}
	int res = INF;
	for(int mask = 0; mask < 1 << n; mask ++) {
		int cnt = __builtin_popcount(mask);
		if(cnt < 3 || (n - cnt > 0 && n - cnt < 3)) {
			continue;
		}
		set<int> alls;
		vector<int> vis(n);
		int tot = m, ans = INF;
		auto dfs = [&](auto &&self, int cur, int cnt, int root)->void{
			if(cnt == alls.size()) {
				int u = min(root, cur), v = max(root, cur);
				ans = min(ans, tot + (st.find({u, v}) != st.end() ? -1 : 1));
				return;
			}
			for(auto e : alls) {
				if(vis[e]) {
					continue;
				}
				vis[e] = true;
				if(root == -1) {
					self(self, e, 1, e);
				}else{
					int u = min(e, cur), v = max(e, cur);
					if(st.find({u, v}) != st.end()) {
						tot --;
						self(self, e, cnt + 1, root);
						tot ++;
					}else{
						tot ++;
						self(self, e, cnt + 1, root);
						tot --;
					}
				}
				vis[e] = false;
			}
		};
		for(int i = 0; i < n; i ++) {
			if(mask >> i & 1) {
				alls.insert(i);
			}
		}
		dfs(dfs, -1, 0, -1);
		if(cnt == n) {
			res = min(res, ans);
			continue;
		}
		tot = ans, ans = INF;
		alls.clear();
		for(int i = 0; i < n; i ++) {
			if(!(mask >> i & 1)) {
				alls.insert(i);
			}
		}
		dfs(dfs, -1, 0, -1);
		res = min(res, ans);
	}
	cout << res << '\n';
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