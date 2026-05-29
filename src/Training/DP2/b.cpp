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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &e : a) cin >> e;

	int ans = INF;
	for (int l = 0, r = 0, sum = 0; l < n; l ++) {
		while (r < n && sum < k) {
			sum += a[r];
			r ++;
		}
		if (sum >= k) {
			ans = min(ans, r - l);
		}
		sum -= a[l];
	}
	cout << (ans == INF ? -1 : ans) << '\n';
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