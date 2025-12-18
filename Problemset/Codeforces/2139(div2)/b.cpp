#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<i64> a(n), b(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		b[i] = (i64)k * a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	i64 ans = 0;
	for(int i = 0; i < min(n, k); i ++){
		ans += b[i] - a[i] * i;
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