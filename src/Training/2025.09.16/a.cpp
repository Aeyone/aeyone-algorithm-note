#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<i64, i64> cnt;
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	int q;
	cin >> q;
	while(q --){
		i64 x, y;
		cin >> x >> y;
		i64 l = (x >= 0 ? (x + 1) / 2 : x / 2), r = inf, a1 = inf;
		while(l <= r){
			i64 mid = (l + r) / 2;
			if(mid * mid - x * mid + y >= 0)
				a1 = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		i64 ans = 0;
		if(a1 * a1 - x * a1 + y == 0)
			ans = (a1 == x - a1 ? (cnt[a1] - 1) * cnt[a1] / 2 : cnt[a1] * cnt[x - a1]);
		cout << ans << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}