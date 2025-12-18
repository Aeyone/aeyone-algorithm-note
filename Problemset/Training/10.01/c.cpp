#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int a, b;
	cin >> a >> b;
	int ans = inf;
	for(int i = 1; i <= 1e5; i ++){
		ans = min(ans, (a + i - 1) / i + (b + i - 1) / i + (i - 1));
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}