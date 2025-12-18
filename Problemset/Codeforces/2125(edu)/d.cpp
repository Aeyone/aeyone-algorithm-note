#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

int qmi(int a, int b, int p){
	int res = 1;
	while(b){
		if(b & 1)
			res = (i64)a * res % p;
		b >>= 1;
		a = (i64)a * a % p;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 3>>> g(m);
	i64 sum = 1;
	for(int i = 0; i < n; i ++){
		i64 l, r, p, q;
		cin >> l >> r >> p >> q;
		l --, r --;
		int x = p * qmi(q, mod - 2, mod) % mod;
		int xx = (q - p) * qmi(q, mod - 2, mod) % mod;
		sum = (sum * xx) % mod;
		g[l].push_back({r, x, xx});
	}
	i64 ans = 0, s = 1, ss = 1;
	auto dfs = [&](auto &&self, int u)->void{
		if(u == m){
			ans = (ans + (sum * s % mod) * qmi(ss, mod - 2, mod) % mod) % mod;
			return;
		}
		for(auto [v, x, xx] : g[u]){
			s = (s * x) % mod;
			ss = (ss * xx) % mod;
			self(self, v + 1);
			s = (s * qmi(x, mod - 2, mod)) % mod;
			ss = (ss * qmi(xx, mod - 2, mod)) % mod;
		}
	};
	dfs(dfs, 0);
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}