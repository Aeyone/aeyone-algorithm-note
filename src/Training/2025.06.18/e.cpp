#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 0x3f3f3f3f3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i];
	
	i64 sum = 0, mn = infll;
	for(int i = 1; i <= n; i ++){
		sum += max(0ll, a[i % n] - b[i - 1]);
		if(a[i % n] - b[i - 1] > 0)
			mn = min(mn, b[i - 1]);
		else
			mn = min(mn, a[i % n]);
	}
	cout << sum + mn << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}