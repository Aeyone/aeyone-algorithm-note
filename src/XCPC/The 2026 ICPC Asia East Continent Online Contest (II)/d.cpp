#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353

struct Seg {
	int l, r, op, max, u;
};

int qmi(int a, int b, int p) {
	int res = 1;
	for (; b; b >>= 1, a = a * a % p) if (b & 1) {
		res = a * res % p;
	}
	return res;
}

vector<int> fac, inv;

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

int C(int N, int M) {
	if (M > N || M < 0) {
		return 0;
	}
	return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int A(int N, int M) {
	if (M > N || M < 0) {
		return 0;
	}
	return fac[N] * inv[N - M] % MOD;
}

void solve() {
	int n, q;
	cin >> n >> q;

	map<int, array<int, 2>> mp;
	bool ok = false;
	vector<Seg> tot;
	while (q --) {
		int u, x;
		cin >> u >> x;
		int t = __lg(u);
		int l = (u << n - t) - (1 << n) + 1;
		int r = l + (1 << (n - t)) - 1;
		if (mp.find(x) != mp.end()) {
			auto [L, R] = mp[x];
			ok |= (R < l || r < L);
			L = std::max(l, L);
			R = std::min(r, R);
			mp[x] = {L, R};
		} else {
			mp[x] = {l, r};
		}
		tot.push_back({l, r, 1, x, u});
	}
	if (ok) {
		cout << 0 << '\n';
		return;
	}

	vector<int> a(1 << n + 1), op(1 << n + 1);
	for (auto &[l, r, _op, max, u] : tot) {
		auto [L, R] = mp[max];
		_op = (l == L && r == R);
		a[u] = max;
		op[u] = _op;
	}

	for (int i = 1; i < 1 << n; i ++) {
		if (a[i] == 0) continue;
		int l = 2 * i, r = 2 * i + 1;
		if (a[r] > a[i] || a[l] > a[i]) {
			cout << 0 << '\n';
			return;
		}
		if (a[l] == 0) {
			if (a[r] == 0) {
				a[l] = a[r] = a[i];
				op[l] = op[r] = op[i];
			} else {
				a[l] = a[i];
				op[l] = op[i];
			}
		} else if (a[r] == 0) {
			a[r] = a[i];
			op[r] = op[i];
		}
	}
	
	map<array<int, 2>, int> cnt;
	for (int i = 1 << n; i < (1 << n + 1); i ++) {
		cnt[{a[i], op[i]}] ++;
	}

	int res = 0;
	int ans = 1;
	for (auto [p, len] : cnt) {
		auto [e, op] = p;
		// cerr << e << ' ' << op << ' ' << len << '\n';
		if (e == 0) {
			continue;
		}
		if (op == 0) {
			ans = ans * C(e - res - 1, len) % MOD * fac[len] % MOD;
		} else {
			ans = ans * C(e - res - 1, len - 1) % MOD * fac[len] % MOD;
		}
		res += len;
	}
	ans = ans * fac[(1 << n) - res] % MOD;
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init(1e6);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}