#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	vector<int> vis(n + 2);
	vis[0] = true;
	for(int i = 1; i <= n; i ++){
		if(vis[i - 1] && i + a[i] <= n)
			vis[i + a[i]] = true;
		if(i - a[i] - 1 >= 0)
			vis[i] |= (vis[i - a[i] - 1]);
	}
	if(vis[n])
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}