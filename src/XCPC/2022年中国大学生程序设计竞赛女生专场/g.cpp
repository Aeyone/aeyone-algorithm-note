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
	int t, tot;
	cin >> t >> tot;
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0] >> a[i][1];
	}
	int idx = lower_bound(a.begin(), a.end(), array<int, 2>{t, 0}) - a.begin();
	int cur = 0, T = 0;
	for (int i = 0; i < idx; i ++) {
		auto [t, x] = a[i];
		cur = max(0ll, cur - (t - T) * k) + x;
		T = t;
	}
	cur = max(0ll, cur - (t - T) * k);
	T = t;
	if (cur != tot) {
		cout << "Wrong Record" << '\n';
		return;
	}
	int mn = INFLL, ans = T;
	for (int i = idx; i < n; i ++) {
		auto [t, x] = a[i];
		cur = max(0ll, cur - k * (t - T)) + x;
		T = t;
		if (mn >= (cur + k) / k) {
			mn = (cur + k) / k;
			ans = T;
		}
	}
	cout << ans << ' ' << mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}