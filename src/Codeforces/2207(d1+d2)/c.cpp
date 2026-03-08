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
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector pre(n, vector<int>(n)), suf(n, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		int mx = a[i];
		for (int j = i + 1; j < n; j ++) {
			mx = max(mx, a[j]);
			suf[i][j] = suf[i][j - 1] + (h - mx);
		}
		mx = a[i];
		for (int j = i - 1; j >= 0; j --) {
			mx = max(mx, a[j]);
			pre[i][j] = pre[i][j + 1] + (h - mx);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		array<int, 2> mx = {a[i], i};
		ans = max(ans, h - a[i] + pre[i][0] + suf[i][n - 1]);
		for (int j = i + 1; j < n; j ++) {
			ans = max(ans, (h * 2 - a[i] - a[j]) + pre[i][0] + suf[j][n - 1] + (mx[1] == i ? 0 : suf[i][mx[1]] + pre[j][mx[1]] - (h - a[mx[1]])));
			mx = max(mx, {a[j], j});
		}
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