#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int ca, cb, k;
	cin >> ca >> cb >> k;
	vector<int> a(k), b(k), cnta(ca + 1), cntb(cb + 1);
	for(int i = 0; i < k; i ++)
		cin >> a[i], cnta[a[i]] ++;
	for(int i = 0; i < k; i ++)
		cin >> b[i], cntb[b[i]] ++;

	i64 ans = 0;
	for(int i = 0; i < k; i ++){
		ans += (k - i) - cnta[a[i]] - cntb[b[i]] + 1;
		cnta[a[i]] --;
		cntb[b[i]] --;
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