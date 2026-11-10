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
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 3>> v(k);
	for (int i = 0; i < k; i ++) {
		auto &[x, y, h] = v[i];
		cin >> x >> y >> h;
	}

	map<array<int, 2>, int> mp;

	for (auto [x, y, h] : v) {
		if ((x != 1 && x != n) || (y != 1 && y != m)) {
			cout << -1 << '\n';
			return;
		}
		mp[{x, y}] ++;
	}

	int ans = 0;
	if (n > 1) ans += abs(mp[{1, 1}] - mp[{n, m}]);
	if (m > 1) ans += abs(mp[{1, m}] - mp[{n, 1}]);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}