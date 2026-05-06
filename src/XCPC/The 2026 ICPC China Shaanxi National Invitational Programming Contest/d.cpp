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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	ranges::sort(a);

	i64 ans = m, x = 0, cur = 0;

	for (int i = 1; i <= n; i ++) {
		i64 t = (a[i] - x + i - 1) / i;
		cur += t;
		if (cur > m) {
			break;
		}
		x += t * i - a[i];
		ans = max(ans, 1ll * (m - cur) * (i + 1) + x);
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