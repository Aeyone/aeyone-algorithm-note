#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 h, n;
	cin >> h >> n;
	vector<int> a(n), c(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i], h -= a[i];
	for(int i = 0; i < n; i ++)
		cin >> c[i];

	auto check = [&](i64 x)->bool{
		i64 h1 = h;
		for(int i = 0; i < n; i ++){
			h1 -= (i64)a[i] * (x / c[i]);
			if(h1 <= 0)
				return true;
		}
		return false;
	};

	i64 l = 0, r = 1e12, ans = 0;
	while(l <= r){
		i64 mid = (l + r) >> 1;
		if(check(mid)){
			// cout << mid << '\n';
			ans = mid, r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans + 1 << '\n';
	// cout << h << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}