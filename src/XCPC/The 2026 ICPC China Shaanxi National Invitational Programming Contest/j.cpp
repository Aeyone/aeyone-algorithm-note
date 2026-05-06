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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	array<int, 3> ans = {0, n, n};
	for (int i = 1; i < n - 1; i ++) {
		int cur = a[i - 1] + a[i];
		int l = i - 1;
		int r = ranges::lower_bound(a, cur) - a.begin() - 1;
		ans = max(ans, {r - l + 1, l, r});
	}
	auto [len, l, r] = ans;
	if (len < 3) {
		cout << 0 << '\n';
		return;
	}
	cout << len << ' ';
	for (int i = l; i <= r; i ++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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