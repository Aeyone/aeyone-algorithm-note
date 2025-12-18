#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, cnt = 1, ans = 3;
    cin >> n;
    while (cnt < n) {
        cnt = cnt * 2 + 1;
        ans += 2;
    }
    cout << ans << endl;
}
signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}