#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	auto bfs = [&](int l, int r, int u)->int{
		int bl = l, br = r;
		int lu = u - 1, ru = u + 2;
		while(lu >= 0){
			int x = a[lu];
			if(x >= l && x <= r)
				return u - lu;

			l = min(l, x - 1);
			r = max(r, x + 1);
			lu --;
		}
		l = bl, r = br;
		while(ru < n){
			int x = a[ru];
			if(x >= l && x <= r)
				return ru - u - 1;

			l = min(l, x - 1);
			r = max(r, x + 1);
			ru ++;
		}
		return 1e9;
	};

	int ans = 1e9;
	for(int i = 0; i < n - 1; i ++){
		int l = a[i], r = a[i + 1];
		if(l > r)
			swap(l, r);
		if(r - l <= 1){
			cout << 0 << '\n';
			return;
		}
		l --, r ++;
		ans = min(ans, bfs(l, r, i));
	}
	if(ans > 2 * n)
		ans = -1;
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