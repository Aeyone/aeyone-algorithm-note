#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 ans = 0;
	for(auto &e : a){
		cin >> e;
		i64 l = 1, r = e, res = -1;
		while(l <= r){
			i64 mid = (l + r) >> 1;
			if(e - mid * (mid + 1) / 2 <= 0)
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		ans += res;
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