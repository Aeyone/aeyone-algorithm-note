#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i ++)
		cin >> b[i];

	bool ok = true;
	int mn = b[0];
	i64 cur = 2 * b[0] - 1;
	for(int i = 1; i < n; i ++){
		ok &= (b[i] <= cur);

		if(b[i] < mn){
			mn = b[i], cur = 2 * b[i] - 1;
		}
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
	cin >> _;
	while (_ --)
		solve();
}