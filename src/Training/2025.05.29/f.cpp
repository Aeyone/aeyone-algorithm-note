#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int x; 
	bool vis[4] = {};
	cin >> x;
	vis[x] = true;
	for(int i = 0; i < 3; i ++){
		int a, b;
		cin >> a >> b;
		swap(vis[a], vis[b]);
	}
	int ans = -1;
	for(int i = 1; i <= 3; i ++){
		if(vis[i])
			ans = i;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}