#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	map<i64, i64> cnt;
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	map<int, i64> mp;
	for(int i = 0; i < n; i ++){
		vector<int> p;
		for(int j = 1; j <= a[i] / j; j ++){
			if(a[i] % j == 0){
				p.push_back(j);
				if(a[i] / j != j)
					p.push_back(a[i] / j);
			}
		}
		for(auto e : p)
			mp[e] += a[i];
	}
	i64 ans = 0;
	for(auto [e, sum] : mp)
		ans = max(ans, e * sum);
	
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