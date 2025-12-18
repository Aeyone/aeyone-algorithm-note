#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool cmp(array<i64, 3> &a, array<i64, 3> &b){
	return (a[0] * b[2] < b[0] * a[2]);
}

void solve() {
	int n;
	cin >> n;
	vector<array<i64, 3>> a(n);
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		ans += a[i][1];
	}
	sort(a.begin(), a.end(), cmp);
	i64 C = 0;
	for(int i = 0; i < n; i ++){
		ans -= (C * a[i][0]);
		C += a[i][2];
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