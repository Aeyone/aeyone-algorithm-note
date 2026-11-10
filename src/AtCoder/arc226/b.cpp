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
	int n, m;
	cin >> n >> m;
	vector<int> a(64);
	for (int i = 0; i < m; i ++) {
		cin >> a[i];
	}

	auto check = [&](int x)-> bool {
		i128 cost = 0;
		for (int i = 63; i >= 0; i --, cost <<= 1) {
			if(x >> i & 1) cost += n;
			cost -= a[i];
			if (cost < 0) return false;
		}
		return true;
	};

	int l = 0, r = INFLL;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
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