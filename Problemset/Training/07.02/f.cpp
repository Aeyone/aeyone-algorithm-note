#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> res(n);
	for(int i = 0; i < n; i ++)
		res[i] = 3 * n + 2 * i + 1;
	res[0] --;
	res[n - 1] ++;
	int sum = 0;
	for(auto e : res)
		cout << e << ' ', sum += e;
	cout << '\n';
	// cout << sum << '\n';
	// cout << res[n - 1] - res[0] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}