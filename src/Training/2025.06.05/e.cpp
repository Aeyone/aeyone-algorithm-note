#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int siz = 0, ans = 0;
	for(int i = 0; i < n - 1; i ++){
		if(a[i] < 2 * a[i + 1])
			siz ++;
		else
			siz = 0;
		if(siz >= k)
			ans ++;
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