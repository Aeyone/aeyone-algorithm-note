#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), cnt(x + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	bool ok = true;
	for(int i = 1; i < x; i ++){
		cnt[i + 1] += cnt[i] / (i + 1);
		ok &= ((cnt[i] % (i + 1)) == 0);
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}