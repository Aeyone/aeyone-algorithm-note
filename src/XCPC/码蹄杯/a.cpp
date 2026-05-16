#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	vector<array<int,2>> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
		ans += (y >= x);
	}
	cout << ans << ' ' << n - ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}