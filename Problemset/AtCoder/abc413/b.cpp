#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i < n; i ++)
		cin >> g[i];
	map<string, bool> mp;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == j)
				continue;
			mp[g[i] + g[j]] = true;
		}
	}
	cout << mp.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}