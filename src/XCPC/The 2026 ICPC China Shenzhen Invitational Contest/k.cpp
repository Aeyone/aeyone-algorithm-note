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
	i64 n, m;
	cin >> n >> m;

	vector<array<i64, 2>> ps;
	i64 x = n;
	for (int i = 2; i <= x / i; i ++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt ++;
		}
		if (cnt > 0) {
			ps.push_back({i, cnt});
		}
	}
	if (x > 1) {
		ps.push_back({x, 1});
	}

	int tot = ps.size();
	vector<vector<i64>> pow(tot);
	for (int i = 0; i < tot; i ++) {
		auto [p, a] = ps[i];
		pow[i].assign(a + 1, 1);
		for (int j = 1; j <= a; j ++) {
			pow[i][j] = pow[i][j - 1] * p;
		}
	}

	i64 ans = 0;	
	auto dfs = [&](this auto &&self, int idx, i64 d, i64 phi, i64 g)-> void {
		if (idx == tot) {
			phi %= MOD, d %= MOD;
			ans = (ans + phi * d % MOD * ((m / g + 1) % MOD) % MOD) % MOD;
			return;
		}
		auto [p, a] = ps[idx];
		for (int i = 0; i <= a; i ++) {
			i64 cur_phi = phi, cur_g = g;
			if (a - i > 0) {
				cur_phi *= pow[idx][a - i - 1] * (p - 1);
			}
			cur_g *= pow[idx][(i + 1) / 2];
			self(idx + 1, d * pow[idx][i], cur_phi, cur_g);
		}
	};
	dfs(0, 1, 1, 1);
	cout << ans << '\n';
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