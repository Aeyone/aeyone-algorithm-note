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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> pre(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + (a[i] / x) * y;
	}
	for (int i = n; i >= 0; i --) {
		suf[i] = suf[i + 1] + (a[i] / x) * y;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, a[i] + pre[i - 1] + suf[i + 1]);
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