#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x7f7f7f7f;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	sort(a.begin(), a.end());
	int ans = inf;
	for(int i = 0; i <= k; i ++){
		ans = min(ans, a[i + n - k - 1] - a[i]);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}