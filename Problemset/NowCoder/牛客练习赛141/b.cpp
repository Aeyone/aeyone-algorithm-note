#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans = inf;
	for(int i = 0; i < n; i ++){
		if(i + m > n)
			break;

		int c1 = 0, c2 = 0;
		for(int j = i; j - i < m; j ++){
			if((a[j] & 1) != (j & 1))
				c1 ++;
			if((a[j] & 1) != !(j & 1))
				c2 ++;
		}
		ans = min(ans , min(c1, c2));
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}