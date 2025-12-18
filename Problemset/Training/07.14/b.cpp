#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> rg(m);
	for(int i = 0; i < m; i ++) {
		int l, r;
		cin >> l >> r;
		rg[i] = {l, r};
	}
	int q;
	cin >> q;
	vector<int> x(n + 1);
	for(int i = 1; i <= q; i ++)
		cin >> x[i];

	auto check = [&](int u)->bool {
		vector<int> a(n + 1), s(n + 1);
		for(int i = 1; i <= u; i ++)
			a[x[i]] = 1;

		for(int i = 1; i <= n; i ++){
			s[i] = s[i - 1] + a[i];
			// cout << a[i] << ' ';
		}
		// cout << '\n';
		bool ok = false;
		for(auto [l, r] : rg){
			int need = (r - l + 1) / 2 + 1;
			ok |= (s[r] - s[l - 1] >= need);
		}
		return ok;
	};

	int l = 1, r = q, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
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