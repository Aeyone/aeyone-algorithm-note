#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), vis(n + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	reverse(a.begin(), a.end());
	vector<array<int, 2>> res;
	for(int i = 0; i < n; i ++){
		int x = a[i] - 1;
		vis[a[i]] = true;
		while(x > 0){
			if(!vis[x])
				res.push_back({a[i], x});
			x --;
		}
		for(int j = 0; j < i; j ++)
			res.push_back({a[i], a[j]});
	}
	cout << res.size() << '\n';
	for(auto [x, y] : res)
		cout << x << ' ' << y << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}