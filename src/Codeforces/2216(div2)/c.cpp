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
	int n, k, p, q;
	cin >> n >> k >> p >> q;
	vector<i64> a(n + 1), pre1(n + 1), pre2(n + 1), pre3(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		pre1[i] = pre1[i - 1] + min(a[i] % p, (a[i] % q) % p);
		pre2[i] = pre2[i - 1] + (a[i] % p);
		pre3[i] = pre3[i - 1] + ((a[i] % q) % p);
	}

	i64 ans = INFLL;
	for (int i = 1; i + k - 1 <= n; i ++) {
		int l = i, r = i + k - 1;
		ans = min(ans, pre1[l - 1] + pre1[n] - pre1[r] + min(pre2[r] - pre2[l - 1], pre3[r] - pre3[l - 1]));
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