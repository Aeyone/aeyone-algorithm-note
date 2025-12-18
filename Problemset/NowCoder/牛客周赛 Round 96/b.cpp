#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, m, k;
	cin >> n >> m >> k;
	 vector<i64> res;
	 for(int i = 0; i < n; i ++){
	 	i64 a;
	 	cin >> a;
	 	res.push_back(abs(a - k));
	 }
	 sort(res.begin(), res.end());

	 i64 ans = 0;
	 for(int i = 0; i < m; i ++)
	 	ans = max(ans, res[i]);
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