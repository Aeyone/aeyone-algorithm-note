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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), fac(n + 1, 1);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int l = 0; l < n; l ++) {
		for (int r = l; r < n; r ++) {
			sum += (a[r] - a[l]);
		}
	}
	int ans = 1 + (a.front() != a.back());
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && a[l] == a[r]) {
			r ++;
		}
		int len = r - l;
		ans = ans * fac[len] % MOD;
	}
	cout << sum << ' ' << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	while (t --) {
		solve();
	}
}