#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n), t(n);
	for(auto &e : s)
		cin >> e, e %= k, e = min(e, abs(k - e));
	for(auto &e : t)
		cin >> e, e %= k, e = min(e, abs(k - e));
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	bool ok = true;
	for(int i = 0; i < n; i ++)
		ok &= (s[i] == t[i]);
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}