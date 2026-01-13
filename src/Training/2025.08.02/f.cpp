#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> mp;
	for(auto &e : a)
		cin >> e, mp[e] ++;

	vector<pair<int, int>> v;
	for(auto [num, cnt] : mp)
		v.push_back({num, cnt});
	
	int m = v.size(), ans = v[0].second, cnt = 1;
	int last = 0, sum = ans;
	for(int i = 1; i < m; i ++){
		if(v[i].first == v[i - 1].first + 1){
			sum += v[i].second, cnt ++;
			if(cnt > k)
				sum -= mp[v[last ++].first];
		}else
			sum = v[i].second, cnt = 1, last = i;
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}