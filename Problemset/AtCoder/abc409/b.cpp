#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<i64, i64> pii;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	map<i64, i64> mp;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] ++;

	vector<pii> v;
	for(auto [num, cnt] : mp)
		v.push_back({num, cnt});

	sort(v.begin(), v.end(), greater<pii>());

	i64 sum = 0, ans = n;
	for(auto [num, cnt] : v){
		sum += cnt;
		if(sum >= num){
			ans = max(num, sum - cnt);
			break;
		}
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