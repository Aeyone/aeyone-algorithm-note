#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i ++){
		int x; cin >> x;
		map<int, bool> mp;
		while(!mp[x]){
			mp[x] = true;
			a[i].push_back(x);
			x ^= (x / 2);
			// cout << x << ' ';
		}
		// cout << '\n';
	}
	int l = 0, r = n - 1;
	i64 ans = 0;
	while(l < r){
		int res = inf;
		for(int i = 0; i < a[l].size(); i ++)
			for(int j = 0; j < a[r].size(); j ++)
				if(a[l][i] == a[r][j])
					res = min(res, i + j);

		if(res == inf){
			cout << -1 << '\n';
			return;
		}
		ans += res;
		l ++, r --;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// int x = 2135107522;
	// map<int, bool> mp;
	// while(!mp[x]){
	// 	mp[x] = true;
	// 	x ^= (x / 2);
	// }
	// cout << mp.size() << '\n';
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}