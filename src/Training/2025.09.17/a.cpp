#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;

	i64 ans = 1, suf = 1;
	for(int i = n - 2; i >= 0; i --){
		suf = 1 + suf + (a[i] > a[i + 1] ? n - 1 - i : 0);
		ans += suf;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}