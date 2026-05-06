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
	int n;
	cin >> n;
	vector<i64> a(n), cnt(n);
	i64 sum = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n != 0) {
		cout << -1 << '\n';
		return;
	}

	i64 x = sum / n, ans = 0;

	for (int i = 0; i < n; i ++) {
		if (a[i] > x) {
			cout << -1 << '\n';
			return;
		}
		cnt[i] = x - a[i];
		a[i] = x;

		if (i + 1 < n) {
			a[i + 1] -= cnt[i];
		}

		ans += max(0ll, cnt[i] - (i - 2 >= 0 ? cnt[i - 2] : 0));
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