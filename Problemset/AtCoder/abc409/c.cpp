#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> d(n - 1);
	map<int, i64> mp;
	i64 sum = 0;
	mp[0] ++;
	for(int i = 0; i < n - 1; i ++){
		cin >> d[i];
		sum += d[i];
		mp[sum % l] ++;
	}

	if(l % 3 != 0){
		cout << 0 << '\n';
		return;
	}

	i64 ans = 0;
	for(int i = 0; i < l / 3; i ++){
		int a = i, b = i + l / 3, c = i + 2 * l / 3;
		ans += mp[a] * mp[b] * mp[c];
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