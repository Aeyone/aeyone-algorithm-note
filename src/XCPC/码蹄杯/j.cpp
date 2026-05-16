#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	i64 ans = 0;
	for (auto e : s) {
		ans += e;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}