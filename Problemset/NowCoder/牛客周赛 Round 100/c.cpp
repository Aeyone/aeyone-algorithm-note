#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), vis(n + 1), to(n + 1, -1);
	for(int i = 0; i < 2 * n; i ++)
		cin >> a[i];
	for(int i = 0; i < 2 * n; i ++){
		if(!vis[a[i]])
			vis[a[i]] = 1;
		else
			to[a[i]] = i;
	}
	int d = 0;
	for(int i = 0; i < 2 * n; i ++){
		if(i == to[a[i]])
			break;
		d += (to[a[i]] - i + 1);
		i = to[a[i]];
	}
	if(d == 2 * n)
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