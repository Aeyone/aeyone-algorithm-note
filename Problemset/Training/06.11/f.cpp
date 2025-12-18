#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	i64 res = 0;
	int mx = max(n, x);
	for(int i = 1; i <= mx; i ++){
		for(int j = 1; i <= mx / j; j ++){
			int l = 1, r = mx, ans = 0;
			while(l <= r){
				i64 mid = (l + r) >> 1;
				if(mid * (i + j) + i * j <= n && mid + i + j <= x)
					ans = mid, l = mid + 1;
				else
					r = mid - 1;
			}
			res += ans;
			// if(ans != 0)
			// 	cout << i << ' ' << j << ' ' << ans << '\n';
		}
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}