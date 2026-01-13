#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n);
	i64 mx = 0, sum = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}

	i64 len = mx;
	int ans = sum / len;
	i64 r = sum % len;

	while(k > len && ans < n){
		k -= len, ans ++;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}