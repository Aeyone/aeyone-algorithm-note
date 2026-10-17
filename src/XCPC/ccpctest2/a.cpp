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
	vector<i64> a(2 * n + 1), s(2 * n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int i = 1; i <= 2 * n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	i64 max = -INFLL;
	int u = -1;
	for (int i = k; i <= 2 * n; i ++) {
		if (s[i] - s[i - k] > max) {
			u = i;
			max = s[i] - s[i - k];
		}
	}
	u -= (k - 1);
	if (u > n) u -= n;
	cout << max << '\n';
	cout << u << '\n';
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