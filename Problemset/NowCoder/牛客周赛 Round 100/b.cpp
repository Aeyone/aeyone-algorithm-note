#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), vis(2 * n), cnt(n + 1);
	for(int i = 0; i < 2 * n; i ++)
		cin >> a[i];
	for(int i = 0; i < 2 * n; i ++){
		if(!cnt[a[i]])
			cnt[a[i]] = 1, vis[i] = 1;
	}
	for(int i = 0; i < 2 * n; i ++){
		if(vis[i])
			cout << a[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i < 2 * n; i ++){
		if(!vis[i])
			cout << a[i] << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}