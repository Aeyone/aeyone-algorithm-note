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
	int n, k;
	cin >> n >> k;
	int m = n * k;
	vector<vector<int>> g(m);
	for(int i = 0; i < m - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> cnt(m), ok(m, 1);
	auto dfs = [&](auto &&self, int u, int fa)->void{
		vector<int> son;
		for(auto v : g[u]) if(v != fa) {
			self(self, v, u);
			son.push_back(cnt[v]);
			ok[u] &= ok[v];
		}
		sort(son.begin(), son.end(), greater<int>{});
		while(son.size() && son.back() == 0) {
			son.pop_back();
		}
		cnt[u] = 1;
		for(auto e : son) {
			cnt[u] = (cnt[u] + e) % k;
		}
		cnt[u] %= k;
		ok[u] &= (son.size() <= 1 || (son.size() == 2 && cnt[u] == 0));
	};
	dfs(dfs, 0, -1);
	if(ok[0]) {
		cout << "Yes" << '\n';
	}else {
		cout << "No" << '\n';
	}
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