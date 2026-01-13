#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = (i128)a * a % p) if(b & 1){
		res = (i128)a * res % p;
	}
	return res;
}

void solve() {
	int n, c;
	cin >> n >> c;
	c --;
	i64 sum = 0;
	vector<i64> a(n), u(n), idx(n);
	iota(u.begin(), u.end(), 0);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	a[c] ++;
	sort(u.begin(), u.end(), [&](const int &x, const int &y)->bool{
		return (a[x] > a[y]);
	});
	for (int i = 0; i < n; i ++) {
		idx[u[i]] = i;
	}
	vector<vector<i64>> p(2, vector<i64>(n, 0));
	p[1][idx[c]] = 1;
	i64 ans = 0;
	for (int cnt = 1; cnt <= 100; cnt ++) {
		p[cnt & 1 ^ 1].assign(n, 0);
		for (int i = 0; i < n; i ++) {
			ans = (ans + cnt * p[cnt & 1][i] % MOD * (a[u[i]] - 1) % MOD * qmi(sum, MOD - 2, MOD) % MOD) % MOD;
			i64 tot = 0;
			for (int j = 0; a[u[j]] > a[u[i]]; j ++) {
				tot += a[u[j]];
				p[cnt & 1 ^ 1][j] = (p[cnt & 1 ^ 1][j] + p[cnt & 1][i] * a[u[j]] % MOD * qmi(sum, MOD - 2, MOD) % MOD) % MOD;
			}
			p[cnt & 1 ^ 1][i] = (p[cnt & 1 ^ 1][i] + p[cnt & 1][i] * (sum - tot) % MOD * qmi(sum, MOD - 2, MOD) % MOD) % MOD;
		}
		cerr << "ans = " << ans << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}