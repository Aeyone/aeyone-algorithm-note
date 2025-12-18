#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n, q;
	cin >> n >> q;
	map<int, vector<int>> mp;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		mp[x].push_back(i);
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		if(x == y){
			cout << (i64)(mp[x].size() - 1) * mp[x].size() / 2;
			continue;
		}
		if(mp[x].size() == 0 || mp[y].size() == 0){
			cout << 0 << '\n';
			continue;
		}
		int l = 0, r = n;
		i64 ans = 0;
		// for(auto e : mp[x])
		// 	cout << e << ' ';
		// cout << '\n';
		for(int i = 0; i < mp[y].size() && l < mp[x].size(); i ++){
			i64 idx = lower_bound(mp[x].begin() + l, mp[x].end(), mp[y][i]) - mp[x].begin();
			ans += idx;
			l = idx;
		}
		// cout << ans << '\n';
	}
	// vector<array<int, 2>> v(q);
	// map<int, vector<int>> mp;
	// for(int i = 0; i < q; i ++){
	// 	int x, y;
	// 	cin >> x >> y;
	// 	v[i] = {x, y};
	// 	mp[y].push_back(x);
	// }
	// map<pair<int, int>, i64> cnt;
	// map<int, int> pre;
	// for(int i = 0; i < n; i ++){
	// 	for(auto x : mp[a[i]])
	// 		cnt[{x, a[i]}] += pre[x];
	// 	pre[a[i]] ++;
	// }

	// for(auto [x, y] : v)
	// 	cout << cnt[{x, y}] << '\n';
	// for( int i=0;i<q; i++)
	// 	cout << v[i][2] << '\n';
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while(_ --)
		solve();
}