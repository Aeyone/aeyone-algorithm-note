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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	b[0] = 1;
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		b[i] = a[i] - a[i - 1];
		ans += (b[i] == 0);
	}
	vector<int> pre(n), suf(n + 1);
	pre[0] = 1;
	for (int i = 1; i < n; i ++) {
		pre[i] = pre[i - 1] + (b[i] > 0);
	}
	for (int i = n - 1; i >= 0; i --) {
		suf[i] = suf[i + 1] + (b[i] < 0);
	}

	int mn = INF;
	for (int i = 0; i <= n; i ++) {
		mn = min(mn, (i ? pre[i - 1] : 0) + suf[i]);
	}
	cout << ans + mn << '\n';
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