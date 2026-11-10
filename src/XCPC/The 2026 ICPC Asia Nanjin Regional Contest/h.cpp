#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	a %= MOD;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
		res = a * res % p;
	}
	return res;
}

void init(int n) {
	fac.assign(n + 1, 1);
	for (int i = 1; i <= n; i ++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	inv.assign(n + 1, 1);
	inv[n] = qmi(fac[n], MOD - 2, MOD);
	for (int i = n - 1; i >= 0; i --) {
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
}

int A(int N, int M) {
	if (M > N || M < 0) {
		return 0;
	}
	return fac[N] * inv[N - M] % MOD;
}

int C(int N, int M) {
	if (M > N || M < 0) {
		return 0;
	}
	return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dfn(n), siz(n, 1), b(n);

	int T = 0;
	auto dfs1 = [&](auto &&self, int u, int fa)-> void {
		b[T] = a[u];
		dfn[u] = T ++;
		for (auto v : g[u]) if (v != fa) {
			self(self, v, u);
			siz[u] += siz[v];
		}
	};

	dfs1(dfs1, 0, -1);

	const int pow = 20;
	vector<array<int, pow + 1>> st(n);

	for(int i = 0; i < n; i ++){    //p = 0时
		st[i][0] = b[i];
	}

	for(int p = 1; n >> p > 0; p ++){   //枚举所有p
		for(int i = 0; i + (1 << p) <= n; i ++){  
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}

	auto query = [&](int l, int r)->int{
		if (l > r) return 0;
		int p = __lg(r - l + 1);
		return max(st[l][p], st[r - (1 << p) + 1][p]);
	};


	int ans = 0;
	auto dfs2 = [&](auto &&self, int u, int fa)-> void {
		int m = siz[u] - 1;
		if (fa != -1) {
			ans = (ans + query(dfn[u], dfn[u] + siz[u] - 1) * fac[k] % MOD * C(n - m - 2, k - m) % MOD * qmi(A(n - 1, k), MOD - 2, MOD) % MOD) % MOD;
		}
		for (auto v : g[u]) if (v != fa) {
			m = n - 1 - siz[v];
			int max = std::max(query(0, dfn[v] - 1), query(dfn[v] + siz[v], n - 1));
			ans = (ans + max * fac[k] % MOD * C(n - m - 2, k - m) % MOD * qmi(A(n - 1, k), MOD - 2, MOD) % MOD) % MOD;
			self(self, v, u);
		}
	};

	dfs2(dfs2, 0, -1);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(1e6);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}