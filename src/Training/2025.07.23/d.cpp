#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		if(s[i] == '0')
			a[i] = a[i - 1] - 1;
		if(s[i] == '1')
			a[i] = a[i - 1] + 1;
	}
	map<int, i64> mp;
	i64 ans = 0;
	for(int i = 0; i <= n; i ++){
		ans = (ans + mp[a[i]] * (n - i + 1) % mod) % mod;
		mp[a[i]] += (i + 1);
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