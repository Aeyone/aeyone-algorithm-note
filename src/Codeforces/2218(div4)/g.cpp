#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 676767677;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 2), cnt(m), any(m), ext(m);
	a[0] = a[n + 1] = INF;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	bool ok = true;
	for (int i = 1; i <= n; i ++) {
		if (a[i] != 0) {
			ok &= (a[i - 1] < a[i] || a[i + 1] < a[i]);
			if (min(a[i - 1], a[i + 1]) == a[i] - 1) {
				any[a[i]] ++;
			} else {
				ext[a[i]] ++;
			}
		}
	}
	if (!ok) {
		cout << 0 << '\n';
		return;
	}
	i64 ans = 1;
	int pre = cnt[0];
	for (int i = 1; i < m; i ++) {
		ans = (ans * qmi(cnt[i - 1], ext[i])) % MOD;
		ans = (ans * qmi(pre, any[i])) % MOD;
		pre += cnt[i];
	}
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