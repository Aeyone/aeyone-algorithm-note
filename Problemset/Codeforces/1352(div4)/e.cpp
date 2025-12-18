#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	bool vis[8010];
	for(int i = 0; i < n; i ++)
		cin >> a[i], vis[a[i]] = true;

	vector<vector<int>> g(n);
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i ++){
		g[i].push_back(a[i]);
		for(int j = 0; j < i; j ++){
			
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}