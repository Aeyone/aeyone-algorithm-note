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
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	int ans = -INFLL, mx = -INFLL;
	for (int i = n; i >= 1; i --) {
		suf[i] = max(a[i], suf[i + 1] + a[i]);
		mx = max(mx, suf[i]);
		ans = max(ans, pre[i - 1] + mx);
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