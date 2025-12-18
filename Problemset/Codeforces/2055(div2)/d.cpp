#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<i64> a(n);
	cin >> a[0];
	a[0] *= 2, l *= 2, k *= 2;
	i64 mx = a[0];
	a[0] = 0;
	for(int i = 1; i < n; i ++){
		cin >> a[i];
		a[i] *= 2;
		i64 d = max(0ll, ((a[i] - mx) - (a[i - 1] + k)) / 2);
		mx += d;
		a[i] = min(a[i] + mx, max(a[i] - mx, a[i - 1] + k));
	}
	i64 ans = mx + max(0ll, l - (a.back() + k));
	cout << ans << '\n';
	// cout << "a = [";
	// for(int i = 0; i < n - 1; i ++)
	// 	cout << a[i] << ", ";
	// cout  << a[n - 1] << "]\nmax = "<< mx << '\n';
	// cout << "ans = " << ans * 2 << '\n';
	// cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}