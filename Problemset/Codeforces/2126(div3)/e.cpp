#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> pre(n), suf(n);
	for(int i = 0; i < n; i ++)
		cin >> pre[i];
	for(int i = 0; i < n; i ++)
		cin >> suf[i];

	bool ok = (pre.back() == suf.front());
	for(int i = 1; i < n; i ++)
		ok &= ((pre[i - 1] % pre[i]) == 0);

	for(int i = n - 2; i >= 0; i --)
		ok &= ((suf[i + 1] % suf[i]) == 0);

	for(int i = 0; i < n - 1; i ++)
		ok &= (__gcd(pre[i], suf[i + 1]) == pre.back());

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}