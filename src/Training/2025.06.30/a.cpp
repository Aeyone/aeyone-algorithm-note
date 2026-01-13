#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x7f7f7f7f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i];

	auto check = [&](int x)->bool{
		int l = 0, r = 0;
		for(int i = 0; i < n; i ++){
			l = max(l - x, a[i]);
			r = min(r + x, b[i]);
			if(l > r)
				return false;
		}
		return true;
	};

	i64 l = 0, r = inf, ans = -1;
	while(l <= r){
		i64 mid = (l + r) >> 1;
		if(check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
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