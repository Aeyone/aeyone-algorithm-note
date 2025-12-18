#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> mp;
	for(auto &e : a){
		cin >> e;
		mp[e] ++;
	}
	int tmp = mp[k], ans = mp[k];
	for(int i = 0; i < k; i ++) if(mp[i] == 0){
		if(tmp > 0){
			tmp --;
		}else{
			ans ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}